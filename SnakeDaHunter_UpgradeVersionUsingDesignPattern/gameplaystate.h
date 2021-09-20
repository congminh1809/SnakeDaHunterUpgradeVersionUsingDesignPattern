#pragma once

#include "gamestate.h"
#include "snake.h"
#include "world.h"

class GamePlayState : public GameState
{
public:
  GamePlayState(Game*);

  void handleInput() override;
  void update() override;
  void draw() override;

  int speed() const override;

private:
  int segmentSize_;
  Snake snake_;
  World world_;

  sf::Text statusBar_;
  sf::Font font_;

  void initializeStatusBar();
  void updateStatusBar();
};
