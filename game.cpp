/*
Advanced Programming Lab 4 :: Space Invaders Clone
David Kelly C00192316
Date: 06/12/2016
*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Aliens.h"
#include "Bullet.h"
#include "Ship.h"
int main() {

	// Create the window
	sf::RenderWindow window(sf::VideoMode(600, 400), "Space Invaders");
	
	// Setup shapes and variables
	bool gameOver = false;
	int difficulty = 1;

	// Create Player Object
	float playerSpeed = 2.f;
	Ship playerShip(playerSpeed);
	playerShip.setPosition(playerShip.getShip().getGlobalBounds().width, playerShip.getShip().getGlobalBounds().height + 340);

	// Create a bullet object
	float bulletSpeed = 6.f;
	Bullet bullet(bulletSpeed);

	//Create Vector


	std::vector<Aliens> invaders;
	int NUMBER_OF_ALIENS = 21;
	float alienSpeed = 1000.f;
	float xpos = 1;
	float ypos = 20;
	int invaderNum = 0;
	int count = 0;

	// Create Aliens
	for (int i = 0; i < NUMBER_OF_ALIENS; i++) {
		Aliens alien(alienSpeed);
		if (invaderNum != 0 && invaderNum != 1 && invaderNum % 7 == 0) {
			ypos += 30;
			xpos = 1;
			count = 0;
		}
		alien.setPosition(xpos + 50 *count, ypos);
		invaders.push_back(alien);
		invaderNum++;
		count++;
	}

	// Direction the Aliens are moving
	bool direction = true;

	// Set time frame to 1 60th of a second. 60 frames per second
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// Clock object keeps the time.
	sf::Clock clock;
	clock.restart();

	while (window.isOpen())
	{
		// Check if the close window button is clicked on.
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();
		// Update every 60th of a second

		// Only when the time since last update is greate than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			// Get keyboard input.
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				playerShip.getShip().move(-playerShip.getSpeed(), 0.f);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				playerShip.getShip().move(+playerShip.getSpeed(), 0.f);
			}
			if (playerShip.getShip().getPosition().x >= 570) {
				playerShip.setPosition(1, 370);
			}
			if (playerShip.getShip().getPosition().x <= 0) {
				playerShip.setPosition(570, 370);
			}
			// Fire a bullet
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				if (bullet.isAlive() == false) {
					bullet.create();
					bullet.setPosition(playerShip.getShip().getPosition().x, playerShip.getShip().getPosition().y);
				}
			}
			// Test collision with bullet and boundary
			if (bullet.getBullet().getPosition().y < 0)
				bullet.kill();

			// Test collisions between bullet and aliens
			for(int i = 0; i < invaders.size(); i++) {
				if (bullet.isAlive() && invaders[i].isAlive() && invaders[i].getAlien().getGlobalBounds().intersects(bullet.getBullet().getGlobalBounds()) == true) {
					bullet.kill();
					invaders.erase(invaders.begin() + i);
				}
			}

			// Test collisions between ship and aliens
			for (int i = 0; i < invaders.size(); i++) {
				if (invaders[i].getAlien().getPosition().y > 380) {
					gameOver = true;
				}
			}

			// Move aliens
			for (int i = 0; i < invaders.size(); i++) {
				if (invaders[invaders.size()-1].getAlien().getPosition().x > 580) {
					direction = false;
					invaders[i].getAlien().move(0.f, +10 );
				}
				if (invaders[0].getAlien().getPosition().x < 0) {
					direction = true;
					invaders[i].getAlien().move(0.f, +10 );
				}
				if (direction) {
					invaders[i].getAlien().move(1 * difficulty, 0.f);
				}
				if (!direction) {
					invaders[i].getAlien().move(-1 * difficulty, 0.f);
				}
			}

			if (invaders.size() == 0) {
				gameOver = true;
			}

			//Check Game Status
			if (gameOver) {
				if (invaders.size() == 0) {
					xpos = 1;
					ypos = 20;
					invaderNum = 0;
					count = 0;
					for (int i = 0; i < NUMBER_OF_ALIENS; i++) {
						Aliens alien(alienSpeed);
						if (invaderNum != 0 && invaderNum != 1 && invaderNum % 7 == 0) {
							ypos += 30;
							xpos = 1;
							count = 0;
						}
						alien.setPosition(xpos + 50 * count, ypos);
						invaders.push_back(alien);
						invaderNum++;
						count++;
					}
					gameOver = false;
					//difficulty++;
				}
				else {
					invaders.clear();
				}
			}

			// Clear the screen and draw all the shapes
			window.clear();
			playerShip.draw(window);
			for (size_t i = 0; i<invaders.size(); i++) {
				if (invaders[i].isAlive()) {
					invaders[i].draw(window);
				}
			}

			// Move bullet
			if(bullet.isAlive() == true){
				bullet.draw(window);
				bullet.move(0.f, -25);
			}
			window.display();

			// reset the time
			timeSinceLastUpdate = sf::Time::Zero;
		}		

	}
	return 0;
}