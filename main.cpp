#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"


double MAIN_TIME = 0;
double CURRENT_TIME = 0;
bool AnalyseEvent(sf::Event event);

int main()
{
    sf::RenderWindow window(sf::VideoMode(M::WindowWidth, M::WindowHeight), "CRAFT THE WORLD", sf::Style::Fullscreen);    
    sf::Event event;
    M::Map map(0);
   // Hero first_hero("images/heroes.png", START_X, START_Y, HERO_WEIGHT, HERO_HEIGHT);


    sf::Clock main_clock;

    while (window.isOpen())
    {   
        //set new time
        //CURRENT_TIME = main_clock.getElapsedTime().asMicroseconds();
        //MAIN_TIME += CURRENT_TIME;
        //main_clock.restart();
        //MAIN_TIME is global

        while (window.pollEvent(event))
        {   
            if (!AnalyseEvent(event)) {
                window.close();
                break;
            }
        }
        map.update(0, sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
        window.setView(map.view());
        std::cout << map.isSoft(sf::Mouse::getPosition()) << "\n";

        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}


bool AnalyseEvent(sf::Event event) 
{   
    if (event.type == sf::Event::MouseMoved)
    {
        //std::cout << "new mouse x: " << event.mouseMove.x << std::endl;  
        //std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
    }
    if (event.type == sf::Event::Closed)
        return false;
    return true;
}