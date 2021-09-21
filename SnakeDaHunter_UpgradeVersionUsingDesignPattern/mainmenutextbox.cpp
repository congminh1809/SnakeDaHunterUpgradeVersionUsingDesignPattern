#include "mainmenutextbox.h"

MainMenuTextBox::MainMenuTextBox(sf::RenderWindow& window)
  : window_{ window }
{
  initializeBackdrop();

  title_ = { "SNAKE DA HUNTER BY MINH PC" };
  intializeTitle();
  centerText(titleText_, 320);

  message_ = { "New Game [Enter]\n"
               "Help     [F1]\n"
               "Quit     [Esc]" };
  intializeMessage();
  centerText(messageText_, 460);
}

void MainMenuTextBox::initializeBackdrop()
{
  backdrop_.setFillColor(sf::Color{ 0, 255, 174, 64 });
  backdrop_.setOutlineColor(sf::Color{ 255, 157, 0, 255});
  backdrop_.setOutlineThickness(5.0f);
  //backdrop_.setSize(sf::Vector2f{ window_.getSize().x-40,window_.getSize().y-40 });
  backdrop_.setSize(sf::Vector2f{ 40, 40 });
  backdrop_.setPosition(300, 300);
}

void MainMenuTextBox::intializeTitle()
{
  titleFont_.loadFromFile("C:/Windows/Fonts/BRITANIC.ttf");
  titleText_.setCharacterSize(56);
  titleText_.setFont(titleFont_);
  titleText_.setString(title_);
  titleText_.setFillColor(sf::Color{ 0, 255, 174 });
}

void MainMenuTextBox::intializeMessage()
{
  messageFont_.loadFromFile("C:/Windows/Fonts/consola.ttf");
  messageText_.setCharacterSize(30);
  messageText_.setFont(messageFont_);
  messageText_.setString(message_);
  messageText_.setFillColor(sf::Color{ 255, 0, 144, 255 });
}

void MainMenuTextBox::centerText(sf::Text& text, const float y)
{
  auto bounds = text.getLocalBounds();
  // std::cout << "bounds: left=" << bounds.left << ",width=" << bounds.width << ",top=" <<
  // bounds.top
  //           << ",height=" << bounds.height << std::endl;
  text.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
  // std::cout << "text origin: x=" << text.getOrigin().x << ",y=" << text.getOrigin().y <<
  // std::endl;
  text.setPosition(window_.getSize().x / 2.0f, y);
}

void MainMenuTextBox::draw()
{
  window_.draw(backdrop_);
  window_.draw(titleText_);
  window_.draw(messageText_);
}
