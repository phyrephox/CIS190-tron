#pragma once
#include "player.hpp"
#include "field.hpp"

#include <string>

class Painter;

class Game {
public:
  Game ();
  void tick();
  void draw();
  void keyEvent(Player::Direction, int);// to be changed
  void reset();
private:
  void renderString(float x, float y, const std::string);
  void resetString();
  Field field_;
  Player player1_;
  Player player2_;
  enum { PLAYING, MENU } state_;
  int p1_score_;
  int p2_score_;
  int string_width_;
};
