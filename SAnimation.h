#ifndef SANIMATION_H
#define SANIMATION_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class SAnimation : public sf::Sprite {
public:
	SAnimation(std::string files,float x=0,float y=0);
	void DrawIt();
	float current;
	float speed;

private:
	std::vector<sf::Texture> frames;
	int max;
};

#endif