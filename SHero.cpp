#include "PCH.h"

SHero::SHero(float x,float y) : SObject("hero.png",x,y) {
	jumpPower=6.0F;
	gravity=0.3F;
	xSpeed=0.0F;
	ySpeed=0.0F;
	power=3.0F;
}

void SHero::DrawIt() {
	if(GetPosition().y>480) SetPosition(GetPosition().x,-24);
	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::LShift)) power=1.0F;
	else power=3.0F;

	if(sf::Keyboard::IsKeyPressed(sf::Keyboard::A)) {
		FlipX(true);
		xSpeed=-power;
	}
	else if(sf::Keyboard::IsKeyPressed(sf::Keyboard::D)) {
		FlipX(false);
		xSpeed=power;
	}
	else xSpeed=0;

	if(Collide(GetPosition().x,GetPosition().y+1)) {
		ySpeed=0;
		if(sf::Keyboard::IsKeyPressed(sf::Keyboard::W)) ySpeed-=jumpPower;
	}
	else ySpeed+=gravity;

	AdjustXPosition();
	AdjustYPosition();
	SGame::GetInstance().Draw(*this);
}

bool SHero::Collide(float x,float y) {
	for(std::list<SBlock *>::iterator i=SGame::GetInstance().manager.blocks.begin();i!=SGame::GetInstance().manager.blocks.end();i++) {
		if(x+24>(*i)->GetPosition().x&&x<(*i)->GetPosition().x+24
		 &&y+24>(*i)->GetPosition().y&&y<(*i)->GetPosition().y+24) return true;
	}
	return false;
}

void SHero::AdjustXPosition() {
	for(int i=0;i<abs(xSpeed);i++) {
		if(!Collide(GetPosition().x+Sign(xSpeed),GetPosition().y)) Move(Sign(xSpeed),0);
		else {
			xSpeed=0;
			break;
		}
	}
}

void SHero::AdjustYPosition() {
	for(int i=0;i<abs(ySpeed);i++) {
		if(!Collide(GetPosition().x,GetPosition().y+Sign(ySpeed))) Move(0,Sign(ySpeed));
		else {
			ySpeed=0;
			break;
		}
	}
}

float SHero::Sign(float a) {
	if(a>0) return 1;
	if(a<0) return -1;
	return 0;
}