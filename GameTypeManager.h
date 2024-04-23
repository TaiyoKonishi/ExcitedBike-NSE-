#ifndef GAMETYPEMANAGER_H
#define GAMETYPEMANAGER_H

#include "GameType.h"
#include <memory>

class GameTypeManager {
public:
    GameTypeManager();

    // Sets the current game type based on user selection.
    void SetGameType(std::unique_ptr<GameType> gameType);

    // Initializes the current game type.
    void Initialize();

    // Updates the current game type.
    void Update(float deltaTime);

    // Renders the current game type.
    void Render(sf::RenderWindow& window);

private:
    std::unique_ptr<GameType> currentGameType; // The currently active game type.
};

#endif // GAMETYPEMANAGER_H
