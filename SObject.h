#ifndef SOBJECT_H
#define SOBJECT_H

class SObject : public sf::Sprite {
public:
	SObject(sf::Texture *tex,float x=0,float y=0);
	SObject(std::string path,float x=0,float y=0);
	virtual ~SObject();
	void DrawIt();

private:
	sf::Texture *wsk;
};

#endif