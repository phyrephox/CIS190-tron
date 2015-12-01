#include "field.hpp"
#ifdef __APPLE__
  #include <OpenGL/gl.h>
#else
  #include <GL/gl.h>
#endif

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


void Field::draw() const {
  for (int i = 0; i<WIDTH; i++){
    for (int j = 0; j<HEIGHT; j++){
      glColor3f(1, 1, 0);
      switch (map_[i][j]) {
        case EMPTY :
          break;
        case PLAYER1 :
          glColor3f(0, 1, 0);
        case PLAYER2:
          glBegin(GL_QUADS);
          glVertex2f(i*BLOCK_WIDTH, j*BLOCK_HEIGHT);
          glVertex2f((i+1)*BLOCK_WIDTH, j*BLOCK_HEIGHT);
          glVertex2f(i*BLOCK_WIDTH, (j+1)*BLOCK_HEIGHT);
          glVertex2f((i+1)*BLOCK_WIDTH, (j+1)*BLOCK_HEIGHT);
          glEnd();
          break;
      }
    }
  }
}

