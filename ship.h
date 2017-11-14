#include <SFML/Graphics.hpp>
#include <iostream>

class Ship {
public:
	Ship();
	Ship(float);
	sf::RectangleShape & getShip();
	bool isAlive();
	void create();
	void setPosition(float, float);
	void move(float, float);
	void draw(sf::RenderWindow& window);
	void kill();
	float getSpeed();
private:
	sf::RectangleShape ship;
	bool alive;
	float speed;
};
