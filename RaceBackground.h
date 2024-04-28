#ifndef RACEBACKGROUND_H
#define RACEBACKGROUND_H

#include <SFML/Graphics.hpp>

// Class to manage and render the race track background
class RaceBackground {
public:
    RaceBackground(const std::string& imagePath, float scrollSpeed);
    ~RaceBackground();

    // Initialize the background textures and settings
    void Initialize();

    // Update the background position for scrolling effects
    void Update(float deltaTime);

    // Render the background on the screen
    void Render(sf::RenderWindow& window);

private:
    sf::Texture backgroundTexture;  // Texture for the background image
    sf::Sprite backgroundSprite;    // Sprite for the background image
    float scrollSpeed;              // Speed at which the background scrolls
    float currentPosition;          // Current scroll position of the background
    std::string imagePath;          // Path to the background image file
};

#endif // RACEBACKGROUND_H
