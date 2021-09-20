#include "game.h"
#include "gameoverstate.h"
#include "gamepausestate.h"
#include "gameplaystate.h"
#include "mainmenustate.h"

#include <stdexcept>

const int SEGMENT_SIZE{ 20 };
const int SEGMENTS_X{ 40 };
const int SEGMENTS_Y{ 30 };

const std::string WINDOW_TITLE{ "Yet Another Snake Game" };
const int MAX_FPS{ 60 };

Game::Game()
  : segmentSize_{ SEGMENT_SIZE }
  , gridSize_{ SEGMENTS_X, SEGMENTS_Y }
{
  window_.create(sf::VideoMode{ SEGMENTS_X * SEGMENT_SIZE, SEGMENTS_Y * SEGMENT_SIZE },
                 WINDOW_TITLE,
                 sf::Style::Titlebar | sf::Style::Close);

  // Try to reduce CPU load in each running loop by setting framerate limit.
  // After each sf::RenderWindow::display() call, the program will sleep a bit
  // to ensure the current frame last long enough to match the framerate limit.
  window_.setFramerateLimit(MAX_FPS);

  elapsedTime_ = 0;

  changeState(GameState::Type::MENU);
}

Game::~Game()
{
  // Delete all states in used
  for ( auto& s : states_ ) {
    delete s.second;
  }

  // and close the render window
  window_.close();
}

void Game::run()
{
  sf::Clock clock;
  while ( window_.isOpen() ) {
    if ( currentState_ == nullptr ) continue;

    currentState_->handleInput();

    float timeOfUpdate = 1.0 / currentState_->speed();
    if ( elapsedTime_ > timeOfUpdate ) {
      currentState_->update();
      elapsedTime_ -= timeOfUpdate;
    }

    window_.clear();
    currentState_->draw();
    window_.display();
    elapsedTime_ += clock.restart().asSeconds();
  }
}

/** Change to a state specified by a given type.
 *
 * If the state is not the map, insert a new one and change
 * the current state to the new one.
 */
void Game::changeState(const GameState::Type type)
{
  try {
    currentState_ = states_.at(type);
    return;
  } catch ( const std::out_of_range& ) {
    // If the given state is not in the list, insert a new one
    switch ( type ) {
      case GameState::Type::MENU:
        states_[type] = new MainMenuState(this);
        break;
      case GameState::Type::PLAY:
        states_[type] = new GamePlayState(this);
        break;
      case GameState::Type::PAUSE:
        states_[type] = new GamePauseState(this);
        break;
      case GameState::Type::OVER:
        states_[type] = new GameOverState(this);
        break;
    }
  }
  // and change current state to the new one
  currentState_ = states_[type];
}

/** Get a state already in state map by a given type.
 *
 * If the state cannot be found, return nullptr.
 */
GameState* Game::getState(const GameState::Type type)
{
  try {
    return states_.at(type);
  } catch ( const std::out_of_range& ) {}
  return nullptr;
}

/** Remove the specified state and insert a new one.
 */
void Game::resetState(const GameState::Type type)
{
  try {
    auto s = states_.at(type);
    delete s;
    states_.erase(type);
  } catch ( const std::out_of_range& ) {}
  changeState(type);
}

int Game::segmentSize() const
{
  return segmentSize_;
}

const sf::Vector2u& Game::gridSize() const
{
  return gridSize_;
}

sf::RenderWindow& Game::window()
{
  return window_;
}
