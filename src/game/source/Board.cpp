//
// Created by sunil on 3/28/19.
//

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "../headers/Board.h"
#include "../../pieces/headers/Rook.h"
#include "../../pieces/headers/Knight.h"
#include "../../pieces/headers/Bishop.h"
#include "../../pieces/headers/Queen.h"
#include "../../pieces/headers/King.h"
#include "../../pieces/headers/Pawn.h"
#include "../../pieces/headers/FreeSpace.h"

using namespace sf;

Board::Board(int SPRITE_SIZE) {
    this->SPRITE_SIZE = SPRITE_SIZE;
    this->tWhitePawn.loadFromFile("../assets/pieces/wP.png");
    this->tBlackPawn.loadFromFile("../assets/pieces/bP.png");
    this->tWhiteRook.loadFromFile("../assets/pieces/wR.png");
    this->tBlackRook.loadFromFile("../assets/pieces/bR.png");
    this->tWhiteKnight.loadFromFile("../assets/pieces/wN.png");
    this->tBlackKnight.loadFromFile("../assets/pieces/bN.png");
    this->tWhiteBishop.loadFromFile("../assets/pieces/wB.png");
    this->tBlackBishop.loadFromFile("../assets/pieces/bB.png");
    this->tWhiteQueen.loadFromFile("../assets/pieces/wQ.png");
    this->tBlackQueen.loadFromFile("../assets/pieces/bQ.png");
    this->tWhiteKing.loadFromFile("../assets/pieces/wK.png");
    this->tBlackKing.loadFromFile("../assets/pieces/bK.png");

    for (int i = 0; i < 8; i++) {
        board[2][i] = new FreeSpace();
        board[3][i] = new FreeSpace();
        board[4][i] = new FreeSpace();
        board[5][i] = new FreeSpace();
        board[1][i] = new Pawn(new Sprite(tBlackPawn), -1, i*SPRITE_SIZE, SPRITE_SIZE);
        board[6][i] = new Pawn(new Sprite(tWhitePawn), 1, i*SPRITE_SIZE, 6*SPRITE_SIZE);
    }

    this->board[0][0] = new Rook(new Sprite(tBlackRook), -2, 0, 0);
    this->board[0][1] = new Knight(new Sprite(tBlackKnight), -3, SPRITE_SIZE, 0);
    this->board[0][2] = new Bishop(new Sprite(tBlackBishop), -4, 2*SPRITE_SIZE, 0);
    this->board[0][3] = new Queen(new Sprite(tBlackQueen), -5, 3*SPRITE_SIZE, 0);
    this->board[0][4] = new King(new Sprite(tBlackKing), -6, 4*SPRITE_SIZE, 0);
    this->board[0][5] = new Bishop(new Sprite(tBlackBishop), -4, 5*SPRITE_SIZE, 0);
    this->board[0][6] = new Knight(new Sprite(tBlackKnight), -3, 6*SPRITE_SIZE, 0);
    this->board[0][7] = new Rook(new Sprite(tBlackRook), -2, 7*SPRITE_SIZE, 0);

    this->board[7][0] = new Rook(new Sprite(tWhiteRook), 2, 0, 7*SPRITE_SIZE);
    this->board[7][1] = new Knight(new Sprite(tWhiteKnight), 3, SPRITE_SIZE, 7*SPRITE_SIZE);
    this->board[7][2] = new Bishop(new Sprite(tWhiteBishop), 4, 2*SPRITE_SIZE, 7*SPRITE_SIZE);
    this->board[7][3] = new Queen(new Sprite(tWhiteQueen), 5, 3*SPRITE_SIZE, 7*SPRITE_SIZE);
    this->board[7][4] = new King(new Sprite(tWhiteKing), 6, 4*SPRITE_SIZE, 7*SPRITE_SIZE);
    this->board[7][5] = new Bishop(new Sprite(tWhiteBishop), 4, 5*SPRITE_SIZE, 7*SPRITE_SIZE);
    this->board[7][6] = new Knight(new Sprite(tWhiteKnight), 3, 6*SPRITE_SIZE, 7*SPRITE_SIZE);
    this->board[7][7] = new Rook(new Sprite(tWhiteRook), 2, 7*SPRITE_SIZE, 7*SPRITE_SIZE);
}

void Board::mouseEvents(Event *event, bool &mouseButtonReleased, sf::Vector2i mousePos) {
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

void Board::update(sf::Vector2i mousePos, bool &mouseButtonReleased) {
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
                    swap(x, y, mousePos.x / SPRITE_SIZE, mousePos.y / SPRITE_SIZE);
                    printDebug();
                    break;
                }
            }
        }
    }
}

Piece* Board::getElement(int x, int y) {
    return board[y][x];
}

void Board::printDebug() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j]->getId() >= 0)
                std::cout << " " << board[i][j]->getId() << " ";
            else
                std::cout << board[i][j]->getId() << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Board::swap(int oldBoardX, int oldBoardY, int newBoardX, int newBoardY) {
    Piece* tmp = board[oldBoardY][oldBoardX];
    board[oldBoardY][oldBoardX] = board[newBoardY][newBoardX];
    board[newBoardY][newBoardX] = tmp;
}

bool Board::isLegal(sf::Vector2i mousePos, int x, int y) {
    if      (board[y][x]->getId() == -2 || board[y][x]->getId() == 2) return isLegalRook(mousePos, x, y);
    else if (board[y][x]->getId() == -3 || board[y][x]->getId() == 3) return isLegalKnight(mousePos, x, y);
    else if (board[y][x]->getId() == -4 || board[y][x]->getId() == 4) return isLegalBishop(mousePos, x, y);
    else if (board[y][x]->getId() == -5 || board[y][x]->getId() == 5) return isLegalQueen(mousePos, x, y);
    else if (board[y][x]->getId() == -6 || board[y][x]->getId() == 6) return isLegalKing(mousePos, x, y);
    else if (board[y][x]->getId() == -1 || board[y][x]->getId() == 1) return isLegalPawn(mousePos, x, y);
    else return false;
}

bool Board::isLegalRook(sf::Vector2i mousePos, int x, int y) {
    return false;
}

bool Board::isLegalKnight(sf::Vector2i mousePos, int x, int y) {
    return false;
}

bool Board::isLegalBishop(sf::Vector2i mousePos, int x, int y) {
    return false;
}

bool Board::isLegalQueen(sf::Vector2i mousePos, int x, int y){
    return false;
}

bool Board::isLegalKing(sf::Vector2i mousePos, int x, int y) {
    return false;
}

bool Board::isLegalPawn(sf::Vector2i mousePos, int x, int y) {
    return false;
}