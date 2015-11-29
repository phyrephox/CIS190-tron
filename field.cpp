//#include "painter.hpp"
#include "field.hpp"

Field::Field(){
  for (int i = 0; i<WIDTH; i++){
    for (int j = 0; j<HEIGHT; j++){
      setBlock(EMPTY, i, j);
    }
  }
}

void Field::setBlock(Type t, int x, int y){
  map_[x][y] = t;
}

Field::Type Field::block(int x, int y) const{
  return map_[x][y];
}

/*
void Field::draw(Painter &p) {
  for (int i = 0; i<WIDTH; i++){
    for (int j = 0; j<HEIGHT; j++){
      p.draw(map_[i][j], i, j);
    }
  }
}
*/
