#pragma once
#include "player.hpp"
#include "field.hpp"

class Painter;

class Game {
public:
  Game ();
  void tick();
  void draw() const;
  void keyEvent(Player::Direction, int);// to be changed
  void reset();
private:
  Field field_;
  Player player1_;
  Player player2_;
  enum { PLAYING, MENU } state_;
  int p1_score_;
  int p2_score_;
};
