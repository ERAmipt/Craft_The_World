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


//ВАЖНО ЕЩЕ:
//Пока выход из проги во вермя работы на Escape, НО проверь, работает ли прога, скорее всего нет... Есть пару версий как избежать этой ситуации
//1)Ты подстраиваешься и тогда https://www.youtube.com/watch?v=on7U-90gfrI делаешь здесь.
//2)Ты сам доставляешь прогу в рабочий файл в репозиторий и говоришь, что делать мне, просто у меня через NuGet еще раньше был поставлен
//У меня вот эта написанная прога работает(ну просто экран), я ее свзяал. НО: идет ли реально синхронизация кода , а именно скачка с гитхаба еще ж не проверено.
//Сообщи когда прочитаешь, уже что-то поделаешь, жду)

bool Event();
bool CheckKeyboard();
bool CheckMouse();


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "CRAFT THE WORLD");

    while (window.isOpen())
    {
        if (Event())
            window.close();



        window.clear();
        window.display();
    }

    return 0;
}



bool Event()
{
    if (CheckKeyboard() || CheckMouse())
        return true;

    return false;
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