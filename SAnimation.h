#ifndef SANIMATION_H
#define SANIMATION_H

class SAnimation : public sf::Sprite {
public:
	SAnimation(std::string files);
	void DrawIt();
	float current;
	float speed;

private:
	std::vector<sf::Texture> frames;
	int max;
};

#endif