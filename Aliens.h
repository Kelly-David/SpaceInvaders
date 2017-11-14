#include <SFML/Graphics.hpp>
#include <iostream>

class Aliens {
public:
	Aliens();
	Aliens(float);
	sf::RectangleShape & getAlien();
	bool isAlive();
	void create();
	void setPosition(float, float);
	void move(float, float);
	void draw(sf::RenderWindow& window);
	void kill();
	float getSpeed();
private:
	sf::RectangleShape alien;
	bool alive;
	float speed;
};
 