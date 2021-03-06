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

Board::Board(int SPRITE_SIZE, int WIDTH, int HEIGHT) {
    this->SPRITE_SIZE = SPRITE_SIZE;
    this->whitesMove = true;
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
    this->tPromotionScreen.loadFromFile("../assets/promotion.png");
    this->sPromotion = new Sprite(tPromotionScreen);
    this->sWhiteQueen = new Sprite(tWhiteQueen);
    this->sWhiteRook = new Sprite(tWhiteRook);
    this->sWhiteBishop = new Sprite(tWhiteBishop);
    this->sWhiteKnight = new Sprite(tWhiteKnight);
    this->sBlackQueen = new Sprite(tBlackQueen);
    this->sBlackRook = new Sprite(tBlackRook);
    this->sBlackBishop = new Sprite(tBlackBishop);
    this->sBlackKnight = new Sprite(tBlackKnight);
    sPromotion->setPosition(0, HEIGHT/2 - SPRITE_SIZE/2);
    sWhiteQueen->setPosition(200, HEIGHT/2 - SPRITE_SIZE/2);
    sBlackQueen->setPosition(200, HEIGHT/2 - SPRITE_SIZE/2);
    sWhiteRook->setPosition(300, HEIGHT/2 - SPRITE_SIZE/2);
    sBlackRook->setPosition(300, HEIGHT/2 - SPRITE_SIZE/2);
    sWhiteBishop->setPosition(400, HEIGHT/2 - SPRITE_SIZE/2);
    sBlackBishop->setPosition(400, HEIGHT/2 - SPRITE_SIZE/2);
    sWhiteKnight->setPosition(500, HEIGHT/2 - SPRITE_SIZE/2);
    sBlackKnight->setPosition(500, HEIGHT/2 - SPRITE_SIZE/2);

    for (int i = 0; i < 8; i++) {
        board[2][i] = freeSpace;
        board[3][i] = freeSpace;
        board[4][i] = freeSpace;
        board[5][i] = freeSpace;
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

Board::~Board() {
    for (int y = 0; y < 8; y++) {
        delete [] *board[y];
    }
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
    int newX = mousePos.x / SPRITE_SIZE;
    int newY = mousePos.y / SPRITE_SIZE;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (board[y][x]->getId() != 0 &&
                ((board[y][x]->getId() > 0 && whitesMove) || (board[y][x]->getId() < 0 && !whitesMove))) {
                if (board[y][x]->isIsMove()) {
                    board[y][x]->setSpritePos(
                            mousePos.x - SPRITE_SIZE / 2,
                            mousePos.y - SPRITE_SIZE / 2);
                    break;
                } else if (mouseButtonReleased && !board[y][x]->isIsMove() && board[y][x]->getIsBeingModified() &&
                        ((board[y][x]->getId() > 0 && whitesMove) || (board[y][x]->getId() < 0 && !whitesMove))) {
                    if (isLegal(mousePos, x, y) && isRevealingCheck(mousePos, x, y)) {
                        makeMove(newX, newY, x, y, mouseButtonReleased);
                        std::pair<int, int> king = findKing(board[newY][newX]->getColor()*(-1));
                        actOnGameEnd(newX, newY, king);
                        if (pvp) {
                            if (abs(board[newY][newX]->getId()) == 1 && newY == 0) {
                                promote = true;
                                toBePromotedX = newX;
                                toBePromotedY = newY;
                            }
                        }
                        if (pvp && !promote && !mate && !stalemate) {
                            flipBoardVertically();
                            flipBoardHorizontally();
                        }
                        printDebug();
                    } else {
                        board[y][x]->setSpritePos(x*SPRITE_SIZE, y*SPRITE_SIZE);
                        mouseButtonReleased = false;
                        board[y][x]->setIsBeingModified(false);
                    }
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
    int newX = (mousePos.x / SPRITE_SIZE);
    int newY = (mousePos.y / SPRITE_SIZE);

    if (newX >= 0 && newX <= 7 && newY >= 0 && newY <= 7) {
        if (newX == x && board[newY][newX]->getColor() != board[y][x]->getColor()) {
            if (newY > y) {
                for (int i = y + 1; i < newY; i++) {
                    if (board[i][newX]->getColor() != 0) return false;
                }
                return true;
            } else {
                for (int i = newY + 1; i < y; i++) {
                    if (board[i][newX]->getColor() != 0) return false;
                }
                return true;
            }
        } else if (newY == y && board[newY][newX]->getColor() != board[y][x]->getColor()) {
            if (newX > x) {
                for (int i = x + 1; i < newX; i++) {
                    if (board[newY][i]->getColor() != 0) return false;
                }
                return true;
            } else {
                for (int i = newX + 1; i < x; i++) {
                    if (board[newY][i]->getColor() != 0) return false;
                }
                return true;
            }
        } else return false;
    }
    return false;
}

bool Board::isLegalKnight(sf::Vector2i mousePos, int x, int y) {
    int newX = (mousePos.x / SPRITE_SIZE);
    int newY = (mousePos.y / SPRITE_SIZE);

    if (newX >= 0 && newX <= 7 && newY >= 0 && newY <= 7) {
        if (board[y][x]->getColor() == -1) {
            if (abs(x - newX) == 2 && abs(y - newY) == 1 && board[newY][newX]->getColor() != -1) return true;
            else if (abs(x - newX) == 1 && abs(y - newY) == 2 && board[newY][newX]->getColor() != -1) return true;
            else return false;
        } else if (board[y][x]->getColor() == 1) {
            if (abs(x - newX) == 2 && abs(y - newY) == 1 && board[newY][newX]->getColor() != 1) return true;
            else if (abs(x - newX) == 1 && abs(y - newY) == 2 && board[newY][newX]->getColor() != 1) return true;
            else return false;
        } else {
            return false;
        }
    }
    return false;
}

bool Board::isLegalBishop(sf::Vector2i mousePos, int x, int y) { //SIGSEGV when beating on the 0 line
    int newX = (mousePos.x / SPRITE_SIZE);
    int newY = (mousePos.y / SPRITE_SIZE);

    if (newX >= 0 && newX <= 7 && newY >= 0 && newY <= 7) {
        if (board[newY][newX]->getColor() != board[y][x]->getColor() && abs(newX - x) == abs(newY - y)) {
            int tmpY = y, tmpX = x;
            while (true) {
                if (newY > y) tmpY++;
                else tmpY--;

                if (newX > x) tmpX++;
                else tmpX--;

                if (tmpX == newX && tmpY == newY) return true;

                if (board[tmpY][tmpX]->getColor() != 0) return false;
            }
        }
    }
    return false;
}

bool Board::isLegalQueen(sf::Vector2i mousePos, int x, int y) {
    if (isLegalRook(mousePos, x, y)) return true;
    if (isLegalBishop(mousePos, x, y)) return true;
    return false;
}

bool Board::isLegalKing(sf::Vector2i mousePos, int x, int y) {
    int newX = (mousePos.x / SPRITE_SIZE);
    int newY = (mousePos.y / SPRITE_SIZE);

    if (newX >= 0 && newX <= 7 && newY >= 0 && newY <= 7) {
        if (board[newY][newX]->getColor() != board[y][x]->getColor()) {
            if ((abs(x - newX) == 1 || abs(x - newX) == 0) && (abs(y - newY) == 1 || abs(y - newY) == 0)) {
                if (newY < 7 && board[newY + 1][newX]->getId() == -1 * board[y][x]->getId()) return false;
                else if (newY > 0 && board[newY - 1][newX]->getId() == -1 * board[y][x]->getId()) return false;
                else if (newY < 7 && newX < 7 && board[newY + 1][newX + 1]->getId() == -1 * board[y][x]->getId())
                    return false;
                else if (newY > 0 && newX < 7 && board[newY - 1][newX + 1]->getId() == -1 * board[y][x]->getId())
                    return false;
                else if (newY < 7 && newX > 0 && board[newY + 1][newX - 1]->getId() == -1 * board[y][x]->getId())
                    return false;
                else if (newY > 0 && newX > 0 && board[newY - 1][newX - 1]->getId() == -1 * board[y][x]->getId())
                    return false;
                else if (newX < 7 && board[newY][newX + 1]->getId() == -1 * board[y][x]->getId()) return false;
                else if (newX > 0 && board[newY][newX - 1]->getId() == -1 * board[y][x]->getId()) return false;
                return true;
            } else if (!pvp && newY == y && newX == 2 && !board[y][x]->isHasMoved() && board[y][3]->getId() == 0 &&
                       board[y][2]->getId() == 0 &&
                       board[y][1]->getId() == 0 &&
                       board[y][0]->getId() == board[y][x]->getId() - board[y][x]->getColor() * 4 &&
                       !board[y][0]->isHasMoved() && !isAttacked(board[y][x]->getColor(), 0, y) &&
                       !isAttacked(board[y][x]->getColor(), 1, y) &&
                       !isAttacked(board[y][x]->getColor(), 2, y) && !isAttacked(board[y][x]->getColor(), 3, y) &&
                       !isAttacked(board[y][x]->getColor(), 4, y)) {

                board[y][0]->setSpritePos((newX + 1) * SPRITE_SIZE, y * SPRITE_SIZE);
                board[y][0]->setHasMoved(true);
                swap(0, y, newX + 1, y);
                return true;
            } else if (!pvp && newY == y && newX == 6 && !board[y][x]->isHasMoved() && board[y][5]->getId() == 0 &&
                       board[y][6]->getId() == 0 &&
                       board[y][7]->getId() == board[y][x]->getId() - board[y][x]->getColor() * 4 &&
                       !board[y][7]->isHasMoved() && !isAttacked(board[y][x]->getColor(), 7, y) &&
                       !isAttacked(board[y][x]->getColor(), 6, y) &&
                       !isAttacked(board[y][x]->getColor(), 5, y) && !isAttacked(board[y][x]->getColor(), x, y)) {
                board[y][7]->setSpritePos((newX - 1) * SPRITE_SIZE, y * SPRITE_SIZE);
                board[y][7]->setHasMoved(true);
                swap(7, y, newX - 1, y);
                return true;
            } else if (pvp) {
                if (newY == y && abs(newX - x) == 2 && !board[y][x]->isHasMoved()) {
                    int tmpX = x;
                    while (true) {
                        if (newX > x) {
                            if (abs(7-newX) == 2) {
                                if (tmpX == newX + 1) break;
                            } else {
                                if (tmpX == newX) break;
                            }
                            tmpX++;
                        } else {
                            if (abs(newX) == 2) {
                                if (tmpX == newX - 1) break;
                            } else {
                                if (tmpX == newX) break;
                            }
                            tmpX--;
                        }
                        if (board[y][tmpX]->getColor() != 0) return false;
                        if (isAttacked(board[y][x]->getColor(), tmpX, y)) return false;
                    }
                    if (newX > x) {
                        if (abs(7-newX) == 2) {
                            if (board[y][newX + 2]->isHasMoved()) return false;
                            if (isAttacked(board[y][x]->getColor(), newX + 2, y)) return false;

                            board[y][newX + 2]->setSpritePos((newX - 1) * SPRITE_SIZE, y * SPRITE_SIZE);
                            board[y][newX + 2]->setHasMoved(true);
                            swap(newX + 2, y, newX - 1, y);
                        } else {
                            if (board[y][newX + 1]->isHasMoved()) return false;
                            if (isAttacked(board[y][x]->getColor(), newX + 1, y)) return false;

                            board[y][newX + 1]->setSpritePos((newX - 1) * SPRITE_SIZE, y * SPRITE_SIZE);
                            board[y][newX + 1]->setHasMoved(true);
                            swap(newX + 1, y, newX - 1, y);
                        }
                        return true;
                    } else {
                        if (abs(newX) == 2) {
                            if (board[y][newX - 2]->isHasMoved()) return false;
                            if (isAttacked(board[y][x]->getColor(), newX - 2, y)) return false;
                            board[y][newX - 2]->setSpritePos((newX + 1) * SPRITE_SIZE, y * SPRITE_SIZE);
                            board[y][newX - 2]->setHasMoved(true);
                            swap(newX - 2, y, newX + 1, y);
                        } else {
                            if (board[y][newX - 1]->isHasMoved()) return false;
                            if (isAttacked(board[y][x]->getColor(), newX - 1, y)) return false;
                            board[y][newX - 1]->setSpritePos((newX + 1) * SPRITE_SIZE, y * SPRITE_SIZE);
                            board[y][newX - 1]->setHasMoved(true);
                            swap(newX - 1, y, newX + 1, y);
                        }
                        return true;
                    }
                }

            }
        }
    }
    return false;
}

bool Board::isLegalPawn(sf::Vector2i mousePos, int x, int y) {
    int newX = (mousePos.x / SPRITE_SIZE);
    int newY = (mousePos.y / SPRITE_SIZE);
    if (newX >= 0 && newX <= 7 && newY >= 0 && newY <= 7) {
        if (pvp && !whitesMove) {
            if (newY > y) return false;

            if (newY == y - 1 && newX == x && board[newY][newX]->getColor() == 0) {
                board[y][x]->setHasMovedBy2(false);
                return true; //move by 1
            } else if (abs(newY-y) == 1 && ((newX == x + 1 && board[newY][newX]->getColor() == -1*board[y][x]->getColor()) ||
                                            (newX == x - 1 && board[newY][newX]->getColor() == -1*board[y][x]->getColor()))) {
                board[y][x]->setHasMovedBy2(false);
                return true; //beating
            } else if (y == 6 && newY == y - 2 && x == newX && board[5][x]->getColor() == 0 &&
                       board[4][x]->getColor() == 0) {
                if (board[newY][newX - 1]->getId() == -1*board[y][x]->getId() ||
                    board[newY][newX + 1]->getId() == -1*board[y][x]->getId())
                    board[y][x]->setHasMovedBy2(true);
                std::cout << "HAS MOVED " << x << " " << y << std::endl;
                return true; //move by 2
            } else if (board[newY + 1][newX]->getId() == -1*board[y][x]->getId() && board[newY + 1][newX]->isHasMovedBy2()
                       && y == newY + 1 && (x == newX + 1 || x == newX - 1)) {
                board[newY + 1][newX] = freeSpace;
                return true;
            }
                //TODO: reaching end line
            else return false;
        } else {
            if (board[y][x]->getColor() == 1 && newY > y) return false;
            if (board[y][x]->getColor() == -1 && newY < y) return false;

            if (board[y][x]->getColor() == -1) {
                if (newY == y + 1 && newX == x && board[newY][newX]->getColor() == 0) {
                    board[y][x]->setHasMovedBy2(false);
                    return true; //move by 1
                } else if (newY == y + 1 && ((newX == x + 1 && board[newY][newX]->getColor() == 1)
                                             || (newX == x - 1 && board[newY][newX]->getColor() == 1))) {
                    board[y][x]->setHasMovedBy2(false);
                    return true;
                } else if (y == 1 && newY == y + 2 && x == newX && board[2][x]->getColor() == 0 &&
                           board[3][x]->getColor() == 0) {
                    if (board[newY][newX - 1]->getId() == 1 || board[newY][newX + 1]->getId() == 1)
                        board[y][x]->setHasMovedBy2(true);
                    return true;
                } else if (board[newY - 1][newX]->getId() == 1 && board[newY - 1][newX]->isHasMovedBy2()
                           && y == newY - 1 && (x == newX + 1 || x == newX - 1)) {
                    board[newY - 1][newX] = freeSpace;
                    return true;
                }
                    //TODO: reaching end line
                else return false;
            } else if (board[y][x]->getColor() == 1) {
                if (newY == y - 1 && newX == x && board[newY][newX]->getColor() == 0) {
                    board[y][x]->setHasMovedBy2(false);
                    return true; //move by 1
                } else if (newY == y - 1 && ((newX == x + 1 && board[newY][newX]->getColor() == -1) ||
                                             (newX == x - 1 && board[newY][newX]->getColor() == -1))) {
                    board[y][x]->setHasMovedBy2(false);
                    return true; //beating
                } else if (y == 6 && newY == y - 2 && x == newX && board[5][x]->getColor() == 0 &&
                           board[4][x]->getColor() == 0) {
                    if (board[newY][newX - 1]->getId() == 1 || board[newY][newX + 1]->getId() == 1)
                        board[y][x]->setHasMovedBy2(true);
                    return true; //move by 2
                } else if (board[newY + 1][newX]->getId() == -1 && board[newY + 1][newX]->isHasMovedBy2()
                           && y == newY + 1 && (x == newX + 1 || x == newX - 1)) {
                    board[newY + 1][newX] = freeSpace;
                    return true;
                }
                    //TODO: reaching end line
                else return false;
            } else {
                return false;
            }
        }
    }
    return false;
}

bool Board::isAttacked(int color, int x, int y) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j]->getColor() == -1*color) {
                if (isLegal(sf::Vector2i(x*SPRITE_SIZE, y*SPRITE_SIZE), j, i)) return true;
            }
        }
    }
    return false;
}

