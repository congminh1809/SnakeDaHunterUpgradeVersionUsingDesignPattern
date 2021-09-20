#pragma once

#include "gamestate.h"

#include <SFML/Graphics.hpp>

#include <map>

/** The game which has multiple states and each state changes
 * by user input.
 */
class Game
{
public:
  Game();
  ~Game();

  void run();

  void changeState(const GameState::Type);
  GameState* getState(const GameState::Type);
  void resetState(const GameState::Type);

  int segmentSize() const;
  const sf::Vector2u& gridSize() const;
  sf::RenderWindow& window();

private:
  int segmentSize_;
  sf::Vector2u gridSize_;

  std::map<GameState::Type, GameState*> states_;
  GameState* currentState_;

  sf::RenderWindow window_;
  float elapsedTime_;  // time passed since the game starts
};
