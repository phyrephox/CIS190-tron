#pragma once
#include "player.hpp"
#include "field.hpp"

class Painter;

class Game
{
public:
	void tick();
	void draw(Painter &) const;
	void keyEvent(Player::Direction);// to be changed
private:
	Field field_;
	Player player1_;
	Player player2_;
};
