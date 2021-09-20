#include "gameoverstate.h"
#include "game.h"

GameOverState::GameOverState(Game* g)
  : GameState{ g }
  , textbox_{ game_->window(),
              "GAME OVER!",
              "Main Menu [Enter]\n"
              "Quit      [Esc]" }

{}

/** Press [Enter] to return to main menu or [Esc] to quit
 */
void GameOverState::handleInput()
{
  sf::Event event;
  // while there are pending events
  while ( game_->window().pollEvent(event) ) {
    if ( event.type == sf::Event::Closed ) { game_->window().close(); }

    // handle change state events
    if ( event.type == sf::Event::KeyPressed ) {
      if ( event.key.code == sf::Keyboard::Enter ) {
        game_->changeState(GameState::Type::MENU);
      } else if ( event.key.code == sf::Keyboard::Escape ) {
        game_->window().close();
      }
    }
  }
}

void GameOverState::update()
{
  // Do nothing in this state
}

void GameOverState::draw()
{
  // draw the current game play state
  auto play = game_->getState(GameState::Type::PLAY);
  if ( play ) play->draw();

  // draw the state screen over the game play screen
  textbox_.draw();
}
