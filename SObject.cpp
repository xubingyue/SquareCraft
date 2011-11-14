#include "SObject.h"
#include "SGame.h"

SObject::SObject(sf::Texture *tex,float x,float y) : sf::Sprite() {
	wsk=tex;
	SetTexture(*wsk);
	SetPosition(x,y);
	hasTexture=false;
}

SObject::SObject(std::string path,float x,float y) : sf::Sprite() {
	wsk=new sf::Texture();
	wsk->LoadFromFile(path);
	SetTexture(*wsk);
	SetPosition(x,y);
	hasTexture=true;
}

SObject::~SObject() {
	if(hasTexture) delete wsk;
}

void SObject::DrawIt() {
	SGame::GetInstance().Draw(*this);
}