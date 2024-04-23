#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp> 

// The Player class represents the player character in the game.
class Player {
public:
    Player();
    ~Player();

    // Initializes the player. Sets up initial position and state.
    void Initialize();

    // Updates the player's state, including movement and speed changes.
    void Update(float deltaTime);

    // Renders the player on the screen.
    void Render(sf::RenderWindow& window);

    // Processes player input. Executes actions like jumping and changing speed.
    void ProcessInput(const sf::Event& event);

    // Methods to get and set the position.
    sf::Vector2f GetPosition() const;
    void SetPosition(const sf::Vector2f& position);

    // Methods to get and set the speed.
    float GetSpeed() const;
    void SetSpeed(float speed);

    // Getter and setter for the velocity property. Used for velocity calculations by the physics engine.
    sf::Vector2f GetVelocity() const;
    void SetVelocity(const sf::Vector2f& velocity);

private:
    sf::Vector2f position; // The player's position on the screen.
    float speed; // The player's speed.
    sf::Vector2f velocity; // The player's velocity vector.

};

sf::Vector2f Player::GetVelocity() const {
    // Returns the current velocity vector.
    return velocity;
}

void Player::SetVelocity(const sf::Vector2f& velocity) {
    // Sets the velocity vector.
    this->velocity = velocity;
}

#endif // PLAYER_H

