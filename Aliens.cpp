#include "Aliens.h"
Aliens::Aliens(){

}
Aliens::Aliens(float sp) {
	alive = true;
	speed = sp;
	alien.setSize(sf::Vector2f(20, 20));
	alien.setFillColor(sf::Color::Magenta);

}
sf::RectangleShape & Aliens::getAlien()
{
	return alien;
}
float Aliens::getSpeed(){
	return speed;
}
bool Aliens::isAlive()
{
	return alive;
}
void Aliens::create()
{
	alive = true;
}
void Aliens::kill()
{
	alive = false;
}
void Aliens::setPosition(float x, float y)
{
	alien.setPosition(x, y);
}
void Aliens::move(float x, float y)
{
	alien.move(x, y);
}
void Aliens::draw(sf::RenderWindow& window)
{
	window.draw(alien);
}