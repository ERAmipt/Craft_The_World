#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
//мы должны продумать соглашение о названиях:
//что я предлагаю: enum class называть допустим с какаого-то константного слова - допустим Type... (TypeWeapon, TypeAction и т.д.)
//Насчет букв маленьких и больших - допустим, ф-ии с большими буквами названия (CheckAction, DoOperation...)
//А вот переменные например наоборот can_i_do_this, sprite_hero and so on...
//Важно придумать как мы будем договариваться о том, как чекать апдейты - либо говорить что должно готовиться и создать отдельный файл,
//в котором и будем писать типо Map в Map.h сделано с гравитацией, либо просто коментить кучу кода, но это все равно хуже

//поэтому ЗАГЛЯНИ В Updates.txt (с вижуалки открой)

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