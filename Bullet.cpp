#include "Bullet.h"

Bullet::Bullet(float speed) {
	alive = false;
	bullet.setSize(sf::Vector2f(5, 5));
	bullet.setFillColor(sf::Color::Green);
}
sf::RectangleShape & Bullet::getBullet()
{
	return bullet;
}
bool Bullet::isAlive()
{
	return alive;
}
void Bullet::create()
{
	alive = true;
}
void Bullet::kill()
{
	alive = false;
}
void Bullet::setPosition(float x, float y)
{
	bullet.setPosition(x, y);
}
void Bullet::move(float x, float y)
{
	bullet.move(x, y);
}
void Bullet::draw(sf::RenderWindow& window) 
{
	window.draw(bullet);
}