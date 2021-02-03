//
// Created by Yousif Alebyary on 3/2/2021.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


#include <Piece.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Knight : public Piece {
private:
    static inline bool init = false;
    static inline std::vector<sf::Texture> textures{2};
public:
    Knight(sf::Vector2<int> pos, int playerIdx) : Piece(pos, playerIdx, PieceTypes::Knight, textures[playerIdx]) {
        if (!init) {
            init = true;
            textures[0].loadFromFile(resourcePath() + "whiteKnight.png");
            textures[1].loadFromFile(resourcePath() + "blackKnight.png");
        }
    }

    std::vector<sf::Vector2<int>> getValidMoves() override {
        return {};
    }
};


#endif //CHESS_KNIGHT_H
