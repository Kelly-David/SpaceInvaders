#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet {
public:
	Bullet(float);
	sf::RectangleShape & getBullet();
	bool isAlive();
	void create(); 
	void setPosition(float, float);
	void move(float, float);
	void draw(sf::RenderWindow& window);
	void kill();
private:
	sf::RectangleShape bullet;
	bool alive;
};
