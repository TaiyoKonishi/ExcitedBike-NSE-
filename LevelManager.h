#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <vector>
#include <string>
#include "Track.h"

// The LevelManager class manages levels or stages within the game.
class LevelManager {
public:
    LevelManager();
    ~LevelManager();

    // Initializes the level manager.
    // This includes loading level data from files.
    // Called by the GameEngine during the game's initialization phase.
    void Initialize();

    // Loads a level by its identifier or name.
    // Includes setting up the track, placing obstacles, initializing the player's position, and any level-specific settings.
    void LoadLevel(const std::string& levelName);

    // Advances to the next level in the game.
    // This method may be called after a level is completed, handling any necessary cleanup from the previous level and loading the next one.
    void NextLevel();

    // Resets the current level.
    // Typically called after the player has failed a level or chosen to restart.
    void ResetLevel();

    // Updates the state of the level as needed.
    // This involves managing level-specific events and conditions, such as time limits or checkpoints.
    // Called every frame from the GameEngine's update loop.
    void Update(float deltaTime);

private:
    std::vector<std::string> levels; // List of level names or identifiers. Used for loading levels and tracking progress.
    int currentLevelIndex; // The index of the current level. Indicates which level is currently being played within the `levels` vector.

    std::vector<bool> levelCompletionStatus; // The completion status of each level. True is completed, false is not completed.
    std::vector<int> levelScores; // The player's score for each level. Stores scores for each level.
    std::vector<float> levelProgress; // The player's progress in each level. Values range from 0 to 1, representing the completion percentage of the level.

    // These variables are used to track the player's progress during gameplay and maintain data between levels.
};

#endif // LEVELMANAGER_H
