#pragma once

class Field;

class Player {
public:
  enum Direction { LEFT, UP, RIGHT, DOWN, ENTER };
  void set(int num);
  bool tick(Field &);
  void keyEvent(Direction);
private:
  Direction direction_;
  Direction movement_;
  int playernum_;
  char x_, y_;
};
