//
// Created by sunil on 3/27/19.
//

#include "../headers/Game.h"
#include "../../pieces/headers/Piece.h"
#include "../../pieces/headers/Rook.h"
#include "../../pieces/headers/Bishop.h"
#include "../../pieces/headers/Knight.h"
#include "../../pieces/headers/Queen.h"
#include "../../pieces/headers/King.h"
#include "../../pieces/headers/Pawn.h"
#include "../../pieces/headers/FreeSpace.h"
#include "../headers/Board.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void Game::run() {
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Chess");
    window.setFramerateLimit(FPS);

    Texture tBoard;
    tBoard.loadFromFile("../assets/board/board.png");
    Sprite sBoard(tBoard);

    Board *board = new Board(SPRITE_SIZE, WIDTH, HEIGHT);
    board->getElement(0,0)->getSprite();

    while (window.isOpen()) {
        Event event;
        Vector2i mousePos = Mouse::getPosition(window);
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (!board->isPromote())
                board->mouseEvents(&event, mouseButtonReleased, mousePos);
        }
        if (!board->isPromote())
            board->update(mousePos, mouseButtonReleased);

        window.clear();
        window.draw(sBoard);
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                if (board->getElement(x, y)->getId() != 0)
                    window.draw(board->getElement(x, y)->getSprite());
            }
        }
        if (board->isPromote()) {
            window.draw(board->getSPromotion());
            if (!board->isWhitesMove()) {
                window.draw(board->getSWhiteQueen());
                window.draw(board->getSWhiteBishop());
                window.draw(board->getSWhiteRook());
                window.draw(board->getSWhiteKnight());
            } else {
                window.draw(board->getSBlackQueen());
                window.draw(board->getSBlackKnight());
                window.draw(board->getSBlackRook());
                window.draw(board->getSBlackBishop());
            }
            board->promotion(&event, mousePos);
        }
        window.display();
    }
}
