#include "field.hpp"
#include "player.hpp"

Player::Player(int num):
  playernum_(num) {
  if (num == 1){
    movement_ = UP;
    x_ = 60;
    y_ = 60;
  } else {
    movement_ = DOWN;
    x_ = 20;
    y_ = 20;
  }
}

bool Player::tick(Field &f){
  movement_ = direction_;
  switch (movement_){
    case LEFT:
      x_ -= 1;
      break;
    case RIGHT:
      x_ += 1;
      break;
    case UP:
      y_ -= 1;
      break;
    case DOWN:
      y_ += 1;
      break;
  }
  if (f.block(x_, y_) != f.Type::EMPTY){
    return false;
  }
  f.setBlock(playernum_ == 1 ? f.Type::PLAYER1 : f.Type::PLAYER2, x_, y_);
  return true;
}

void Player::keyEvent(Direction d){
  direction_ = d;
}

