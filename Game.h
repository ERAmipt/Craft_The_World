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

	float get_x()
	{
		return x_;
	}
	float get_y()
	{
		return y_;
	}
	float get_speed_x()
	{
		return speed_x_;
	}
	float get_spped_y()
	{
		return speed_y_;
	}
	int get_weight()
	{
		return weight_;
	}
	int get_height()
	{
		return height_;
	}

private:

	float x_;
	float y_;
	float speed_x_;
	float speed_y_;
	int weight_;
	int height_;

	Coord_Object();
};

class Hero : public Coord_Object
{
public:

	Hero(float new_x, float new_y, int weight_, int height_);
	~Hero();

	int GetDamageWeapon();
	void ChangeWeapon(TypeWeapon typeweapon);
	void ChangeAction(HeroAction new_action);  //we have to check it before, 

private:
	int health_;
	HeroAction action_;
	Weapon* weapon_;
};


















class Animal : public Coord_Object
{
public:
	virtual int GetDamage() = 0; // it means returns the damage of that animal
	virtual bool ReceiveDamage() = 0; // it means get other damage and returns (is_alive())
	//т.к. мы наследуемся от координат, поэтому можем передавать в функции проверки на карте и просто указатель на животного
};
class Bison : public Animal
{
public:

	Bison(float new_x, float new_y, float weight_, float height_);
	~Bison();

	virtual int GetDamage() override;
	virtual bool ReceiveDamage() override;
	void ChangeAction(AnimalAction new_action);  //we have to check it before, 

private:
	int health_;
	AnimalAction action_;
	int damage_;
};
