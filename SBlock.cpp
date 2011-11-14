#include "SBlock.h"
#include "SGame.h"

SBlock::SBlock(sf::Texture *tex,float x,float y) : SObject(tex,x,y) {
	light=2;
}

void SBlock::DrawIt() {
	SetColor(sf::Color((sf::Uint8)(25.5*light),(sf::Uint8)(25.5*light),(sf::Uint8)(25.5*light)));
	SGame::GetInstance().Draw(*this);
}