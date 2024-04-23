#ifndef BIKE_H
#define BIKE_H

#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Track.h"

class Bike {
public:
    Bike(Player* player);
    ~Bike();

    // Initializes bike
    void Initialize();

    // Updates bike's state with the given deltaTime
    void Update(float deltaTime);

    // Renders bike on the given window
    void Render(sf::RenderWindow& window);

    // Processes user input events
    void ProcessInput(const sf::Event& event);

    // Handles interaction between the bike and the track
    void InteractWithTrack(const Track& track);

    // Executes the action of leaning bike forward
    void LeansForward();

    // Executes the action of accelerating the bike
    void Accelerate();

    // Executes the action of accelerating the bike more forcefully
    void DoubleAccelerate();

    // Executes the action of leaning the bike backward
    void LeansBackward();

private:
    sf::Vector2f position; // Position of the bike on the screen
    float speed; // Current speed of the bike
    sf::Sprite bikeSprite; // Sprite representing the bike
    Player* player; // Pointer to the player controlling the bike
};

#endif // BIKE_H
