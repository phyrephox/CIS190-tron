#include "field.hpp"
#include "player.hpp"

void Player::set(int num){
  playernum_ = num;
  if (num == 1){
    movement_ = UP;
    direction_ = UP;
    x_ = 60;
    y_ = 60;
  } else {
    movement_ = DOWN;
    direction_ = DOWN;
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
  if (x_ >= f.WIDTH || y_ >= f.HEIGHT || x_ < 0 || y_ < 0) {
    return false;
  }
  f.setBlock(playernum_ == 1 ? f.Type::PLAYER1 : f.Type::PLAYER2, x_, y_);
  return true;
}

void Player::keyEvent(Direction d){
  if ((d == UP && direction_ == DOWN) || (d == LEFT && direction_ == RIGHT) ||
    (d == DOWN && direction_ == UP) || (d == RIGHT && direction_ == LEFT)) {
    return;
  }
  direction_ = d;
}

