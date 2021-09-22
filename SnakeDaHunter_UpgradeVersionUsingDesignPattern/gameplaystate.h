#pragma once

#include "gamestate.h"
#include "snake.h"
#include <SFML/Graphics.hpp>
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

  //sf::RenderWindow& window_;

  sf::Text statusBar_;
  sf::Font font_;
  sf::Text title_;

  void initializeStatusBar();
  void updateStatusBar();
  void centerText(sf::Text&, const float);
};
