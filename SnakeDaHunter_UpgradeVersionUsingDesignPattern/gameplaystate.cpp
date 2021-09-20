#include "gameplaystate.h"
#include "game.h"

#include <iomanip>
#include <sstream>

const int SNAKE_LIVES{ 3 };
const int SNAKE_SPEED{ 4 };

/** Constructor: create world, snake and a render window.
 */
GamePlayState::GamePlayState(Game* g)
  : GameState{ g }
  , segmentSize_{ game_->segmentSize() }
  , snake_(segmentSize_, SNAKE_LIVES, SNAKE_SPEED)
  , world_(segmentSize_, game_->gridSize(), snake_)
{
  initializeStatusBar();
  updateStatusBar();
}

/** Check and handle real-time input events
 */
void GamePlayState::handleInput()
{
  sf::Event event;
  // while there are pending events
  while ( game_->window().pollEvent(event) ) {
    if ( event.type == sf::Event::Closed ) { game_->window().close(); }

    // handle change state events
    if ( event.type == sf::Event::KeyPressed ) {
      if ( event.key.code == sf::Keyboard::Space ) {
        game_->changeState(GameState::Type::PAUSE);
      } else if ( event.key.code == sf::Keyboard::Escape ) {
        game_->changeState(GameState::Type::MENU);
      }
    }
  }

  // Check if key Up, Right, Down, or Left is pressed
  // If yes then set the direction of the snake by using Snake::direction(Direction)
  // Remember to check if we can set the new direction. For example, if the current direction is
  // Left then we cannot set the new direction to Right because the head will go back to the body.
  if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake_.direction() != Direction::Down ) {
    snake_.direction(Direction::Up);
  } else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
              snake_.direction() != Direction::Left ) {
    snake_.direction(Direction::Right);
  } else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
              snake_.direction() != Direction::Up ) {
    snake_.direction(Direction::Down);
  } else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
              snake_.direction() != Direction::Right ) {
    snake_.direction(Direction::Left);
  }
}

/** Update the states of game after checking events and input
 */
void GamePlayState::update()
{
  snake_.update();
  world_.update();

  updateStatusBar();

  if ( snake_.isDead() ) { game_->changeState(GameState::Type::OVER); }
}

void GamePlayState::draw()
{
  snake_.draw(game_->window());
  world_.draw(game_->window());

  game_->window().draw(statusBar_);
}

int GamePlayState::speed() const
{
  return snake_.speed();
}

void GamePlayState::initializeStatusBar()
{
  font_.loadFromFile("C:\\Windows\\Fonts\\consola.ttf");
  statusBar_.setFont(font_);
  statusBar_.setCharacterSize(segmentSize_ - 4);
  statusBar_.setFillColor(sf::Color::White);
  statusBar_.setPosition(segmentSize_ + 2, (game_->gridSize().y - 1) * game_->segmentSize() - 1);
}

void GamePlayState::updateStatusBar()
{
  std::ostringstream oss;
  oss << "Lives: " << snake_.lives() << "  Body: " << std::setw(3) << snake_.body().size()
      << "  Speed: " << std::setw(2) << snake_.speed() << "  Apples: " << std::setw(3)
      << world_.numberOfApplesCreated() - 1 << "           Pause [SPACE]  Main Menu [ESC]";
  statusBar_.setString(oss.str().c_str());
}
