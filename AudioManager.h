#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <SFML/Audio.hpp> // Using SFML for audio management.
#include <string>
#include <map>

// The AudioManager class manages game audio including sound effects and music.
class AudioManager {
public:
    AudioManager();
    ~AudioManager();

    // Initializes the audio manager and loads sound effects and music tracks into memory.
    // Called by GameEngine during the game's initialization phase.
    void Initialize();

    // Plays a sound effect identified by a unique name.
    // Can be called from anywhere within the game, such as when the player jumps or collides with an obstacle.
    void PlaySoundEffect(const std::string& name);

    // Plays a music track identified by a unique name, optionally looping the track.
    // Called to change background music based on game state, like entering a new level.
    void PlayMusic(const std::string& name, bool loop = false);

    // Stops the currently playing music track.
    // Used to stop background music when the game is paused or the player returns to the main menu.
    void StopMusic();

    // Updates the state of the audio manager.
    // Includes adjusting the volume based on game settings or managing audio channels.
    // Called every frame from the GameEngine's update loop.
    void Update(float deltaTime);

    // Additional functionalities related to audio management can be added here.
    // This could include methods for adjusting the global sound effect and music volume, or pausing/resuming audio.

private:
    std::map<std::string, sf::SoundBuffer> soundEffects; // Stores sound effects loaded from files.
    std::map<std::string, sf::Music> musicTracks; // Stores music tracks that may be streamed from files.
    sf::Music currentMusic; // The music track currently being played.

};

#endif // AUDIOMANAGER_H
