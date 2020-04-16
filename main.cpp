#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
//�� ������ ��������� ���������� � ���������:
//��� � ���������: enum class �������� �������� � �������-�� ������������ ����� - �������� Type... (TypeWeapon, TypeAction � �.�.)
//������ ���� ��������� � ������� - ��������, �-�� � �������� ������� �������� (CheckAction, DoOperation...)
//� ��� ���������� �������� �������� can_i_do_this, sprite_hero and so on...
//����� ��������� ��� �� ����� �������������� � ���, ��� ������ ������� - ���� �������� ��� ������ ���������� � ������� ��������� ����,
//� ������� � ����� ������ ���� Map � Map.h ������� � �����������, ���� ������ ��������� ���� ����, �� ��� ��� ����� ����

//������� ������� � Updates.txt (� �������� ������)


//����� ���:
//���� ����� �� ����� �� ����� ������ �� Escape, �� �������, �������� �� �����, ������ ����� ���... ���� ���� ������ ��� �������� ���� ��������
//1)�� ��������������� � ����� https://www.youtube.com/watch?v=on7U-90gfrI ������� �����.
//2)�� ��� ����������� ����� � ������� ���� � ����������� � ��������, ��� ������ ���, ������ � ���� ����� NuGet ��� ������ ��� ���������
//� ���� ��� ��� ���������� ����� ��������(�� ������ �����), � �� ������. ��: ���� �� ������� ������������� ���� , � ������ ������ � ������� ��� � �� ���������.
//������ ����� ����������, ��� ���-�� ���������, ���)

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