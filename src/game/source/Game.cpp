//
// Created by sunil on 3/27/19.
//

#include "../headers/Game.h"
#include <SFML/Graphics.hpp>

using namespace sf;

void Game::run() {
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Chess");
    window.setFramerateLimit(FPS);

    Texture tBoard;
    tBoard.loadFromFile("../assets/board/board.png");
    Sprite sBoard(tBoard);

    Texture tWhitePawn;
    tWhitePawn.loadFromFile("../assets/pieces/wP.png");
    Sprite sWhitePawn(tWhitePawn);

    Texture tBlackPawn;
    tBlackPawn.loadFromFile("../assets/pieces/bP.png");
    Sprite sBlackPawn(tBlackPawn);

    Texture tWhiteRook;
    tWhiteRook.loadFromFile("../assets/pieces/wR.png");
    Sprite sWhiteRook(tWhiteRook);

    Texture tBlackRook;
    tBlackRook.loadFromFile("../assets/pieces/bR.png");
    Sprite sBlackRook(tBlackRook);

    Texture tWhiteKnight;
    tWhiteKnight.loadFromFile("../assets/pieces/wN.png");
    Sprite sWhiteKnight(tWhiteKnight);

    Texture tBlackKnight;
    tBlackKnight.loadFromFile("../assets/pieces/bN.png");
    Sprite sBlackKnight(tBlackKnight);

    Texture tWhiteQueen;
    tWhiteQueen.loadFromFile("../assets/pieces/wQ.png");
    Sprite sWhiteQueen(tWhiteQueen);

    Texture tBlackQueen;
    tBlackQueen.loadFromFile("../assets/pieces/bQ.png");
    Sprite sBlackQueen(tBlackQueen);

    Texture tWhiteKing;
    tWhiteKing.loadFromFile("../assets/pieces/wK.png");
    Sprite sWhiteKing(tWhiteKing);

    Texture tBlackKing;
    tBlackKing.loadFromFile("../assets/pieces/bK.png");
    Sprite sBlackKing(tBlackKing);


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(sBoard);
        window.display();
    }

}