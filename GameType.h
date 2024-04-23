#ifndef GAMETYPE_H
#define GAMETYPE_H

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
#include "ObstacleType.h"

class GameType {
public:
    virtual ~GameType() {}

    // Specific initialization for the game type. This includes setting up tracks, obstacles, and game rules.
    virtual void Initialize() = 0;

    // Update method for game-type-specific logic, called every frame.
    virtual void Update(float deltaTime) = 0;

    // Render method for game-type-specific elements.
    virtual void Render(sf::RenderWindow& window) = 0;
};

#endif // GAMETYPE_H
