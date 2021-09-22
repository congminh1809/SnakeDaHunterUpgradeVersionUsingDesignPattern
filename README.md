# SnakeDaHunter_UpgradeVersionUsingDesignPattern

Snake Da Hunter Game using SFML

"Snake Da Hunter" game, an upgraded version of the famous game Snake game.
In this Project, I have developed all part of the game, include logic part, design part and menu part using C++ programming language, SFML and Visual Studio IDE
Project Knowledge: Advance C++ Programming; Object Oriented Programming (OOP); Simple and Fast Multimedia Library (SFML); Design Pattern

Game Layout
<p align="center">
   <img width="800" height="850" src="https://github.com/congminh1809/SnakeDaHunter_UpgradeVersionUsingDesignPattern/blob/master/SFML-2.5.1/Demo.gif">
</p>

Game Logic Execution:

i. Part 1

- Write the simplest framework with 3 classes in the design.
- Snake Class:
o Initialize a snake consisting of 2 body pieces and 1 head piece at a fixed position on the screen.
o Draw the snake on the graphic screen.
- Class World:
o Initializes a wall around the screen and an apple at a random location (not at the wall or the snake's body)
o Draw the wall and the apple on the graphic screen.
- Class Game:
o Initialize the game screen.
o Use Snake and World to draw the entire game onto the graphic screen. o Handle the screen close event.

ii. Part 2

- Update Snake class to be able to move in 4 directions with up, down, left, right keys.
o Add a dir_ attribute of the Direction enum type to store the current motion direction.
o Add getters and setters for this dir_ attribute. o Add private method Snake::move() to reset body position to new position.
o Add a public method Snake::update() that will be used by the Game class after handling the keys. This method will call the private method move() above.
- Update the World class to spawn an apple in a random location:
o Add a private method World::createApple() to generate a random apple on the game screen. This location should not coincide with the walls. This method will be used when the World is initialized and after the snake eats the apple.
- Update Game class to move the snake:
o Add public method Game::checkInput() to check if arrow keys are pressed or not. If so, we will call the Snake::direction(Direction) function of the snake to set a new direction for it
o Add a public method Game::update() to call the snake's Snake::update() method to move the snake to another location.
- Update main() function to:
o Call game.checkInput() o Call game.update()

iii. Part 3

Write code to update the state of the game.
Add the following properties to Snake:
- int lives_: stores the number of times the snake is allowed to touch its body. The value for it is set at the constructor (e.g. value could be 3)
- bool isDead_ : determines whether the snake is alive or dead. The snake will die when its lives_ = 0 or when it hits a wall.
- Add getter/setter for isDead_ attribute
Modify the Snake::update() function to:
- Check if the snake is touching its body or not. If it touches its body, the segment from where it was touched to its tail will be cut off and lives_ reduced by 1 - If lives_ == 0 then the snake will die.
Modify the World::update() function to:
- Check if the snake can eat the apple. If possible, increase the length of the snake by 1 cell and create a new apple.
- Check if the snake is touching the wall. If it touches the wall, the snake will die.
Modify the Game::update() function to:
- Check if the snake is alive or dead. If the snake dies, print the command line "Game Over" and exit the program.
