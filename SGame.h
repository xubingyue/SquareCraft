#ifndef SGAME_H
#define SGAME_H

class SGame : public sf::RenderWindow {
public:
	virtual ~SGame();
	static SGame &GetInstance();
	void EndOfAnimation();
	void StartGame();
	float camera_x;
	float camera_y;
	sf::Texture *moont;
	sf::Texture *sunt;
	sf::Sprite moon;
	SManager manager;
	SInventory inv;
	SUtils utils;
	SHero hero;

private:
	SGame();
	SBlock *destroy;
	SAnimation *pek;
	sf::Texture ghast;
	sf::Sprite ghost;
};

#endif