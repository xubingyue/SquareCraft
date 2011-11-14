#ifndef SMANAGER_H
#define SMANAGER_H

#include <list>
#include "SBlock.h"

class SManager {
public:
	SManager();
	void PlaceBlock(sf::Texture *tex,float x,float y);
	void PlaceBlocks(float x,float y);
	void RemoveBlock(float x,float y);
	SBlock *GetBlock(float x,float y);
	std::list<SBlock *> blocks;
	sf::Texture *stone;
	sf::Texture *dirt;
	sf::Texture *grass;
	sf::Texture *coal;
	sf::Texture *copper;
	sf::Texture *iron;
	sf::Texture *gold;
};

#endif