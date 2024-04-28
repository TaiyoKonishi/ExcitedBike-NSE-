#ifndef TRACK_H
#define TRACK_H

#include <vector>
//#include "Obstacle.h"
#include <SFML/Graphics.hpp>
//#include "Player.h"

// The Track class manages the game environment, including the layout of the track and obstacles.
class Track {
public:
    Track(const std::string& imagePath, float scrollSpeed);
    ~Track();

    // Initializes the track by loading its layout and placing obstacles.
    // This is called by the GameEngine when starting a new level or initializing a new game.
    void Initialize();

    // Updates the state of the track. This includes triggering events related to obstacle movement and player progress.
    // Called from the GameEngine's update loop, checking for player progress and interactions with the track.
    void Update(float deltaTime);

    // Renders the track and its obstacles on the screen.
    // Should be called from the GameEngine's rendering loop, providing the rendering context.
    void Render(sf::RenderWindow& window);

    // Checks and handles collisions between the player and obstacles on the track.
    // This function is called from the GameEngine's update loop after updating the player and track positions.
    //void CheckCollisions(Player& player);

    // Adds a new obstacle to the track.
    //void AddObstacle(const Obstacle& obstacle);

    // Removes a specific obstacle from the track.
    //void RemoveObstacle(const Obstacle& obstacle);

    // Changes the layout of the track. This can be used, for example, to implement track sections that change as the race progresses.
    //void ChangeLayout();

private:
    //std::vector<Obstacle> obstacles; // List of obstacles on the track.
    sf::Sprite trackSprite; // The visual representation of the track.
    sf::Texture trackTexture;
    float scrollSpeed;
    float currentPosition;
    std::string imagePath;
};

#endif // TRACK_H
