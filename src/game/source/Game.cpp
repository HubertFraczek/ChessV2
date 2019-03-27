//
// Created by sunil on 3/27/19.
//

#include "../headers/Game.h"
#include <SFML/Graphics.hpp>

using namespace sf;

void Game::run() {
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Chess");
    window.setFramerateLimit(FPS);
    Event event;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear();
        //draw
        window.display();
    }

}