#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bike.h"

// The Obstacle class represents obstacles encountered by the player on the track.
class Obstacle {
public:
    Obstacle();
    virtual ~Obstacle();

    virtual void Initialize(); // Initializes the obstacle. Sets the size, position, and potential effects.
    virtual void Update(float deltaTime); // Updates the state of the obstacle. Used for behaviors over time, like moving obstacles.
    virtual void Render(sf::RenderWindow& window); // Renders the obstacle on the screen.
    virtual void CheckCollision(Player& player, Bike& bike); // Checks for collisions with the player or bike.

    sf::Vector2f GetPosition() const; // Gets the position of the obstacle.
    void SetPosition(const sf::Vector2f& position); // Sets the position of the obstacle.

protected:
    sf::Vector2f position; // The position of the obstacle on the track.
    sf::Sprite obstacleSprite; // The visual representation of the obstacle.
    float size; // The size of the obstacle, indicating its dimensions or area it occupies.
    std::string effectOnPlayer; // The effect on the player, such as "speed reduction".

    // The GameEngine calls the obstacle's Update and CheckCollision to facilitate dynamic interactions
    // between the player and the track. For example, if a collision with the player is detected in the CheckCollision method,
    // it may perform actions like reducing the player's speed.
};

#endif // OBSTACLE_H
