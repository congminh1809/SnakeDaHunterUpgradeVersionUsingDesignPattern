#pragma once

#include "gamestate.h"
#include "screentextbox.h"

class GameOverState : public GameState
{
public:
  GameOverState(Game* g);

  void handleInput() override;
  void update() override;
  void draw() override;

private:
  ScreenTextBox textbox_;
};
