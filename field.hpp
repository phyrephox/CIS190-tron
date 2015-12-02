#pragma once


class Field {
public:
  enum { WIDTH = 120, HEIGHT = 120 };
  enum { BLOCK_WIDTH = 5, BLOCK_HEIGHT = 5 };
  enum Type { EMPTY = 0, PLAYER1 = 1, PLAYER2 = 2 };
  Field();
  void setBlock(Type, int x, int y);
  Type block (int x, int y) const;
  void draw() const;
private:
  Type map_[HEIGHT][WIDTH];
};
