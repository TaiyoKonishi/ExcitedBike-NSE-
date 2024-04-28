#include "RaceBackground.h"
#include <iostream>

// Constructor
RaceBackground::RaceBackground(const std::string& imagePath, float scrollSpeed)
    : imagePath(imagePath), scrollSpeed(scrollSpeed), currentPosition(0.0f) {
}

// Destructor
RaceBackground::~RaceBackground() {
    // Any needed cleanup would go here
}

// Initialize the background
void RaceBackground::Initialize() {
    if (!backgroundTexture.loadFromFile(imagePath)) {
        // Handle the error, e.g., log an error message or use a default texture
        std::cerr << "Failed to load background texture from: " << imagePath << std::endl;
    }

    backgroundTexture.setRepeated(true); // Set texture to repeat mode if scrolling is needed
    backgroundSprite.setTexture(backgroundTexture);
    int windowHeight = 62; // Set half of window height
    backgroundSprite.setTextureRect(sf::IntRect(0, 0, 800, windowHeight)); // Assuming window size for now, adjust as needed
    backgroundSprite.setPosition(0.0f,0.0f);  // Set the position of the sprite to the top-left corner of the window
}

// Update the background's position
void RaceBackground::Update(float deltaTime) {
    currentPosition += scrollSpeed * deltaTime; // Update the scroll position

    // Ensure texture width is non-zero to avoid division by zero
    if (scrollSpeed != 0 && backgroundTexture.getSize().x > 0) {
        backgroundSprite.setTextureRect(sf::IntRect(static_cast<int>(currentPosition) % backgroundTexture.getSize().x, 0, 800, 62));
    }
}


// Render the background
void RaceBackground::Render(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
}
