#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

bool AnalyseEvent(sf::Event event, M::Map& map);

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "CRAFT THE WORLD", sf::Style::Fullscreen);    
    sf::Event event;
    M::Map map;
    Hero first_hero("images/hero1.png", START_X, START_Y, HERO_WEIGHT, HERO_HEIGHT);

    while (window.isOpen())
    {   
       
        while (window.pollEvent(event))
        {   
            if (!AnalyseEvent(event, map)) {
                window.close();
                break;
            }
        }
        window.setView(map.getView());

        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}


bool AnalyseEvent(sf::Event event, M::Map& map) 
{   
    if (event.type == sf::Event::MouseWheelMoved)
        M::ScrollMap(map, event.mouseWheel.delta, event.mouseWheel.x, event.mouseWheel.y);
    if (event.type == sf::Event::MouseMoved)
    {
        std::cout << "new mouse x: " << event.mouseMove.x << std::endl;  
        std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
        std::cout << map.isSoft(event.mouseMove.x, event.mouseMove.y) << std::endl;
    }
    if (event.type == sf::Event::Closed)
        return false;
    return true;
}