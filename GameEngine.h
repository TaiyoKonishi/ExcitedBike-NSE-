#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <memory>
#include "Player.h"
#include "Bike.h"
#include "Track.h"
#include "Obstacle.h"
#include "GameUI.h"
#include "Renderer.h"
#include "InputHandler.h"
#include "PhysicsEngine.h"
#include "AudioManager.h"
#include "LevelManager.h"
#include "ScoreManager.h"

// The GameEngine class manages the main game loop, state management (e.g., start, pause, end),
// and the high-level control of other game components.
class GameEngine {
public:
    GameEngine();
    ~GameEngine();

    // Initializes game components and prepares the game to start.
    // This includes loading resources, initializing subsystems like rendering and audio, and setting up the initial game state.
    void Initialize();

    // Starts the main game loop. This function will continuously update game state and render frames
    // until the game is exited. The loop includes processing input, updating game logic, and rendering.
    void Run();

    // Pauses the game, which can involve freezing game logic updates while possibly still rendering the game.
    // Useful for when the game is minimized or when the player opens an in-game menu.
    void Pause();

    // Resumes the game from a paused state, restarting the update of game logic.
    void Resume();

    // Ends the current game session, performing cleanup as necessary. This can involve saving game state,
    // releasing resources, and terminating subsystems before closing the game.
    void Quit();

private:
    // Handles the update of game logic. This is called every frame during the game loop
    // and includes moving game entities, collision detection, and other game mechanics.
    void Update(float deltaTime);

    // Handles the rendering of the game. This is called every frame after Update to draw the game state to the screen.
    // It delegates to the Renderer to draw the game's components, like the track, player, and UI.
    void Render();

    // Processes input from the player. This should poll the InputHandler to update the game state
    // based on player actions, such as moving the player's character or interacting with the game UI.
    void ProcessInput();

    // Member variables for game components. These could be unique_ptr or shared_ptr depending on ownership needs.
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<AudioManager> audioManager;
    std::unique_ptr<InputHandler> inputHandler;
    std::unique_ptr<PhysicsEngine> physicsEngine;
    std::unique_ptr<LevelManager> levelManager;
    std::unique_ptr<ScoreManager> scoreManager;
    // Other components like GameUI, Player, etc., would also be included here.
};

#endif // GAMEENGINE_H

