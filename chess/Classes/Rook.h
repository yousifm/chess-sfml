//
// Created by Yousif Alebyary on 3/2/2021.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include <Piece.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Rook : public Piece {
private:
    static inline bool init = false;
    static inline std::vector<sf::Texture> textures{2};
public:
    Rook(sf::Vector2<int> pos, int playerIdx) : Piece(pos, playerIdx, PieceTypes::Rook, textures[playerIdx]) {
        if (!init) {
            init = true;
            textures[0].loadFromFile(resourcePath() + "whiteRook.png");
            textures[1].loadFromFile(resourcePath() + "blackRook.png");
        }
    }

    std::vector<sf::Vector2<int>> getValidMoves() override {
        return {};
    }
};

#endif //CHESS_ROOK_H
