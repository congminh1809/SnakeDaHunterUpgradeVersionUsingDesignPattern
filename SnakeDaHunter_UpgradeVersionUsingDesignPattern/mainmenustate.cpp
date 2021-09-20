#include "mainmenustate.h"
#include "game.h"

#include <SFML/Graphics.hpp>

MainMenuState::MainMenuState(Game* g)
  : GameState{ g }
  , textbox_{ game_->window() }
{}

void MainMenuState::handleInput()
{
  sf::Event event;
  // while there are pending events
  while ( game_->window().pollEvent(event) ) {
    if ( event.type == sf::Event::Closed ) { game_->window().close(); }

    // handle change state events
    if ( event.type == sf::Event::KeyPressed ) {
      if ( event.key.code == sf::Keyboard::Enter ) {
        game_->resetState(GameState::Type::PLAY);
      } else if ( event.key.code == sf::Keyboard::Escape ) {
        game_->window().close();
      }
    }
  }
}

void MainMenuState::update()
{
  // Do nothing in this state
}

void MainMenuState::draw()
{
  textbox_.draw();
}
