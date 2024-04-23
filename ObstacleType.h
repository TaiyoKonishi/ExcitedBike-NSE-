#include "Obstacle.h"

// Ramp class
class Ramp : public Obstacle {
public:
    Ramp() {}
    virtual ~Ramp() {}

    // Set the size, position, and visual representation of the ramp
    virtual void Initialize() override {
        // Initialization process for the ramp
    }

    // Ramps don't move but update any special animations here
    virtual void Update(float deltaTime) override {
        // Update logic for the ramp, if it has special animations
    }

    // Draw the ramp on the screen
    virtual void Render(sf::RenderWindow& window) override {
        // Rendering process for the ramp
    }

    // Handle the player touching the ramp (e.g., speed boost, jump)
    virtual void CheckCollision(Player& player, Bike& bike) override {
        // Collision handling for the player with the ramp
    }
};

// CoolerZone class
class CoolerZone : public Obstacle {
public:
    CoolerZone() {}
    virtual ~CoolerZone() {}

    // Set the size, position, and visual representation of the cooler zone
    virtual void Initialize() override {
        // Initialization process for the cooler zone
    }

    // Cooler zones are static but update any special effects here
    virtual void Update(float deltaTime) override {
        // Update logic for cooler zones, if they have special effects
    }

    // Draw the cooler zone on the screen
    virtual void Render(sf::RenderWindow& window) override {
        // Rendering process for the cooler zone
    }

    // Handle the player touching the cooler zone (e.g., cooling effect to avoid overheating)
    virtual void CheckCollision(Player& player, Bike& bike) override {
        // Collision handling for the player with the cooler zone
    }
};

// Swamp class
class Swamp : public Obstacle {
public:
    Swamp() {}
    virtual ~Swamp() {}

    // Set the size, position, and visual representation of the swamp
    virtual void Initialize() override {
        // Initialization process for the swamp
    }

    // Swamps are static but update any special effects here
    virtual void Update(float deltaTime) override {
        // Update logic for the swamp, if it has special effects
    }

    // Draw the swamp on the screen
    virtual void Render(sf::RenderWindow& window) override {
        // Rendering process for the swamp
    }

    // Handle the player touching the swamp (e.g., speed reduction, difficulty controlling)
    virtual void CheckCollision(Player& player, Bike& bike) override {
        // Collision handling for the player with the swamp
    }
};

// Slope class
class Slope : public Obstacle {
public:
    Slope() {}
    virtual ~Slope() {}

    // Set the size, position, and visual representation of the slope
    virtual void Initialize() override {
        // Initialization process for the slope
    }

    // Slopes are static but update any special behaviors here
    virtual void Update(float deltaTime) override {
        // Update logic for the slope, if it has special behaviors
    }

    // Draw the slope on the screen
    virtual void Render(sf::RenderWindow& window) override {
        // Rendering process for the slope
    }

    // Handle the player touching the slope (e.g., speed changes, deceleration on uphill, acceleration on downhill)
    virtual void CheckCollision(Player& player, Bike& bike) override {
        // Collision handling for the player with the slope
    }
};
