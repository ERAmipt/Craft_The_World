#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

bool AnalyseEvent(sf::Event event);
bool CheckKeyboard();
bool CheckMouse();

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "CRAFT THE WORLD", sf::Style::Fullscreen);
    M::Map map;
    if (!map.load()) {
        std::cerr << "Can not load map. Check images folder";
        return -1;
    }

    while (window.isOpen())
    {   
        sf::Event event;
        while (window.pollEvent(event))
        {   
            if (!AnalyseEvent(event)) {
                window.close();
                break;
            }
        }


        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}


bool AnalyseEvent(sf::Event event) 
{
    if (event.type == sf::Event::Closed)
        return false;
    return true;
}

bool CheckKeyboard()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return true;



    return false;
}

bool CheckMouse()
{
    return false;
}