std::pair<int, int> Board::findKing(int color) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if ((board[y][x]->getId() == 6 && color == 1) ||
                (board[y][x]->getId() == -6 && color == -1))
                return std::pair<int, int>{x, y};
        }
    }
}

bool Board::isRevealingCheck(sf::Vector2i mousePos, int x, int y) {
    bool proceed = true;
    int color = board[y][x]->getColor();
    Piece *tmp = board[mousePos.y / SPRITE_SIZE][mousePos.x / SPRITE_SIZE];
    if (board[mousePos.y / SPRITE_SIZE][mousePos.x / SPRITE_SIZE]->getId() != 0) {
        board[mousePos.y / SPRITE_SIZE][mousePos.x / SPRITE_SIZE] = freeSpace;
    }
    swap(x, y, mousePos.x / SPRITE_SIZE, mousePos.y / SPRITE_SIZE);
    std::pair<int, int> king = findKing(color);
    if (isAttacked(color, king.first, king.second)) proceed = false;
    swap(x, y, mousePos.x / SPRITE_SIZE, mousePos.y / SPRITE_SIZE);
    board[mousePos.y / SPRITE_SIZE][mousePos.x / SPRITE_SIZE] = tmp;
    return proceed;
}

void Board::turnOffHasMovedBy2(int color) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (board[y][x]->getColor() == color) board[y][x]->setHasMovedBy2(false);
        }
    }
}

