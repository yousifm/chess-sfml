//
//  BoardTiles.h
//  chess
//
//  Created by Yousif Alebyary on 2/2/2021.
//  Copyright © 2021 Yousif Alebyary. All rights reserved.
//

#ifndef BoardTiles_h
#define BoardTiles_h

#include <SFML/Graphics.hpp>
#include "Piece.hpp"
#include "Pawn.hpp"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Bishop.h"
#include "Rook.h"

class BoardTiles {
private:
    float tileSize;
    int turn;
    std::vector<sf::Color> colors;
    std::vector<sf::RectangleShape> boardTiles;
    std::vector<Piece> pieces;
public:
    BoardTiles(float, float, float, sf::Color, sf::Color);
    
    void drawBoard(sf::RenderWindow&);
    void mouseClick(float, float);
};

#endif /* BoardTiles_h */
