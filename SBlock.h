#ifndef SBLOCK_H
#define SBLOCK_H

#include "SObject.h"

class SBlock : public SObject {
public:
	SBlock(sf::Texture *tex,float x,float y);
	void DrawIt();
	float light;
};

#endif