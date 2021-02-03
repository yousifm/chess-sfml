//
// Created by Yousif Alebyary on 3/2/2021.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include <Piece.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class King : public Piece {
private:
    static inline bool init = false;
    static inline std::vector<sf::Texture> textures{2};
public:
    King(sf::Vector2<int> pos, int playerIdx) : Piece(pos, playerIdx, PieceTypes::King, textures[playerIdx]) {
        if (!init) {
            init = true;
            textures[0].loadFromFile(resourcePath() + "whiteKing.png");
            textures[1].loadFromFile(resourcePath() + "blackKing.png");
        }
    }

    std::vector<sf::Vector2<int>> getValidMoves() override {
        return {};
    }
};

#endif //CHESS_KING_H
