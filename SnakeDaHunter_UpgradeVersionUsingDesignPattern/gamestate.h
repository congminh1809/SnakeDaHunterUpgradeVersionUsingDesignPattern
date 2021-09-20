#pragma once

class Game;

/** Abstract game state class.
 */
class GameState
{
public:
  enum class Type
  {
    MENU,
    PLAY,
    PAUSE,
    OVER
  };

  GameState(Game* g)
    : game_{ g }
  {}
  virtual ~GameState() = default;

  virtual void handleInput() = 0;
  virtual void update() = 0;
  virtual void draw() = 0;

  virtual int speed() const { return 30; }

protected:
  Game* game_;
};
