#include "game.hpp"
#include "field.hpp"
#include "player.hpp"

#include <iostream>

Game::Game() {
  player1_ = Player();
  player1_.set(1);
  player2_ = Player();
  player2_.set(2);
  field_ = Field();
  state_ = MENU;
  p1_score_ = 0;
  p2_score_ = 0;
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

void Game::draw() const {
  if (state_ == PLAYING){
    field_.draw();
  } else if (state_ == MENU) {
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
