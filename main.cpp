#include "RaceBackground.h"
#include "Track.h"

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 180), "Race Game");

    // Create a RaceBackground object with a specified image path and scroll speed
    RaceBackground raceBackground("Audience-image.png", 20.0f); // Adjust scroll speed as needed
    Track track("TrackRender-image.png", 20.0f);

    // Initialize the background
    raceBackground.Initialize();
    track.Initialize();

    sf::Clock clock; // Start a clock to manage the update cycle

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update
        float deltaTime = clock.restart().asSeconds();
        raceBackground.Update(deltaTime);
        track.Update(deltaTime); // Trackの更新

        // Render
        window.clear();
        track.Render(window); // Trackのレンダリング
        raceBackground.Render(window);
        window.display();
    }


    return 0;
}
