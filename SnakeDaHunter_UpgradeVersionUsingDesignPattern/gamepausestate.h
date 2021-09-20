#pragma once

#include "gamestate.h"
#include "screentextbox.h"

class GamePauseState : public GameState
{
public:
  GamePauseState(Game* g);

  void handleInput() override;
  void update() override;
  void draw() override;

private:
  ScreenTextBox textbox_;
};
