#include "PCH.h"

SBlock::SBlock(sf::Texture *tex,float x,float y) : sf::Sprite(*tex) {
	SetPosition(x,y);
	light=2;
}

void SBlock::DrawIt() {
	SetColor(sf::Color((sf::Uint8)(25.5*light),(sf::Uint8)(25.5*light),(sf::Uint8)(25.5*light)));
	float oldx=GetPosition().x;
	float oldy=GetPosition().y;
	Move(SGame::GetInstance().camera_x,SGame::GetInstance().camera_y);
	SGame::GetInstance().Draw(*this);
	SetPosition(oldx,oldy);
}