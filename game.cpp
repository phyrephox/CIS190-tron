#include "game.hpp"
#include "field.hpp"
#include "player.hpp"

Game::Game() {
	player1_ = Player();
	player1_.set(1);
	player2_ = Player();
	player2_.set(2);
	field_ = Field();
}

void Game::tick()
{
	// Update for GUI
	if (!player1_.tick(field_) || !player2_.tick(field_)) {
		player1_ = Player();
		player1_.set(1);
		player2_ = Player();
		player2_.set(2);
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
