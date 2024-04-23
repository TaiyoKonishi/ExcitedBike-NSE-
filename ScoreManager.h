#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <map>
#include <string>

// The ScoreManager class is responsible for tracking the player's score throughout the game.
class ScoreManager {
public:
    ScoreManager();
    ~ScoreManager();

    // Initializes the Score Manager, performing any initial score settings or score data loading.
    // Called by the GameEngine during the game's initialization phase.
    void Initialize();

    // Adds points to the player's score. The reason parameter indicates why the points are added, such as "stunt" or "timeBonus".
    // This method can be called from various parts of the game where points are awarded, like completing a stunt or finishing a level quickly.
    void AddPoints(int points, const std::string& reason);

    // Deducts points from the player's score, usually as a penalty. The reason parameter indicates why the points are deducted, such as "crash".
    // This method can be used in situations where the player receives a penalty, like crashing into an obstacle.
    void DeductPoints(int points, const std::string& reason);

    // Resets the player's score. Typically used when starting a new game or resetting the current level.
    // Called by the LevelManager when a new level is loaded or the current level is restarted.
    void ResetScore();

    // Gets the player's current score.
    // This can be used by the GameUI to display the score on the screen.
    int GetCurrentScore() const;

    // Updates the state of the Score Manager as needed.
    // This includes checking for score-based achievements and updating high scores.
    // Actual usage may vary depending on game design, but it's typically called every frame from the GameEngine's update loop.
    void Update(float deltaTime);

private:
    int currentScore; // The player's current score.
    std::map<std::string, int> scoreHistory; // History of score changes. Tracks why scores were changed.

    // Additional member variables for managing scoring criteria, high scores, and achievements.
    int highScore; // The high score of the game.
    std::map<std::string, bool> achievements; // List of achievements the player has unlocked.
};

#endif // SCOREMANAGER_H

