//
// Created by Yousif Alebyary on 3/2/2021.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include <Piece.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Bishop : public Piece {
private:
    static inline bool init = false;
    static inline std::vector<sf::Texture> textures{2};
public:
    Bishop(sf::Vector2<int> pos, int playerIdx) : Piece(pos, playerIdx, PieceTypes::Bishop, textures[playerIdx]) {
        if (!init) {
            init = true;
            textures[0].loadFromFile(resourcePath() + "whiteBishop.png");
            textures[1].loadFromFile(resourcePath() + "blackBishop.png");
        }
    }

    std::vector<sf::Vector2<int>> getValidMoves() override {
        return {};
    }
};


#endif //CHESS_BISHOP_H
