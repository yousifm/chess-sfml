//
//  Pawn.hpp
//  chess
//
//  Created by Yousif Alebyary on 3/2/2021.
//  Copyright © 2021 Yousif Alebyary. All rights reserved.
//

#ifndef Pawn_h
#define Pawn_h

#include <Piece.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Pawn : public Piece {
private:
    static inline bool init = false;
    static inline std::vector<sf::Texture> textures{2};

    bool hasMoved = false;
public:
    Pawn(sf::Vector2<int> pos, int playerIdx) : Piece(pos, playerIdx, PieceTypes::Pawn, textures[playerIdx]) {
        if (!init) {
            init = true;
            textures[0].loadFromFile(resourcePath() + "whitePawn.png");
            textures[1].loadFromFile(resourcePath() + "blackPawn.png");
        }
    }

    std::vector<sf::Vector2<int>> getValidMoves() override {
        return {};
    }
};

#endif /* Pawn_h */
