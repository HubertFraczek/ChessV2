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
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void Game::run() {
    RenderWindow window(VideoMode(WIDTH, HEIGHT), "Chess");
    window.setFramerateLimit(FPS);

    Texture tBoard;
    tBoard.loadFromFile("../assets/board/board.png");
    Sprite sBoard(tBoard);

    Texture tWhitePawn;
    tWhitePawn.loadFromFile("../assets/pieces/wP.png");

    Texture tBlackPawn;
    tBlackPawn.loadFromFile("../assets/pieces/bP.png");

    Texture tWhiteRook;
    tWhiteRook.loadFromFile("../assets/pieces/wR.png");

    Texture tBlackRook;
    tBlackRook.loadFromFile("../assets/pieces/bR.png");

    Texture tWhiteKnight;
    tWhiteKnight.loadFromFile("../assets/pieces/wN.png");

    Texture tBlackKnight;
    tBlackKnight.loadFromFile("../assets/pieces/bN.png");

    Texture tWhiteBishop;
    tWhiteBishop.loadFromFile("../assets/pieces/wB.png");

    Texture tBlackBishop;
    tBlackBishop.loadFromFile("../assets/pieces/bB.png");

    Texture tWhiteQueen;
    tWhiteQueen.loadFromFile("../assets/pieces/wQ.png");

    Texture tBlackQueen;
    tBlackQueen.loadFromFile("../assets/pieces/bQ.png");

    Texture tWhiteKing;
    tWhiteKing.loadFromFile("../assets/pieces/wK.png");

    Texture tBlackKing;
    tBlackKing.loadFromFile("../assets/pieces/bK.png");

    Piece* board[8][8] = {
        new Rook(new Sprite(tBlackRook), -2, 0, 0),
        new Knight(new Sprite(tBlackKnight), -3, SPRITE_SIZE, 0),
        new Bishop(new Sprite(tBlackBishop), -4, 2*SPRITE_SIZE, 0),
        new Queen(new Sprite(tBlackQueen), -5, 3*SPRITE_SIZE, 0),
        new King(new Sprite(tBlackKing), -6, 4*SPRITE_SIZE, 0),
        new Bishop(new Sprite(tBlackBishop), -4, 5*SPRITE_SIZE, 0),
        new Knight(new Sprite(tBlackKnight), -3, 6*SPRITE_SIZE, 0),
        new Rook(new Sprite(tBlackRook), -2, 7*SPRITE_SIZE, 0),
        new Pawn(new Sprite(tBlackPawn), -1, 0, SPRITE_SIZE),
        new Pawn(new Sprite(tBlackPawn), -1, SPRITE_SIZE, SPRITE_SIZE),
        new Pawn(new Sprite(tBlackPawn), -1, 2*SPRITE_SIZE, SPRITE_SIZE),
        new Pawn(new Sprite(tBlackPawn), -1, 3*SPRITE_SIZE, SPRITE_SIZE),
        new Pawn(new Sprite(tBlackPawn), -1, 4*SPRITE_SIZE, SPRITE_SIZE),
        new Pawn(new Sprite(tBlackPawn), -1, 5*SPRITE_SIZE, SPRITE_SIZE),
        new Pawn(new Sprite(tBlackPawn), -1, 600, 100),
        new Pawn(new Sprite(tBlackPawn), -1, 700, 100),
        new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(),
        new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(),
        new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(),
        new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(), new FreeSpace(),
        new Pawn(new Sprite(tWhitePawn), 1, 0, 6*SPRITE_SIZE),
        new Pawn(new Sprite(tWhitePawn), 1, SPRITE_SIZE, 6*SPRITE_SIZE),
        new Pawn(new Sprite(tWhitePawn), 1, 2*SPRITE_SIZE, 6*SPRITE_SIZE),
        new Pawn(new Sprite(tWhitePawn), 1, 3*SPRITE_SIZE, 6*SPRITE_SIZE),
        new Pawn(new Sprite(tWhitePawn), 1, 4*SPRITE_SIZE, 6*SPRITE_SIZE),
        new Pawn(new Sprite(tWhitePawn), 1, 5*SPRITE_SIZE, 6*SPRITE_SIZE),
        new Pawn(new Sprite(tWhitePawn), 1, 6*SPRITE_SIZE, 6*SPRITE_SIZE),
        new Pawn(new Sprite(tWhitePawn), 1, 7*SPRITE_SIZE, 6*SPRITE_SIZE),
        new Rook(new Sprite(tWhiteRook), 2, 0, 7*SPRITE_SIZE),
        new Knight(new Sprite(tWhiteKnight), 3, SPRITE_SIZE, 7*SPRITE_SIZE),
        new Bishop(new Sprite(tWhiteBishop), 4, 2*SPRITE_SIZE, 7*SPRITE_SIZE),
        new Queen(new Sprite(tWhiteQueen), 5, 3*SPRITE_SIZE, 7*SPRITE_SIZE),
        new King(new Sprite(tWhiteKing), 6, 4*SPRITE_SIZE, 7*SPRITE_SIZE),
        new Bishop(new Sprite(tWhiteBishop), 4, 5*SPRITE_SIZE, 7*SPRITE_SIZE),
        new Knight(new Sprite(tWhiteKnight), 3, 6*SPRITE_SIZE, 7*SPRITE_SIZE),
        new Rook(new Sprite(tWhiteRook), 2, 7*SPRITE_SIZE, 7*SPRITE_SIZE)
    };

    while (window.isOpen()) {
        Event event;
        Vector2i mousePos = Mouse::getPosition(window);
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            mouseEvents(&event, board, mouseButtonReleased, mousePos);
        }
        update(board, mousePos, mouseButtonReleased);

        window.clear();
        window.draw(sBoard);
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                window.draw(board[y][x]->getSprite());
            }
        }
        window.display();
    }
}

void Game::mouseEvents(Event *event, Piece *board[][8], bool &mouseButtonReleased, sf::Vector2i mousePos) {
    if (event->type == Event::MouseButtonPressed) {
        if (event->key.code == Mouse::Left) {
            for (int y = 0; y < 8; y++) {
                for (int x = 0; x < 8; x++) {
                    if (board[y][x]->getId() != 0) {
                        if (board[y][x]->getSprite().getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                            board[y][x]->setIsMove(true);
                            board[y][x]->setIsBeingModified(true);
                            break;
                        }
                    }
                }
            }
        }
    } else if (event->type == Event::MouseButtonReleased) {
        if (event->key.code == Mouse::Left) {
            for (int y = 0; y < 8; y++) {
                for (int x = 0; x < 8; x++) {
                    board[y][x]->setIsMove(false);
                }
            }
            mouseButtonReleased = true;
        }
    }
}

void Game::update(Piece *board[][8], sf::Vector2i mousePos, bool &mouseButtonReleased) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (board[y][x]->getId() != 0) {
                if (board[y][x]->isIsMove()) {
                    board[y][x]->setSpritePos(
                            mousePos.x - SPRITE_SIZE / 2,
                            mousePos.y - SPRITE_SIZE / 2);
                } else if (mouseButtonReleased && !board[y][x]->isIsMove() && board[y][x]->getIsBeingModified()) {
                    board[y][x]->setSpritePos(
                            (mousePos.x / SPRITE_SIZE) * SPRITE_SIZE,
                            (mousePos.y / SPRITE_SIZE) * SPRITE_SIZE);
                    mouseButtonReleased = false;
                    board[y][x]->setIsBeingModified(false);
                    break;
                }
            }
        }
    }
}
