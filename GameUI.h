#ifndef GAMEUI_H
#define GAMEUI_H

#include <SFML/Graphics.hpp> // For creating graphical user interfaces with SFML.
#include "Bike.h"
#include "Player.h"

// The GameUI class manages the user interface, including displaying elements like the player's score, time, and speed.
class GameUI {
public:
    GameUI();
    ~GameUI();

    // Initializes UI components.
    // This includes loading font assets, setting initial positions of UI elements, and initializing their values.
    // Called by the GameEngine during game initialization.
    void Initialize();

    // Updates UI elements based on the current game state.
    // This method should be called every frame from the GameEngine's update loop, with deltaTime representing the elapsed time.
    // Adjusts display elements based on changes in the player's score, time, speed, or other game events.
    void Update(float deltaTime, const Player& player, const Bike& bike);

    // Renders the UI elements on the screen.
    // This is called from the GameEngine's rendering loop after all game objects have been rendered,
    // to ensure UI elements are drawn on top. A rendering context is passed in.
    void Render(sf::RenderWindow& window);

    // Processes input specific to UI elements, such as menu navigation and button interactions.
    // Depending on the game's design, input can be directly handled here from the GameEngine's input handler.
    void ProcessInput(const sf::Event& event);

private:
    // UI components like the score display, timer, and speedometer are defined here.
    sf::Font uiFont; // Font used for UI text elements.
    sf::Text scoreText; // Text element for displaying the score.
    sf::Text timeText; // Text element for displaying time.
    sf::Text speedText; // Text element for displaying speed.
};

#endif // GAMEUI_H
