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
#include "../ResourcePath.hpp"

enum class PieceTypes {
    King,
    Queen,
    Bishop,
    Rook,
    Pawn,
    Knight
};

class Piece {
public:
    int playerIdx;
    sf::Vector2<int> position;
    sf::Texture& texture;
    PieceTypes pieceType;
    
    Piece(sf::Vector2<int>, int, PieceTypes, sf::Texture&);
    virtual std::vector<sf::Vector2<int>> getValidMoves();
};

#endif /* Piece_h */
