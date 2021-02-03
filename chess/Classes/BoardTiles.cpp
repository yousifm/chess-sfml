//
//  BoardTiles.cpp
//  chess
//
//  Created by Yousif Alebyary on 2/2/2021.
//  Copyright © 2021 Yousif Alebyary. All rights reserved.
//

#include "BoardTiles.hpp"

#include <SFML/Graphics.hpp>

BoardTiles::BoardTiles(float startX, float startY, float tileSize, sf::Color whiteColor, sf::Color blackColor) :
    tileSize(tileSize),
    colors({
        whiteColor,
        blackColor
    }),
    turn(0)
{
    int color_idx;
    int current_x = startX;
    int current_y = startY;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            color_idx = (i + j) % 2;

            sf::RectangleShape rect;
            rect.setFillColor(colors[color_idx]);
            rect.setPosition(current_x, current_y);
            rect.setSize({tileSize, tileSize});
            
            boardTiles.push_back(rect);
            
            current_x += tileSize;
        }
        
        current_x = startX;
        current_y += tileSize;
    }

    for (int i = 0; i < 8; i++) {
        pieces.push_back(Pawn({i, 1}, 1));
        pieces.push_back(Pawn({i, 6}, 0));
    }

    pieces.push_back(Rook({0, 0}, 1));
    pieces.push_back(Rook({7, 0}, 1));
    pieces.push_back(Rook({0, 7}, 0));
    pieces.push_back(Rook({7, 7}, 0));

    pieces.push_back(Knight({1, 0}, 1));
    pieces.push_back(Knight({6, 0}, 1));
    pieces.push_back(Knight({1, 7}, 0));
    pieces.push_back(Knight({6, 7}, 0));

    pieces.push_back(Bishop({2, 0}, 1));
    pieces.push_back(Bishop({5, 0}, 1));
    pieces.push_back(Bishop({2, 7}, 0));
    pieces.push_back(Bishop({5, 7}, 0));

    pieces.push_back(King({4, 0}, 1));
    pieces.push_back(King({4, 7}, 0));

    pieces.push_back(Queen({3, 0}, 1));
    pieces.push_back(Queen({3, 7}, 0));
}
    
void BoardTiles::drawBoard(sf::RenderWindow& window) {
    for (sf::RectangleShape rect : boardTiles) {
        window.draw(rect);
    }
    
    for (auto& piece : pieces) {
        printf("X: %d Y: %d\n", piece.position.x, piece.position.y);
        sf::Sprite sprite(piece.texture);
        sprite.setScale(2, 2);
        sprite.setPosition(piece.position.x * tileSize, piece.position.y * tileSize);
        window.draw(sprite);
    }
}

void BoardTiles::mouseClick(float mouseX, float mouseY) {
    int j = mouseY / tileSize;
    int i = mouseX / tileSize;
    
    printf("%d %d\n", i, j);
}
