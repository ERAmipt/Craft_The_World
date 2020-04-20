#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"


float MAIN_TIME = 0;
float CURRENT_TIME = 0;

bool AnalyseEvent(sf::Event& event, M::Map& map);
bool CheckKeyboard(Hero& hero, const M::Map& map);
bool CheckPermanentActions(Hero& hero, const M::Map& map);
TypeAction RecordinateAction(TypeAction hero_action, TypeAction new_action);

int main()
{
    sf::RenderWindow window(sf::VideoMode(M::WindowWidth, M::WindowHeight), "CRAFT THE WORLD");    
    sf::Event event;
    M::Map map(0);
    Hero first_hero("images/Braid.png", START_X, START_Y, HERO_WEIGHT, HERO_HEIGHT, &CURRENT_TIME);


    sf::Clock main_clock;

    while (window.isOpen())
    {   
        //set new time
        CURRENT_TIME = (float)main_clock.getElapsedTime().asMicroseconds() / 800;
        MAIN_TIME += CURRENT_TIME;
        main_clock.restart();
        //MAIN_TIME is global

        while (window.pollEvent(event))
        {   
            if (!AnalyseEvent(event, map)) {
                window.close();
                break;
            }
        }
        if (!CheckKeyboard(first_hero, map)) {
            window.close();
        }

        map.update(0, sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

        /*printf("X: %d\nY: %d\nSoft: %d\n", 
            map.AbsCoords(sf::Mouse::getPosition()).x,
            map.AbsCoords(sf::Mouse::getPosition()).y,
            map.isSoft(sf::Mouse::getPosition()));
            */

        window.setView(map.view());
        window.clear();
        window.draw(map);
        first_hero.Draw(window);
        window.display();
    }

    return 0;
}


bool AnalyseEvent(sf::Event& event, M::Map& map)
{
    if (event.type == sf::Event::MouseWheelScrolled)
        map.update(event.mouseWheelScroll.delta, event.mouseWheelScroll.x, event.mouseWheelScroll.y);
    if (event.type == sf::Event::MouseMoved)
    {
        //std::cout << "new mouse x: " << event.mouseMove.x << std::endl;  
        //std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
    }
    
    if (event.type == sf::Event::Closed)
        return false;
    return true;
}


bool CheckKeyboard(Hero& hero, const M::Map& map) 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return false;

    if (CheckPermanentActions(hero, map))
        return true;


    TypeAction new_action = TypeAction::Stay;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            new_action = TypeAction::JumpRight;
        else
            new_action = TypeAction::MoveRight;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            new_action = TypeAction::JumpLeft;
        else
            new_action = TypeAction::MoveLeft;
    }

    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        new_action = TypeAction::Jump;
    }

    new_action = RecordinateAction(hero.GetAction(), new_action);
    
    hero.DoAction(hero.CheckOportunityAction(new_action, map));

    return true;
}

bool CheckPermanentActions(Hero& hero, const M::Map& map)
{
    TypeAction current_action = hero.GetAction();
    if (current_action == TypeAction::Jump || current_action == TypeAction::JumpLeft || current_action == TypeAction::JumpRight) {

        if (hero.IsEmptyUp(map) && hero.IsEmptyLeft(map) && hero.IsEmptyRight(map)) {
            hero.ContinueAction();
        }
        else {
            hero.DoAction(TypeAction::Fall);
        }
        return true;

    }
    if (current_action == TypeAction::FallEnd) {
        hero.ContinueAction();
        return true;
    }
    return false;
}

TypeAction RecordinateAction(TypeAction hero_action, TypeAction new_action)
{
    if (hero_action == TypeAction::Fall || hero_action == TypeAction::FallRight || hero_action == TypeAction::FallLeft) {
        if (new_action == TypeAction::MoveLeft)
            return TypeAction::FallLeft;
        if (new_action == TypeAction::MoveRight)
            return TypeAction::FallRight;
    }
    return new_action;
}