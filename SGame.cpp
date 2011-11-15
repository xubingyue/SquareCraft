#include "PCH.h"

SGame::SGame() : sf::RenderWindow(sf::VideoMode(672,480),"SquareCraft",sf::Style::Close) {
	SAnimation pek("p0.png,p1.png,p2.png,p3.png,p4.png,p5.png,p6.png,p7.png,p8.png,p9.png");
	SObject moon("moon.png",0,50);
	SObject ghost("ghost.png");
	SHero hero(48,240);

	SetFramerateLimit(60);
	while(IsOpened()) {
		sf::Event event;
		while(PollEvent(event)) {
			if(event.Type==sf::Event::Closed) Close();
			if(event.Type==sf::Event::KeyPressed) {
				if(event.Key.Code==sf::Keyboard::Escape) Close();
				if(event.Key.Code==sf::Keyboard::Num1) inv.frame.SetPosition(185,inv.frame.GetPosition().y);
				if(event.Key.Code==sf::Keyboard::Num2) inv.frame.SetPosition(217,inv.frame.GetPosition().y);
				if(event.Key.Code==sf::Keyboard::Num3) inv.frame.SetPosition(249,inv.frame.GetPosition().y);
				if(event.Key.Code==sf::Keyboard::Num4) inv.frame.SetPosition(281,inv.frame.GetPosition().y);
				if(event.Key.Code==sf::Keyboard::Num5) inv.frame.SetPosition(313,inv.frame.GetPosition().y);
				if(event.Key.Code==sf::Keyboard::Num6) inv.frame.SetPosition(345,inv.frame.GetPosition().y);
				if(event.Key.Code==sf::Keyboard::Num7) inv.frame.SetPosition(377,inv.frame.GetPosition().y);
				if(event.Key.Code==sf::Keyboard::Num8) inv.frame.SetPosition(409,inv.frame.GetPosition().y);
				if(event.Key.Code==sf::Keyboard::Num9) inv.frame.SetPosition(441,inv.frame.GetPosition().y);
				if(event.Key.Code==sf::Keyboard::E) inv.Expand();
			}
			if(event.Type==sf::Event::MouseWheelMoved) {
				if(event.MouseWheel.Delta<0) {
					if(inv.frame.GetPosition().x<441) inv.frame.Move(32,0);
					else inv.frame.SetPosition(185,inv.frame.GetPosition().y);
				}
				else {
					if(inv.frame.GetPosition().x>185) inv.frame.Move(-32,0);
					else inv.frame.SetPosition(441,inv.frame.GetPosition().y);
				}
			}
		}
		Clear(sf::Color(0,0,15));
		if(moon.GetPosition().x>672) moon.SetPosition(-128,moon.GetPosition().y);
		else moon.Move(1,0);
		moon.DrawIt();
		for(std::list<SBlock *>::iterator i=manager.blocks.begin();i!=manager.blocks.end();i++) {
			float dist=utils.Distance(hero.GetPosition().x+12,hero.GetPosition().y+12,(*i)->GetPosition().x+12,(*i)->GetPosition().y+12);
            if(dist<32) (*i)->light=10;
            else if(dist<64) (*i)->light=9;
            else if(dist<96) (*i)->light=8;
            else if(dist<128) (*i)->light=7;
            else if(dist<160) (*i)->light=6;
            else if(dist<192) (*i)->light=5;
            else if(dist<224) (*i)->light=4;
            else if(dist<256) (*i)->light=3;
            else (*i)->light=2;
			(*i)->DrawIt();
		}
		hero.DrawIt();
		float gridx=(float)(sf::Mouse::GetPosition(*this).x/24*24);
		float gridy=(float)(sf::Mouse::GetPosition(*this).y/24*24);
		SBlock *z=manager.GetBlock(gridx,gridy);
		if(utils.Distance(hero.GetPosition().x,hero.GetPosition().y,gridx,gridy)<96) {
			if(z!=NULL) {
				if(manager.GetBlock(gridx+24,gridy)==NULL
				 ||manager.GetBlock(gridx-24,gridy)==NULL
				 ||manager.GetBlock(gridx,gridy+24)==NULL
				 ||manager.GetBlock(gridx,gridy-24)==NULL) {
					if(sf::Mouse::IsButtonPressed(sf::Mouse::Left)) {
						if(pek.current==-1) {
							destroy=z;
							if(z->GetTexture()==manager.grass||z->GetTexture()==manager.dirt) pek.speed=0.5F;
							if(z->GetTexture()==manager.stone||z->GetTexture()==manager.coal||z->GetTexture()==manager.copper||z->GetTexture()==manager.iron||z->GetTexture()==manager.gold) pek.speed=0.125F;
							pek.SetPosition(gridx,gridy);
							pek.current=0;
						}
						pek.DrawIt();
					} else pek.current=-1;
					ghost.SetPosition(gridx,gridy);
					ghost.DrawIt();
				}
			}
			else {
				if((hero.GetPosition().x+23<gridx||hero.GetPosition().x>gridx+23
                 ||hero.GetPosition().y+23<gridy||hero.GetPosition().y>gridy+23)
				&&(manager.GetBlock(gridx+24,gridy)!=NULL
				 ||manager.GetBlock(gridx-24,gridy)!=NULL
				 ||manager.GetBlock(gridx,gridy+24)!=NULL
				 ||manager.GetBlock(gridx,gridy-24)!=NULL)) {
					 SStack *s=inv.eq[0,(unsigned int)((inv.frame.GetPosition().x-inv.GetPosition().x)/32)];
					 if(sf::Mouse::IsButtonPressed(sf::Mouse::Right)&&s->type!=NULL) {
						 manager.PlaceBlock(s->type,gridx,gridy);
						 if(s->size>1) s->size--;
						 else s->type=NULL;
					 }
					ghost.SetPosition(gridx,gridy);
					ghost.DrawIt();
				}
			}
		}
		inv.DrawIt();
		Display();
	}
}

void SGame::EndOfAnimation() {
	inv.AddItem((sf::Texture *)destroy->GetTexture());
	manager.blocks.remove(destroy);
}

SGame &SGame::GetInstance() {
	static SGame instance;
	return instance;
}