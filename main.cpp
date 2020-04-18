#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"


float MAIN_TIME = 0;
float CURRENT_TIME = 0;
bool AnalyseEvent(sf::Event event, M::Map& map, Hero& hero);

int main()
{
    sf::RenderWindow window(sf::VideoMode(M::WindowWidth, M::WindowHeight), "CRAFT THE WORLD", sf::Style::Fullscreen);    
    sf::Event event;
    M::Map map(0);
    Hero first_hero("images/Braid.png", START_X, START_Y, HERO_WEIGHT, HERO_HEIGHT, &CURRENT_TIME);


    sf::Clock main_clock;

    while (window.isOpen())
    {   
        //set new time
        CURRENT_TIME = main_clock.getElapsedTime().asMicroseconds() / 800;
        MAIN_TIME += CURRENT_TIME;
        main_clock.restart();
        //MAIN_TIME is global

        while (window.pollEvent(event))
        {   
            if (!AnalyseEvent(event, map, first_hero)) {
                window.close();
                break;
            }
        }
        //map.update(0, sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

        /*printf("X: %d\nY: %d\nSoft: %d\n", 
            map.AbsCoords(sf::Mouse::getPosition()).x,
            map.AbsCoords(sf::Mouse::getPosition()).y,
            map.isSoft(sf::Mouse::getPosition()));
            */

        //window.setView(map.view());
        window.clear();
        //window.draw(map);
        first_hero.Draw(window);
        window.display();
    }

    return 0;
}


bool AnalyseEvent(sf::Event event, M::Map& map, Hero& hero)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        hero.DoAction(TypeAction::MoveRight);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        hero.DoAction(TypeAction::MoveLeft);
    }
    else {
        hero.DoAction(TypeAction::Stay);
    }
    /*
    if (event.type == sf::Event::MouseWheelScrolled)
        map.update(event.mouseWheelScroll.delta, event.mouseWheelScroll.x, event.mouseWheelScroll.y);
    if (event.type == sf::Event::MouseMoved)
    {
        //std::cout << "new mouse x: " << event.mouseMove.x << std::endl;  
        //std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
    }
    */
    if (event.type == sf::Event::Closed)
        return false;
    return true;
}