bool Board::anyLegalMove(int x, int y) {
    if      (board[y][x]->getId() == -2 || board[y][x]->getId() == 2) return anyLegalMoveRook(x, y);
    else if (board[y][x]->getId() == -3 || board[y][x]->getId() == 3) return anyLegalMoveKnight(x, y);
    else if (board[y][x]->getId() == -4 || board[y][x]->getId() == 4) return anyLegalMoveBishop(x, y);
    else if (board[y][x]->getId() == -5 || board[y][x]->getId() == 5) return anyLegalMoveQueen(x, y);
    else if (board[y][x]->getId() == -6 || board[y][x]->getId() == 6) return anyLegalMoveKing(x, y);
    else if (board[y][x]->getId() == -1 || board[y][x]->getId() == 1) return anyLegalMovePawn(x, y);
    else return false;
}

bool Board::anyLegalMoveRook(int x, int y) {
    for (int i = x; i < 8; i++) {
        if (isLegalRook(sf::Vector2i(i*SPRITE_SIZE, y*SPRITE_SIZE), x, y) &&
            isRevealingCheck(sf::Vector2i(i*SPRITE_SIZE, y*SPRITE_SIZE), x, y)) {
            return true;
        }
    }
    for (int i = x; i > 0; i--) {
        if (isLegalRook(sf::Vector2i(i*SPRITE_SIZE, y*SPRITE_SIZE), x, y) &&
            isRevealingCheck(sf::Vector2i(i*SPRITE_SIZE, y*SPRITE_SIZE), x, y)) {
            return true;
        }
    }
    for (int i = y; i < 8; i++) {
        if (isLegalRook(sf::Vector2i(x*SPRITE_SIZE, i*SPRITE_SIZE), x, y) &&
            isRevealingCheck(sf::Vector2i(x*SPRITE_SIZE, i*SPRITE_SIZE), x, y)) {
            return true;
        }
    }
    for (int i = y; i > 0; i--) {
        if (isLegalRook(sf::Vector2i(x*SPRITE_SIZE, i*SPRITE_SIZE), x, y) &&
            isRevealingCheck(sf::Vector2i(x*SPRITE_SIZE, i*SPRITE_SIZE), x, y)) {
            return true;
        }
    }
    return false;
}

