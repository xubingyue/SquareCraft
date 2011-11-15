#include "PCH.h"

SInventory::SInventory() : sf::Sprite() {
	gui1=new sf::Texture(); gui1->LoadFromFile("gui1.png");
	gui2=new sf::Texture(); gui2->LoadFromFile("gui2.png");
	SetColor(sf::Color(255,255,255,100));
	SetPosition(185,5);
	SetTexture(*gui1);

	font.LoadFromFile("ariblk.ttf");
	frende.SetCharacterSize(10);
	frende.SetFont(font);

	frama.LoadFromFile("frame.png");
	frame.SetPosition(185,5);
	frame.SetTexture(frama);
}

SInventory::~SInventory() {
	delete gui1;
	delete gui2;
}

void SInventory::AddItem(sf::Texture *type) {
	for(int y=0;y<4;y++) {
		for(int x=0;x<9;x++) {
			if(eq[x][y].type==type) {
				eq[x][y].size++;
				return;
			}
		}
	}
	for(int y=0;y<4;y++) {
		for(int x=0;x<9;x++) {
			if(eq[x][y].type==NULL) {
				eq[x][y].type=type;
				eq[x][y].size=1;
				return;
			}
		}
	}
}

void SInventory::Expand() {
	if(GetTexture()==gui1) SetTexture(*gui2);
	else SetTexture(*gui1);
}

void SInventory::DrawIt() {
	SGame::GetInstance().Draw(*this);
	for(int x=0;x<9;x++) {
		if(eq[x][0].type!=NULL) {
			render.SetTexture(*eq[x][0].type);
			render.SetPosition((float)(196+x*32),16);
			SGame::GetInstance().Draw(render);
			DrawText(eq[x][0].size,(float)(198+x*32),28);
		}
	}
	if(GetTexture()==gui2) {
		for(int y=1;y<4;y++) {
			for(int x=0;x<9;x++) {
				if(eq[x][y].type!=NULL) {
					render.SetTexture(*eq[x][y].type);
					render.SetPosition((float)(196+x*32),(float)(20+y*32));
					SGame::GetInstance().Draw(render);	
					DrawText(eq[x][y].size,(float)(198+x*32),(float)(32+y*32));
				}
			}
		}		
	}
	SGame::GetInstance().Draw(frame);
}

void SInventory::DrawText(int a,float x,float y) {
	frende.SetString(SGame::GetInstance().utils.IntToString(a));
	frende.SetPosition(x,y);

	SGame::GetInstance().Draw(sf::Shape::Rectangle(frende.GetRect().Left-1,frende.GetRect().Top+2,frende.GetRect().Width+1,frende.GetRect().Height-2,sf::Color::Black,1,sf::Color(50,50,50)));
	SGame::GetInstance().Draw(frende);
}