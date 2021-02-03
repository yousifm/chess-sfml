//
// Created by Yousif Alebyary on 3/2/2021.
//
#include "Piece.hpp"

Piece::Piece(sf::Vector2<int> pos , int playerIdx, PieceTypes type, sf::Texture& texture) :
    position(pos), playerIdx(playerIdx), pieceType(type), texture(texture)
{};

std::vector<sf::Vector2<int>> Piece::getValidMoves() {return {};}
