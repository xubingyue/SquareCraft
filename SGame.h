#ifndef SGAME_H
#define SGAME_H

class SGame : public sf::RenderWindow {
public:
	static SGame &GetInstance();
	void EndOfAnimation();
	SManager manager;
	SInventory inv;
	SUtils utils;

private:
	SGame();
	SBlock *destroy;
};

#endif