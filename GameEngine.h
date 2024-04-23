#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <memory>
#include "Player.h"
#include "Bike.h"
#include "Track.h"
#include "Obstacle.h"
#include "GameUI.h"
#include "Renderer.h"
#include "PhysicsEngine.h"
#include "AudioManager.h"
#include "LevelManager.h"
#include "ScoreManager.h"
#include "GameTypeManager.h"
#include "SceneManager.h"
#include "InputHandler.h"
#include "InputHandler.h"

// The GameEngine class manages the main game loop, state management (start, pause, quit),
// and high-level control over other game components.
class GameEngine {
    SceneManager sceneManager;
public:
    GameEngine();
    ~GameEngine();

    // Initializes game components and prepares the game for starting.
    // This involves loading resources, initializing subsystems like rendering and audio,
    // and setting the initial game state.
    void Initialize();

    // Starts the main game loop. This function continuously updates the game state and renders frames
    // until the game ends. The loop includes processing input, updating game logic, and rendering.
    void Run();

    // Pauses the game, potentially freezing updates to game logic while still allowing for rendering.
    // Useful for situations like when the game is minimized or when the player opens an in-game menu.
    void Pause();

    // Resumes the game from a paused state and restarts updates to game logic.
    void Resume();

    // Quits the current game session and performs any necessary cleanup.
    // This includes saving game state, releasing resources, and shutting down subsystems before closing the game.
    void Quit();

private:
    // Responsible for updating game logic.
    // Called every frame during the game loop, covering movement of game entities, collision detection,
    // and other game mechanics.
    void Update(float deltaTime);

    // Responsible for rendering the game.
    // Called every frame following Update, it draws the game state on the screen.
    // Delegates to the Renderer to draw components like the track, player, UI, etc.
    void Render();

    // Processes input from the player.
    // Should poll the InputHandler to update the game state based on player actions,
    // such as moving the player's character or interacting with the game UI.
    void ProcessInput();

    // Member variables for game components. Uses either unique_ptr or shared_ptr depending on ownership needs.
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<AudioManager> audioManager;
    std::unique_ptr<InputHandler> inputHandler;
    std::unique_ptr<PhysicsEngine> physicsEngine;
    std::unique_ptr<LevelManager> levelManager;
    std::unique_ptr<ScoreManager> scoreManager;

    GameTypeManager gameTypeManager;

    void StartGame(int gameTypeSelection) {
        // Based on gameTypeSelection, creates the appropriate GameType and sets it in gameTypeManager.
        // if (gameTypeSelection == 1) {
        //     gameTypeManager.SetGameType(std::make_unique<NormalRace>());
        // }
        // elif (gameTypeSelection == 2) {
        //     gameTypeManager.SetGameType(std::make_unique<HardRace>());
        // }
        // else if (gameTypeSelection == 3) {
        //      gameTypeManager.SetGameType(std::make_unique<RaceTrack>());
        // }
        // gameTypeManager.Initialize();
    }
};

#endif // GAMEENGINE_H

