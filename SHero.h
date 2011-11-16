#ifndef SHERO_H
#define SHERO_H

class SHero : public sf::Sprite {
public:
	SHero();
	void DrawIt();

private:
	bool Collide(float x,float y);
	void AdjustXPosition();
	void AdjustYPosition();
	float Sign(float a);
	sf::Texture tex;
	float jumpPower;
	float gravity;
	float xSpeed;
	float ySpeed;
	float power;
};

#endif