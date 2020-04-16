#pragma once
#include "Constants.h"
#include "Map.h"
#include <cassert>
#include <SFML/Graphics.hpp>







class Weapon 
{
public:
	virtual int GetDamage()
	{
		return damage_;
	}
private:
	const int damage_ = 0;
};
class WoodSword : public Weapon
{
public:
	int GetDamage() override
	{
		return damage_;
	}
private:
	const int damage_ = 2;
};
class ElderSword : public Weapon
{
public:
	int GetDamage() override
	{
		return damage_;
	}
private:
	const int damage_ = 4;
};
class SilverSword : public Weapon
{
public:
	int GetDamage() override
	{
		return damage_;
	}
private:
	const int damage_ = 6;
};





class Coord_Object
{
public:
	explicit Coord_Object(float new_x, float new_y, int weight_, int height_);

	void ChangePosition(TypeHeroAction new_action);

	//мне это не нравится, может все таки public?
	float GetX() const
	{
		return x_;
	}
	float GetY() const
	{
		return y_;
	}
	float GetSpeedX() const
	{
		return speed_x_;
	}
	float GetSppedY() const
	{
		return speed_y_;
	}
	int GetWeight() const
	{
		return weight_;
	}
	int GetHeight() const
	{
		return height_;
	}

	TypeHeroAction GetAction() const 
	{
		return action_;
	}

private:

	float x_;
	float y_;
	float speed_x_;
	float speed_y_;
	int weight_;
	int height_;

	TypeHeroAction action_;
	Coord_Object();
};
class Image_Object : public Coord_Object
{
public:

	Image_Object(std::string file, float new_x, float new_y, int weight_, int height_);
	sf::Sprite GetSprite();
	void ChangeSprite(TypeHeroAction new_action); //ПЛОХОЕ МЕСТО
	void UpdateSprite(); //update current_frame, 

private:

	sf::Image image_;
	sf::Texture texture_;
	sf::Sprite sprite_;
	double current_frame_;   //определенная картинка при каком-то движении, будет меняться со временем - отображать какую именно картинку
							 //использовать для рисования этого действия
};

class Hero : public Image_Object
{
public:

	Hero(std::string, float new_x, float new_y, int weight_, int height_);
	~Hero();

	int GetDamageWeapon();
	void ChangeWeapon(TypeWeapon typeweapon);
	void DoAction(TypeHeroAction new_action);  //we have to check it before, 

private:

	int health_;
	Weapon* weapon_;

	
};


















class Animal : public Coord_Object
{
public:
	Animal(float new_x, float new_y, int weight_, int height_);
	virtual int GetDamage() = 0; // it means returns the damage of that animal
	virtual bool ReceiveDamage(int) = 0; // it means get other damage and returns (is_alive())
	virtual void ChangeAction(TypeAnimalAction new_action) = 0;
	//т.к. мы наследуемся от координат, поэтому можем передавать в функции проверки на карте и просто указатель на животного
};
class Bison : public Animal
{
public:

	Bison(float new_x, float new_y, int weight_, int height_);

	int GetDamage() override;
	bool ReceiveDamage(int delivered_damage) override;
	void ChangeAction(TypeAnimalAction new_action) override;  //we have to check it before, 

private:
	int health_;
	TypeAnimalAction action_;
	const int damage_ = 2;
};
