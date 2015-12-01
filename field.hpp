#pragma once

class Painter;

class Field {
public:
  enum { WIDTH = 80, HEIGHT = 80 };
  enum { BLOCK_WIDTH = 3, BLOCK_HEIGHT = 3 };
  enum Type { EMPTY = 0, PLAYER1 = 1, PLAYER2 = 2 };
  Field();
  void setBlock(Type, int x, int y);
  Type block (int x, int y) const;
  void draw() const;
private:
  Type map_[HEIGHT][WIDTH];
};
