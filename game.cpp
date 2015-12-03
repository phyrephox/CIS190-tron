#include "game.hpp"
#include "field.hpp"
#include "player.hpp"

#include <iostream>
#include <string>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

Game::Game() {
  player1_ = Player();
  player1_.set(1);
  player2_ = Player();
  player2_.set(2);
  field_ = Field();
  state_ = MENU;
  p1_score_ = 0;
  p2_score_ = 0;
  string_width_ = 0;
}

void Game::tick() {
// Update for GUI
  if (state_ == PLAYING) {
    bool p1_not_lost = player1_.tick(field_), p2_not_lost = player2_.tick(field_);
    if (!p1_not_lost && !p2_not_lost) {
      reset();
    } else if (!p1_not_lost) {
      reset();
      p2_score_++;
    } else if (!p2_not_lost) {
      reset();
      p1_score_++;
    }
  }
}

void Game::reset(){
  player1_ = Player();
  player1_.set(1);
  player2_ = Player();
  player2_.set(2);
  field_ = Field();
  state_ = MENU;
}

void setOrthographicProjection() {
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  gluOrtho2D(0, Field::WIDTH*Field::BLOCK_WIDTH, 0, Field::HEIGHT * Field::BLOCK_HEIGHT);
  //glTranslatef(0,-Field::HEIGHT*Field::BLOCK_HEIGHT,0);
  //glTranslatef(0,Field::HEIGHT*Field::BLOCK_HEIGHT,0);
  glMatrixMode(GL_MODELVIEW);
}

void setTextPosition(float x, float y) {
  glMatrixMode(GL_PROJECTION);
  glTranslatef(x,y,0);
  glMatrixMode(GL_MODELVIEW);
}

void setTextSize(float x, float y) {
  glMatrixMode(GL_PROJECTION);
  glScalef(x,y,0);
  glMatrixMode(GL_MODELVIEW);
}

void resetProjection() {
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
}

void Game::resetString() {
  setTextPosition(-string_width_, 0);
  string_width_ = 0;
}

void Game::renderString(const std::string str) {
  const char *c;
  for (int i = 0; i<str.length(); i++){
    glutStrokeCharacter(GLUT_STROKE_ROMAN, str[i]);
    string_width_ += glutStrokeWidth(GLUT_STROKE_ROMAN, str[i]);
  }
  resetString();
}

void Game::draw() {
  if (state_ == PLAYING){
    field_.draw();
  } else if (state_ == MENU) {
    glColor3d(1,1,1);
    setOrthographicProjection();
    glPushMatrix();
    glLoadIdentity();
    setTextPosition(50,100);
    setTextSize(.25,.5);
    renderString("PRESS ENTER TO START!");
    setTextPosition(100,900);
    glColor3d(1,1,0);
    renderString(std::to_string(p2_score_));
    setTextPosition(700,0);
    glColor3d(0,1,0);
    renderString(std::to_string(p1_score_));
    glPopMatrix();
    resetProjection();
    //draw menu
  }
}

void Game::keyEvent(Player::Direction d, int pnum) {
  if (state_ == MENU && pnum == 1) {
    // handle menu
    if (d == Player::ENTER) {
      state_ = PLAYING;
      std::cout << p1_score_ << " " << p2_score_ << std::endl; //print the score
    }
  } else if (state_ == PLAYING && pnum == 1) {
    player1_.keyEvent(d);
  } else if (state_ == PLAYING && pnum == 2) {
    player2_.keyEvent(d);
  }
}
