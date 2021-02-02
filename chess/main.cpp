
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

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "Classes/BoardTiles.hpp"

int main(int, char const**)
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");
    window.setFramerateLimit(60);
    
    sf::Color blackColor(163, 82, 78);
    sf::Color whiteColor(242, 232, 231);
    
    float board_tile_size = 100;
    
    int current_x = 0;
    int current_y = 0;

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
        }

        window.clear();
        
        tiles.drawBoard(window);
        
        window.display();
    }

    return EXIT_SUCCESS;
}
