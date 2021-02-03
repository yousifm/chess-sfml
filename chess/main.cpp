
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <vector>

#include <SFML/Graphics.hpp>

#include "Classes/BoardTiles.hpp"

int main(int, char const**)
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");
    window.setFramerateLimit(60);
    
    sf::Color blackColor(163, 82, 78);
    sf::Color whiteColor(242, 232, 231);

    BoardTiles tiles(0, 0, 100, whiteColor, blackColor);
    
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            if (event.type == sf::Event::MouseButtonPressed) {
                int mouseX = sf::Mouse::getPosition(window).x;
                int mouseY = sf::Mouse::getPosition(window).y;
                
                tiles.mouseClick(mouseX, mouseY);
            }
        }

        window.clear();
        
        tiles.drawBoard(window);
        
        window.display();
    }

    return EXIT_SUCCESS;
}
