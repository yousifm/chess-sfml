//
//  BoardTiles.cpp
//  chess
//
//  Created by Yousif Alebyary on 2/2/2021.
//  Copyright © 2021 Yousif Alebyary. All rights reserved.
//

#include "BoardTiles.hpp"

#include <SFML/Graphics.hpp>

#include "../ResourcePath.hpp"

BoardTiles::BoardTiles(float startX, float startY, float tileSize, sf::Color whiteColor, sf::Color blackColor) :
    tileSize(tileSize),
    colors({
        whiteColor,
        blackColor
    })
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
    
    sf::Texture blackPawnTexture;
    blackPawnTexture.loadFromFile(resourcePath() + "blackPawn.png");
    sf::Texture blackBishopTexture;
    blackBishopTexture.loadFromFile(resourcePath() + "blackBishop.png");
    sf::Texture blackKnightTexture;
    blackKnightTexture.loadFromFile(resourcePath() + "blackKnight.png");
    sf::Texture blackQueenTexture;
    blackQueenTexture.loadFromFile(resourcePath() + "blackQueen.png");
    sf::Texture blackRookTexture;
    blackRookTexture.loadFromFile(resourcePath() + "blackRook.png");
    sf::Texture blackKingTexture;
    blackKingTexture.loadFromFile(resourcePath() + "blackKing.png");
    
    sf::Texture whitePawnTexture;
    whitePawnTexture.loadFromFile(resourcePath() + "whitePawn.png");
    sf::Texture whiteBishopTexture;
    whiteBishopTexture.loadFromFile(resourcePath() + "whiteBishop.png");
    sf::Texture whiteKnightTexture;
    whiteKnightTexture.loadFromFile(resourcePath() + "whiteKnight.png");
    sf::Texture whiteQueenTexture;
    whiteQueenTexture.loadFromFile(resourcePath() + "whiteQueen.png");
    sf::Texture whiteRookTexture;
    whiteRookTexture.loadFromFile(resourcePath() + "whiteRook.png");
    sf::Texture whiteKingTexture;
    whiteKingTexture.loadFromFile(resourcePath() + "whiteKing.png");
    
    
    pieces = std::vector<std::vector<sf::Texture>>(8, std::vector<sf::Texture>(8));
    
    for (int i = 0; i < 8; i++) {
        pieces[1][i] = blackPawnTexture;
        pieces[6][i] = whitePawnTexture;
    }
    
    pieces[0][0] = blackRookTexture;
    pieces[0][1] = blackKnightTexture;
    pieces[0][2] = blackBishopTexture;
    pieces[0][3] = blackQueenTexture;
    pieces[0][4] = blackKingTexture;
    pieces[0][5] = blackBishopTexture;
    pieces[0][6] = blackKnightTexture;
    pieces[0][7] = blackRookTexture;
    
    pieces[7][0] =  whiteRookTexture;
    pieces[7][1] = whiteKnightTexture;
    pieces[7][2] = whiteBishopTexture;
    pieces[7][3] = whiteQueenTexture;
    pieces[7][4] = whiteKingTexture;
    pieces[7][5] = whiteBishopTexture;
    pieces[7][6] = whiteKnightTexture;
    pieces[7][7] = whiteRookTexture;
}
    
void BoardTiles::drawBoard(sf::RenderWindow& window) {
    for (sf::RectangleShape rect : boardTiles) {
        window.draw(rect);
    }
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            sf::Sprite sprite(pieces[i][j]);
            sprite.setScale(2, 2);
            sprite.setPosition(j * 100, i * 100);
        
            window.draw(sprite);
        }
    }
}
