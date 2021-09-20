#pragma once

#include "gamestate.h"
#include "mainmenutextbox.h"

class MainMenuState : public GameState
{
public:
  MainMenuState(Game* g);

  void handleInput() override;
  void update() override;
  void draw() override;

private:
  MainMenuTextBox textbox_;
};