bool Board::anyLegalMoveKnight(int x, int y) { //bugged af
    if (x >= 2 && y >= 1 && isLegalKnight(sf::Vector2i((x-2)*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y) &&
                            isRevealingCheck(sf::Vector2i((x-2)*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y)) {
        return true;
    }
    else if (x >= 1 && y >= 2 && isLegalKnight(sf::Vector2i((x-1)*SPRITE_SIZE, (y-2)*SPRITE_SIZE), x, y) &&
                                 isRevealingCheck(sf::Vector2i((x-1)*SPRITE_SIZE, (y-2)*SPRITE_SIZE), x, y)) {
        return true;
    }
    else if (x <= 6 && y >= 2 && isLegalKnight(sf::Vector2i((x+1)*SPRITE_SIZE, (y-2)*SPRITE_SIZE), x, y) &&
                                 isRevealingCheck(sf::Vector2i((x+1)*SPRITE_SIZE, (y-2)*SPRITE_SIZE), x, y)) {
        return true;
    }
    else if (x <= 5 && y >= 1 && isLegalKnight(sf::Vector2i((x+2)*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y) &&
                                 isRevealingCheck(sf::Vector2i((x+2)*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y)) {
        return true;
    }
    else if (x <= 5 && y <= 6 && isLegalKnight(sf::Vector2i((x+2)*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y) &&
                                 isRevealingCheck(sf::Vector2i((x+2)*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y)) {
        return true;
    }
    else if (x <= 6 && y <= 5 && isLegalKnight(sf::Vector2i((x+1)*SPRITE_SIZE, (y+2)*SPRITE_SIZE), x, y) &&
                                 isRevealingCheck(sf::Vector2i((x+1)*SPRITE_SIZE, (y+2)*SPRITE_SIZE), x, y)) {
        return true;
    }
    else if (x >= 1 && y <= 5 && isLegalKnight(sf::Vector2i((x-1)*SPRITE_SIZE, (y+2)*SPRITE_SIZE), x, y) &&
                                 isRevealingCheck(sf::Vector2i((x-1)*SPRITE_SIZE, (y+2)*SPRITE_SIZE), x, y)) {
        return true;
    }
    else if (x >= 2 && y <= 6 && isLegalKnight(sf::Vector2i((x-2)*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y) &&
                                 isRevealingCheck(sf::Vector2i((x-2)*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y)) {
        return true;
    }
    return false;
}

bool Board::anyLegalMoveBishop(int x, int y) {
    int tmpX = x;
    int tmpY = y;
    while (tmpX < 7 && tmpY < 7) {
        tmpX++;
        tmpY++;
        if (isLegalBishop(sf::Vector2i(tmpX*SPRITE_SIZE, tmpY*SPRITE_SIZE), x, y) &&
            isRevealingCheck(sf::Vector2i(tmpX*SPRITE_SIZE, tmpY*SPRITE_SIZE), x, y)) return true;
    }
    tmpX = x;
    tmpY = y;
    while (tmpX > 0 && tmpY > 0) {
        tmpX--;
        tmpY--;
        if (isLegalBishop(sf::Vector2i(tmpX*SPRITE_SIZE, tmpY*SPRITE_SIZE), x, y) &&
            isRevealingCheck(sf::Vector2i(tmpX*SPRITE_SIZE, tmpY*SPRITE_SIZE), x, y)) return true;
    }
    tmpX = x;
    tmpY = y;
    while (tmpX < 7 && tmpY > 0) {
        tmpX++;
        tmpY--;
        if (isLegalBishop(sf::Vector2i(tmpX*SPRITE_SIZE, tmpY*SPRITE_SIZE), x, y) &&
            isRevealingCheck(sf::Vector2i(tmpX*SPRITE_SIZE, tmpY*SPRITE_SIZE), x, y)) return true;
    }
    tmpX = x;
    tmpY = y;
    while (tmpX > 0 && tmpY < 7) {
        tmpX--;
        tmpY++;
        if (isLegalBishop(sf::Vector2i(tmpX*SPRITE_SIZE, tmpY*SPRITE_SIZE), x, y) &&
            isRevealingCheck(sf::Vector2i(tmpX*SPRITE_SIZE, tmpY*SPRITE_SIZE), x, y)) return true;
    }
    return false;
}

bool Board::anyLegalMoveQueen(int x, int y) {
    if (anyLegalMoveRook(x, y)) return true;
    if (anyLegalMoveBishop(x, y)) return true;
    return false;
}

bool Board::anyLegalMoveKing(int x, int y) {
    if      (x < 7 && isLegalKing(sf::Vector2i((x+1)*SPRITE_SIZE, y*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i((x+1)*SPRITE_SIZE, y*SPRITE_SIZE), x, y))
        return true;
    else if (x < 7 && y > 0 && isLegalKing(sf::Vector2i((x+1)*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i((x+1)*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y))
        return true;
    else if (x < 7 && y < 7 && isLegalKing(sf::Vector2i((x+1)*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i((x+1)*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y))
        return true;
    else if (y > 0 && isLegalKing(sf::Vector2i(x*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i(x*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y))
        return true;
    else if (y < 7 && isLegalKing(sf::Vector2i(x*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i(x*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y))
        return true;
    else if (x > 0 && isLegalKing(sf::Vector2i((x-1)*SPRITE_SIZE, y*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i((x-1)*SPRITE_SIZE, y*SPRITE_SIZE), x, y))
        return true;
    else if (x > 0 && y > 0 && isLegalKing(sf::Vector2i((x-1)*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i((x-1)*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y))
        return true;
    else if (x > 0 && y < 7 && isLegalKing(sf::Vector2i((x-1)*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i((x-1)*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y))
        return true;
    return false;
}

bool Board::anyLegalMovePawn(int x, int y) {
    if (board[y][x]->getColor() == 1 && y > 0 && isLegalPawn(sf::Vector2i(x*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y) &&
        isRevealingCheck(sf::Vector2i(x*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y))
        return true;
    else if (board[y][x]->getColor() == -1 && y < 7 && isLegalPawn(sf::Vector2i(x*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i(x*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y))
        return true;
    else if (board[y][x]->getColor() == -1 && y < 6 && isLegalPawn(sf::Vector2i(x*SPRITE_SIZE, (y+2)*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i(x*SPRITE_SIZE, (y+2)*SPRITE_SIZE), x, y))
        return true;
    else if (board[y][x]->getColor() == 1 && y > 1 && isLegalPawn(sf::Vector2i(x*SPRITE_SIZE, (y-2)*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i(x*SPRITE_SIZE, (y-2)*SPRITE_SIZE), x, y))
        return true;
    else if (board[y][x]->getColor() == -1 && x < 7 && y < 7 && isLegalPawn(sf::Vector2i((x+1)*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i((x+1)*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y))
        return true;
    else if (board[y][x]->getColor() == -1 && x > 0 && y < 7 && isLegalPawn(sf::Vector2i((x-1)*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i((x-1)*SPRITE_SIZE, (y+1)*SPRITE_SIZE), x, y))
        return true;
    else if (board[y][x]->getColor() == 1 && x < 7 && y > 0 && isLegalPawn(sf::Vector2i((x+1)*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i((x+1)*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y))
        return true;
    else if (board[y][x]->getColor() == 1 && x > 0 && y > 0 && isLegalPawn(sf::Vector2i((x-1)*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y) &&
             isRevealingCheck(sf::Vector2i((x-1)*SPRITE_SIZE, (y-1)*SPRITE_SIZE), x, y))
        return true;
    return false;
}

bool Board::isGameOver() {
    int color;
    if (whitesMove) color = 1;
    else color = -1;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (board[y][x]->getColor() == color)
                if (anyLegalMove(x, y)) {
//                    std::cout << "You can block with: " << board[y][x]->getId() << std::endl;
                    return false;
                }
        }
    }
    return true;
}

void Board::flipBoardVertically() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 8; x++) {
            if (board[y][x]->getColor() != 0)
                board[y][x]->setSpritePos(x * SPRITE_SIZE, (7 - y) * SPRITE_SIZE);
            if (board[7 - y][x]->getColor() != 0)
                board[7 - y][x]->setSpritePos(x * SPRITE_SIZE, y * SPRITE_SIZE);
            swap(x, 7 - y, x, y);
        }
    }
}

void Board::flipBoardHorizontally() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 4; x++) {
            if (board[y][x]->getColor() != 0)
                board[y][x]->setSpritePos((7 - x) * SPRITE_SIZE, y * SPRITE_SIZE);
            if (board[y][7 - x]->getColor() != 0)
                board[y][7 - x]->setSpritePos(x * SPRITE_SIZE, y * SPRITE_SIZE);
            swap(7 - x, y, x, y);
        }
    }
}

void Board::promotion(sf::Event *event, sf::Vector2i mousePos) {
    if (event->type == Event::MouseButtonPressed) {
        if (event->key.code == Mouse::Left) {
            bool done = false;
            if (!whitesMove) {
                if (sWhiteQueen->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    done = true;
                    delete board[toBePromotedY][toBePromotedX];
                    board[toBePromotedY][toBePromotedX] = new Queen(
                            new Sprite(tWhiteQueen), 5,
                            toBePromotedX * SPRITE_SIZE,
                            toBePromotedY * SPRITE_SIZE);
                }
                if (sWhiteKnight->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    done = true;
                    delete board[toBePromotedY][toBePromotedX];
                    board[toBePromotedY][toBePromotedX] = new Queen(
                            new Sprite(tWhiteKnight), 3,
                            toBePromotedX * SPRITE_SIZE,
                            toBePromotedY * SPRITE_SIZE);
                }
                if (sWhiteBishop->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    done = true;
                    delete board[toBePromotedY][toBePromotedX];
                    board[toBePromotedY][toBePromotedX] = new Queen(
                            new Sprite(tWhiteBishop), 4,
                            toBePromotedX * SPRITE_SIZE,
                            toBePromotedY * SPRITE_SIZE);
                }
                if (sWhiteRook->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    done = true;
                    delete board[toBePromotedY][toBePromotedX];
                    board[toBePromotedY][toBePromotedX] = new Queen(
                            new Sprite(tWhiteRook), 2,
                            toBePromotedX * SPRITE_SIZE,
                            toBePromotedY * SPRITE_SIZE);
                }
            } else {
                if (sBlackQueen->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    done = true;
                    delete board[toBePromotedY][toBePromotedX];
                    board[toBePromotedY][toBePromotedX] = new Queen(
                            new Sprite(tBlackQueen), -5,
                            toBePromotedX * SPRITE_SIZE,
                            toBePromotedY * SPRITE_SIZE);
                }
                if (sBlackBishop->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    done = true;
                    delete board[toBePromotedY][toBePromotedX];
                    board[toBePromotedY][toBePromotedX] = new Queen(
                            new Sprite(tBlackBishop), -4,
                            toBePromotedX * SPRITE_SIZE,
                            toBePromotedY * SPRITE_SIZE);
                }
                if (sBlackKnight->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    done = true;
                    delete board[toBePromotedY][toBePromotedX];
                    board[toBePromotedY][toBePromotedX] = new Queen(
                            new Sprite(tBlackKnight), -3,
                            toBePromotedX * SPRITE_SIZE,
                            toBePromotedY * SPRITE_SIZE);
                }
                if (sBlackRook->getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    done = true;
                    delete board[toBePromotedY][toBePromotedX];
                    board[toBePromotedY][toBePromotedX] = new Queen(
                            new Sprite(tBlackRook), -2,
                            toBePromotedX * SPRITE_SIZE,
                            toBePromotedY * SPRITE_SIZE);
                }
            }
            if (done) {
                promote = false;
                if (pvp && !promote){
                    flipBoardVertically();
                    flipBoardHorizontally();
                }
            }
        }
    }
}

bool Board::isPromote() {
    return promote;
}

void Board::setPromote(bool promote) {
    Board::promote = promote;
}

Sprite Board::getSPromotion() {
    return *this->sPromotion;
}

void Board::setSPromotion(Sprite *sPromotion) {
    Board::sPromotion = sPromotion;
}

bool Board::isWhitesMove() {
    return whitesMove;
}

void Board::setWhitesMove(bool whitesMove) {
    Board::whitesMove = whitesMove;
}

Sprite Board::getSWhiteQueen() {
    return *this->sWhiteQueen;
}

Sprite Board::getSWhiteRook() {
    return *this->sWhiteRook;
}

Sprite Board::getSWhiteBishop() {
    return *this->sWhiteBishop;
}

Sprite Board::getSWhiteKnight() {
    return *this->sWhiteKnight;
}

Sprite Board::getSBlackQueen() {
    return *this->sBlackQueen;
}

Sprite Board::getSBlackRook() {
    return *this->sBlackRook;
}

Sprite Board::getSBlackBishop() {
    return *this->sBlackBishop;
}

Sprite Board::getSBlackKnight() {
    return *this->sBlackKnight;
}

void Board::actOnGameEnd(int newX, int newY, std::pair<int, int> king) {
    if (isAttacked(board[newY][newX]->getColor()*(-1), king.first, king.second)) {
        if (isGameOver()) {
            std::cout << "Checkmate! ";
            if (!whitesMove) std::cout << "White wins!" << std::endl;
            else std::cout << "Black wins!" << std::endl;
            mate = true;
        }
    } else if (moveNumber > 9 && !isAttacked(board[newY][newX]->getColor()*(-1), king.first, king.second) &&
               isGameOver()) {
        std::cout << "Stalemate!" << std::endl;
        stalemate = true;
    }
}

void Board::makeMove(int newX, int newY, int x, int y, bool &mouseButtonReleased) {
    if (board[newY][newX]->getId() != 0) {
        board[newY][newX] = freeSpace;
    }
    board[y][x]->setSpritePos(
            (newX) * SPRITE_SIZE,
            (newY) * SPRITE_SIZE);
    mouseButtonReleased = false;
    board[y][x]->setIsBeingModified(false);
    board[y][x]->setHasMoved(true);
    turnOffHasMovedBy2(board[y][x]->getColor()*(-1));
    swap(x, y, newX, newY);
    whitesMove = !whitesMove;
    moveNumber++;
    std::cout << "Move number: " << moveNumber/2 << std::endl;
    printDebug();
}

bool Board::isMate() {
    return mate;
}

void Board::setMate(bool mate) {
    Board::mate = mate;
}

bool Board::isStalemate() {
    return stalemate;
}

void Board::setStalemate(bool stalemate) {
    Board::stalemate = stalemate;
}
