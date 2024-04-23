#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SFML/Graphics.hpp>
#include "Bike.h"
#include "Player.h"
#include "GameUI.h"

class InputHandler {
public:
    InputHandler();
    ~InputHandler();

    void Initialize();
    // Processes input events and applies them to the player, bike, and game UI.
    void ProcessInput(sf::Event& event, Player& player, Bike& bike, GameUI& gameUI);
    void Update(float deltaTime, Player& player, Bike& bike);

private:
    // Adds methods to control bike movements based on keyboard inputs.
    void HandleBikeControls(sf::Event& event, Bike& bike);
};

void InputHandler::ProcessInput(sf::Event& event, Player& player, Bike& bike, GameUI& gameUI) {
    //if (event.type == sf::Event::KeyPressed) {
    //    HandleBikeControls(event, bike);
    //}
}

void InputHandler::HandleBikeControls(sf::Event& event, Bike& bike) {
    switch (event.key.code) {
    case sf::Keyboard::E:
        // Selecting the E key tilts the bike forward.
        bike.LeansForward();
        break;
    case sf::Keyboard::S:
        // Selecting the S key accelerates the bike.
        bike.Accelerate();
        break;
    case sf::Keyboard::F:
        // Selecting the F key accelerates the bike twice.
        bike.DoubleAccelerate();
        break;
    case sf::Keyboard::C:
        // If the C key is selected, the bike leans backward.
        bike.LeansBackward();
        break;
    }
}

#endif // INPUTHANDLER_H

