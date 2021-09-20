#pragma once

#include <SFML/Graphics.hpp>

/** The text box displayed in pause or over state.
 */
class ScreenTextBox
{
public:
  ScreenTextBox(sf::RenderWindow&, const std::string&, const std::string&);

  void setTitle(const std::string&);
  void setMessage(const std::string&);
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
  void initializeTitle();
  void initializeMessage();
  void centerText(sf::Text&, const float);
};
