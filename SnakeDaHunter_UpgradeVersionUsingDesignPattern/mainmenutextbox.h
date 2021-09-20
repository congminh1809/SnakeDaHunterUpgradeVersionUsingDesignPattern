#pragma once

#include <SFML/Graphics.hpp>

/** The text box displayed in main menu state.
 */
class MainMenuTextBox
{
public:
  MainMenuTextBox(sf::RenderWindow& window);

  void draw();

private:
  sf::RenderWindow& window_;
  sf::RectangleShape backdrop_;

  sf::Font titleFont_;
  sf::Text titleText_;
  std::string title_;

  sf::Font messageFont_;
  sf::Text messageText_;
  std::string message_;

  void initializeBackdrop();
  void intializeTitle();
  void intializeMessage();
  void centerText(sf::Text&, const float);
};
