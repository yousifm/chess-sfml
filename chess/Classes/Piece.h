//
//  Piece.h
//  chess
//
//  Created by Yousif Alebyary on 2/2/2021.
//  Copyright © 2021 Yousif Alebyary. All rights reserved.
//

#ifndef Piece_h
#define Piece_h

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Piece {
public:
    std::vector<int> position;
    sf::Texture texture;
    
    Piece(std::vector<int> position, sf::Texture texture) : position(position), texture(texture) {}
};

#endif /* Piece_h */
