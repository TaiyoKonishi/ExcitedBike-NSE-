#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include "Track.h"
#include "Player.h"
#include "Bike.h"
#include "GameUI.h"

// The Renderer class handles all rendering operations for the game, including drawing the track, player, obstacles, and UI.
class Renderer {
public:
    Renderer();
    ~Renderer();

    // Initializes the renderer, setting up the window creation and loading graphic assets.
    // This is called by the GameEngine during the game's initialization phase.
    void Initialize(sf::RenderWindow& window);

    // Clears the screen to prepare for a new frame.
    void Clear();

    // Renders the game's track. This includes drawing the track itself and its related static elements.
    // Called from the GameEngine's rendering loop, passing the Track object as a reference.
    void RenderTrack(const Track& track, sf::RenderWindow& window);

    // Renders the player's character and bike on the screen.
    // Called after rendering the track in the GameEngine's rendering loop to ensure the player appears on top.
    void RenderPlayer(const Player& player, sf::RenderWindow& window);
    void RenderBike(const Bike& bike, sf::RenderWindow& window);

    // Renders obstacles on the track.
    // Iterates over the obstacles present on the track and renders each one.
    void RenderObstacles(const std::vector<Obstacle>& obstacles, sf::RenderWindow& window);

    // Renders the game UI, including score, time, and other status indicators.
    // The final rendering step to ensure UI elements appear over everything else.
    void RenderGameUI(const GameUI& gameUI, sf::RenderWindow& window);

    // Finalizes the rendering of the current frame and displays the rendered content on the screen.
    // The last step of the rendering process for each frame.
    void Display(sf::RenderWindow& window);

private:
    // Includes sf::Texture for graphical assets and sf::Shader for special graphical effects.
};

#endif // RENDERER_H
