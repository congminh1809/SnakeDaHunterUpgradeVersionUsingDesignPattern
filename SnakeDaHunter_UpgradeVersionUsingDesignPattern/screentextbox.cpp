#include "screentextbox.h"

ScreenTextBox::ScreenTextBox(sf::RenderWindow& window,
                             const std::string& title,
                             const std::string& msg)
  : window_{ window }
  , title_{ title }
  , message_{ msg }
{
  initializeBackdrop();

  initializeTitle();
  centerText(titleText_, 260);

  // Center the text
  initializeMessage();
  centerText(messageText_, 340);
}

void ScreenTextBox::initializeBackdrop()
{
  backdrop_.setFillColor(sf::Color{ 0, 0, 255, 120 });
  backdrop_.setOutlineColor(sf::Color::Blue);
  backdrop_.setSize(sf::Vector2f{ window_.getSize() });
  backdrop_.setPosition(0, 0);
}

void ScreenTextBox::initializeTitle()
{
  titleFont_.loadFromFile("C:/Windows/Fonts/consolab.ttf");

  titleText_.setFont(titleFont_);
  titleText_.setCharacterSize(60);
  titleText_.setFillColor(sf::Color{ 160, 0, 0 });
  titleText_.setString(title_);
}

void ScreenTextBox::initializeMessage()
{
  messageFont_.loadFromFile("C:/Windows/Fonts/consola.ttf");

  messageText_.setFont(messageFont_);
  messageText_.setCharacterSize(30);
  messageText_.setFillColor(sf::Color::White);
  messageText_.setString(message_);
}

void ScreenTextBox::centerText(sf::Text& text, const float y)
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

void ScreenTextBox::setTitle(const std::string& t)
{
  title_ = t;
  initializeTitle();
}

void ScreenTextBox::setMessage(const std::string& m)
{
  message_ = m;
  initializeMessage();
}

void ScreenTextBox::draw()
{
  window_.draw(backdrop_);
  window_.draw(titleText_);
  window_.draw(messageText_);
}
