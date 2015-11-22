#include "game.hpp"
#include "painter.hpp"
#include "field.hpp"

void Game::tick()
{
	// TODO
}

void Game::draw(Painter &p) const
{
	field_.draw(p);
}

void Game::keyEvent(Player::Direction d, Player::Playernum)
{
	// TODO
}