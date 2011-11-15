#ifndef SINVENTORY_H
#define SINVENTORY_H

class SInventory : public sf::Sprite {
public:
	SInventory();
	virtual ~SInventory();
	void AddItem(sf::Texture *type);
	void Expand();
	void DrawIt();
	SStack eq[9][4];
	sf::Sprite frame;

private:
	void DrawText(int a,float x,float y);
	sf::Font font;
	sf::Text frende;
	sf::Sprite render;
	sf::Texture *gui1;
	sf::Texture *gui2;
	sf::Texture frama;
};

#endif