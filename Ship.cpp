#include "Ship.h"
Ship::Ship() {

}
Ship::Ship(float sp) {
	alive = true;
	speed = sp;
	ship.setSize(sf::Vector2f(30, 30));
	ship.setFillColor(sf::Color::Cyan);

}
sf::RectangleShape & Ship::getShip()
{
	return ship;
}
float Ship::getSpeed() {
	return speed;
}
bool Ship::isAlive()
{
	return alive;
}
void Ship::create()
{
	alive = true;
}
void Ship::kill()
{
	alive = false;
}
void Ship::setPosition(float x, float y)
{
	ship.setPosition(x, y);
}
void Ship::move(float x, float y)
{
	ship.move(x, y);
}
void Ship::draw(sf::RenderWindow& window)
{
	window.draw(ship);
}