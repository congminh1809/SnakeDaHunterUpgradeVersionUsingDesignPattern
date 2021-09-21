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
  centerText(titleText_, 460);

  // Center the text
  initializeMessage();
  centerText(messageText_, 640);
}

void ScreenTextBox::initializeBackdrop()
{
  backdrop_.setFillColor(sf::Color{ 0, 0, 255, 0 });
  backdrop_.setOutlineColor(sf::Color::White);
  backdrop_.setSize(sf::Vector2f{ window_.getSize() });
  backdrop_.setPosition(0, 0);
}

void ScreenTextBox::initializeTitle()
{
  titleFont_.loadFromFile("C:/Windows/Fonts/consolab.ttf");

  titleText_.setFont(titleFont_);
  titleText_.setCharacterSize(100);
  titleText_.setFillColor(sf::Color(255, 0, 98, 255));
  titleText_.setString(title_);
}

void ScreenTextBox::initializeMessage()
{
  messageFont_.loadFromFile("C:/Windows/Fonts/consola.ttf");

  messageText_.setFont(messageFont_);
  messageText_.setCharacterSize(50);
  messageText_.setFillColor(sf::Color(0, 255, 170, 255));
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
