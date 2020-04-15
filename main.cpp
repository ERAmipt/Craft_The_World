#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"


bool CheckKeyboard();


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "CRAFT THE WORLD");

    while (window.isOpen())
    {
        if (CheckKeyboard())
            window.close();



        window.clear();
        window.display();
    }

    return 0;
}



bool Event()
{

}

bool CheckKeyboard()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return true;



    return false;
}