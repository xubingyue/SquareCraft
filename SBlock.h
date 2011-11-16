#ifndef SBLOCK_H
#define SBLOCK_H

class SBlock : public sf::Sprite {
public:
	SBlock(sf::Texture *tex,float x,float y);
	void DrawIt();
	float light;
};

#endif