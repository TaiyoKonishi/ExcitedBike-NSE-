#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp> // Assuming use of SFML for graphics and vector math.

// The Player class represents the player's character in the game.
// It includes properties such as position, speed, and includes behaviors like moving.
class Player {
public:
    Player();
    ~Player();

    // Initializes the player, setting up initial position and state.
    // This function might be called from GameEngine when a new game starts or a new level is loaded.
    void Initialize();

    // Updates the player's state, including position based on current speed and input.
    // This should be called from GameEngine's update loop, passing the time since the last frame (deltaTime).
    void Update(float deltaTime);

    // Renders the player on the screen.
    // This function should be called from GameEngine's render loop, passing a reference to the rendering context.
    void Render(sf::RenderWindow& window);

    // Processes player input to change the player's speed or perform actions like jumping.
    // This should be called from GameEngine's input processing function, likely with input data as arguments.
    void ProcessInput(const sf::Event& event);

    // Getter and setter methods for player properties like position and speed.
    sf::Vector2f GetPosition() const;
    void SetPosition(const sf::Vector2f& position);

    float GetSpeed() const;
    void SetSpeed(float speed);

    // Additional behaviors like acceleration, braking, and jumping can be added here.

private:
    sf::Vector2f position; // Holds the player's position on the screen.
    float speed; // The current speed of the player.
    // Additional properties like acceleration and health could be included here.

    // You might also want to include a reference or pointer back to the GameEngine if the player needs to directly interact with it,
    // for example, to check game state or access global game properties.
    // However, care must be taken to manage this relationship to avoid circular dependencies or memory issues.
};

#endif // PLAYER_H
