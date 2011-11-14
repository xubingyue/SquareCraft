#include "SManager.h"
#include "SGame.h"

SManager::SManager() {
	stone=new sf::Texture(); stone->LoadFromFile("stone.png");
	dirt=new sf::Texture(); dirt->LoadFromFile("dirt.png");
	grass=new sf::Texture(); grass->LoadFromFile("grass.png");
	coal=new sf::Texture(); coal->LoadFromFile("coal.png");
	copper=new sf::Texture(); copper->LoadFromFile("copper.png");
	iron=new sf::Texture(); iron->LoadFromFile("iron.png");
	gold=new sf::Texture(); gold->LoadFromFile("gold.png");
		
	for(int x=0;x<168;x++) 
		for(int y=0;y<20;y++) 
			PlaceBlocks((float)(x*24),(float)(456-y*24));
}

void SManager::PlaceBlock(sf::Texture *tex,float x,float y) {
	if(GetBlock(x,y)==NULL) blocks.push_back(new SBlock(tex,x,y));
}

void SManager::PlaceBlocks(float x,float y) {
	if(y>368) {
		int liczba=SGame::GetInstance().utils.Random(250);
		if(liczba>=0&&liczba<=5) PlaceBlock(coal,x,y);
		else if(liczba>=6&&liczba<=10) PlaceBlock(copper,x,y);
		else if(liczba>=10&&liczba<=13) PlaceBlock(iron,x,y);
		else if(liczba>=14&&liczba<=16) PlaceBlock(gold,x,y);
		else PlaceBlock(stone,x,y);
	}
	if(y>296&&y<368) PlaceBlock(dirt,x,y);
	if(y>272&&y<296) PlaceBlock(grass,x,y);
}

void SManager::RemoveBlock(float x,float y) {
	for(std::list<SBlock *>::iterator i=blocks.begin();i!=blocks.end();) {
		if((*i)->GetPosition().x==x&&(*i)->GetPosition().y==y) i=blocks.erase(i);
		else i++;
	}
}

SBlock *SManager::GetBlock(float x,float y) {
	for(std::list<SBlock *>::iterator i=blocks.begin();i!=blocks.end();i++) {
		if((*i)->GetPosition().x==x&&(*i)->GetPosition().y==y) return *i;
	}
	return NULL;
}