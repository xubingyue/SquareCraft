#ifndef SGAME_H
#define SGAME_H

#include <SFML/Graphics.hpp>
#include "SHero.h"
#include "SUtils.h"
#include "SManager.h"

class SGame : public sf::RenderWindow {
public:
	static SGame &GetInstance();
	void EndOfAnimation();
	SManager manager;
	SUtils utils;

private:
	SGame();
	SBlock *destroy;
};

#endif