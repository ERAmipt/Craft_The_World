#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
bool AnalyseEvent(sf::Event event);
bool CheckKeyboard();
bool CheckMouse();

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "CRAFT THE WORLD", sf::Style::Fullscreen);
    sf::CircleShape shape(100.f);

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
        window.draw(shape);
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