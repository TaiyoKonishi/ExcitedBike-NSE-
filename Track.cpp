#include "Track.h"
#include <iostream>

// Constractor
Track::Track(const std::string& imagePath, float scrollSpeed)
	: imagePath(imagePath), scrollSpeed(scrollSpeed), currentPosition(0.0f) {
}

// Destructor
Track::~Track() {

}

// Initialize Track Rendering
void Track::Initialize() {
	if (!trackTexture.loadFromFile(imagePath)) {
		std::cerr << "Failed to load Track texture from: " << imagePath << std::endl;
	}

	trackTexture.setRepeated(true);
	trackSprite.setTexture(trackTexture);
	float yOffset = 62.0f; 
	trackSprite.setPosition(0.0f, yOffset);
	trackSprite.setTextureRect(sf::IntRect(0, 63, 800, 120));
}

// Update the track position
void Track::Update(float deltaTime) {
	currentPosition += scrollSpeed * deltaTime;

	if (scrollSpeed != 0 && trackTexture.getSize().x > 0) {
		trackSprite.setTextureRect(sf::IntRect(static_cast<int>(currentPosition) % trackTexture.getSize().x, 0, 800, 120));
	}
}

void Track::Render(sf::RenderWindow& window) {
	window.draw(trackSprite);
}
