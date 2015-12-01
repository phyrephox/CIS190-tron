#include "game.hpp"
#include "painter.hpp"
#include "field.hpp"

void Game::tick()
{
	// Update for GUI
	if (!player1_tick(_field)) {
		player1_ = Player(1);
		player2_ = Player(2);
		field_ = Field();
	}
}

void Game::draw() const
{
	field_.draw();
}

void Game::keyEvent(Player::Direction d, int pnum)
{
	// TODO
	if (pnum == 1) {
		player1_.keyEvent(d);
	} else {
		player2_.keyEvent(d);
	}
}