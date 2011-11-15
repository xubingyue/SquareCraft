#include "PCH.h"

SAnimation::SAnimation(std::string files,float x,float y) : sf::Sprite() {
	current=-1;
	speed=1;
	max=0;

	std::vector<std::string> result=SGame::GetInstance().utils.Explode(files,",");
	for(std::vector<std::string>::iterator i=result.begin();i!=result.end();i++) {
		sf::Texture tmp;
		tmp.LoadFromFile(*i);
		frames.push_back(tmp);
		max++;
	}
}

void SAnimation::DrawIt() {
	if(current!=-1) {
		SetTexture(frames[(unsigned int)current]);
		SGame::GetInstance().Draw(*this);

		if(current==max-1) {
			SGame::GetInstance().EndOfAnimation();
			current=-1;
		}
		else current+=speed;
	}
}