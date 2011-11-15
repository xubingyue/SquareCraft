#include "PCH.h"

SObject::SObject(sf::Texture *tex,float x,float y) : sf::Sprite() {
	wsk=tex;
	SetTexture(*wsk);
	SetPosition(x,y);
}

SObject::SObject(std::string path,float x,float y) : sf::Sprite() {
	wsk=new sf::Texture();
	wsk->LoadFromFile(path);
	SetTexture(*wsk);
	SetPosition(x,y);
}

SObject::~SObject() {
	delete wsk;
}

void SObject::DrawIt() {
	SGame::GetInstance().Draw(*this);
}