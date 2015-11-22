#pragma once


class Field;

class Player {
public:
  enum Direction { LEFT, UP, RIGHT, DOWN };
  Player(int num);
  bool tick(Filed &);
  void keyEvent(Direction);
private:
  Direction direction_;
  Direction movement_;
}
