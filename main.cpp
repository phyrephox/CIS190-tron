#include "game.hpp"

#ifdef __APPLE__
  #include <GLUT/glut.h>  
#else
  #include <GL/gl.h>
  #include <GL/glu.h>
  #include <GL/glut.h>
#endif

#include <iostream>

Game game;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  game.draw();
  glutSwapBuffers();
}

void timer(int = 0) {
  game.tick();
  display();
  glutTimerFunc(30, timer, 0);
}

void keyEventS(int key, int, int) {
  switch (key) {
  case GLUT_KEY_LEFT:
    game.keyEvent(Player::LEFT, 1);
    break;
  case GLUT_KEY_RIGHT:
    game.keyEvent(Player::RIGHT, 1);
    break;
  case GLUT_KEY_UP:
    game.keyEvent(Player::UP, 1);
    break;
  case GLUT_KEY_DOWN:
    game.keyEvent(Player::DOWN, 1);
    break;
  }
}

void keyEventN(unsigned char key, int, int) {
  switch (key) {
  case 'a':
    game.keyEvent(Player::LEFT, 2);
    break;
  case 'd':
    game.keyEvent(Player::RIGHT, 2);
    break;
  case 'w':
    game.keyEvent(Player::UP, 2);
    break;
  case 's':
    game.keyEvent(Player::DOWN, 2);
    break;
  case 13:
    game.keyEvent(Player::ENTER, 1); // for menu system
  }
}

int main (int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(Field::WIDTH * Field::BLOCK_WIDTH,
                     Field::HEIGHT * Field::BLOCK_HEIGHT);
  glutInitWindowPosition(100,100);
  glutCreateWindow("TRON");
  glClearColor(0,0,0,1);
  glLineWidth(3);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, Field::WIDTH * Field::BLOCK_WIDTH,
          Field::HEIGHT * Field::BLOCK_HEIGHT, 0, -1, 1);
  glutDisplayFunc(display);
  glutSpecialFunc(keyEventS);
  glutKeyboardFunc(keyEventN);
  timer();

  glutMainLoop();
}
