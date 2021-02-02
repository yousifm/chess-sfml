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
#include "Piece.h"

class BoardTiles {
private:
    float tileSize;
    std::vector<sf::Color> colors;
    std::vector<sf::RectangleShape> boardTiles;
    std::vector<std::vector<sf::Texture>> pieces;
public:
    BoardTiles(float, float, float, sf::Color, sf::Color);
    
    void drawBoard(sf::RenderWindow&);
};

#endif /* BoardTiles_h */
