#ifndef SHERO_H
#define SHERO_H

class SHero : public SObject {
public:
	SHero(float x,float y);
	void DrawIt();

private:
	bool Collide(float x,float y);
	void AdjustXPosition();
	void AdjustYPosition();
	float Sign(float a);
	float jumpPower;
	float gravity;
	float xSpeed;
	float ySpeed;
	float power;
};

#endif