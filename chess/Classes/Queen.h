//
// Created by Yousif Alebyary on 3/2/2021.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include <Piece.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Queen : public Piece {
private:
    static inline bool init = false;
    static inline std::vector<sf::Texture> textures{2};
public:
    Queen(sf::Vector2<int> pos, int playerIdx) : Piece(pos, playerIdx, PieceTypes::Queen, textures[playerIdx]) {
        if (!init) {
            init = true;
            textures[0].loadFromFile(resourcePath() + "whiteQueen.png");
            textures[1].loadFromFile(resourcePath() + "blackQueen.png");
        }
    }

    std::vector<sf::Vector2<int>> getValidMoves() override {
        return {};
    }
};

#endif //CHESS_QUEEN_H
