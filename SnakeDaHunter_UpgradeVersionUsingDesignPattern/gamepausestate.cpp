#include "gamepausestate.h"
#include "game.h"

GamePauseState::GamePauseState(Game* g)
  : GameState{ g }
  , textbox_{ game_->window(), "GAME PAUSED!", "Press [Space] to resume" }
{}

void GamePauseState::handleInput()
{
  sf::Event event;
  // while there are pending events
  while ( game_->window().pollEvent(event) ) {
    if ( event.type == sf::Event::Closed ) { game_->window().close(); }

    // handle change state events
    if ( event.type == sf::Event::KeyPressed ) {
      if ( event.key.code == sf::Keyboard::Space ) { game_->changeState(GameState::Type::PLAY); }
    }
  }
}

void GamePauseState::update()
{
  // Do nothing in this state
}

void GamePauseState::draw()
{
  // draw the current game play state
  auto play = game_->getState(GameState::Type::PLAY);
  if ( play ) play->draw();

  // draw the pause state screen over the game screen
  textbox_.draw();
}
