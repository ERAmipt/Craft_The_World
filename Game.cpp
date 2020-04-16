#include "Game.h"

Coord_Object::Coord_Object()
{
	assert(0);
}
Coord_Object::Coord_Object(float new_x, float new_y, int new_weight, int new_height):
	x_(new_x),
	y_(new_y),
	speed_x_(0),
	speed_y_(0),
	weight_(new_weight),
	height_(new_height)
{}






















Hero::Hero(float new_x, float new_y, int weight_, int height_):
	Coord_Object(new_x, new_y, weight_, height_),
	health_(static_cast<int>(TypeMaxHealth::HERO_START)),
	weapon_(new Weapon)
{}
Hero::~Hero()
{
	delete weapon_;
}
int Hero::GetDamageWeapon()
{
	return weapon_->GetDamage();
}
void Hero::ChangeWeapon(TypeWeapon typeweapon)
{
	switch (typeweapon)
	{
	case TypeWeapon::Nothing:
		weapon_ = new (weapon_) Weapon;
		break;
	case TypeWeapon::WoodSword:
		weapon_ = new (weapon_) WoodSword;
		break;
	case TypeWeapon::ElderSword:
		weapon_ = new (weapon_) ElderSword;
		break;
	case TypeWeapon::SilverSword:
		weapon_ = new (weapon_) SilverSword;
		break;
	default:
		assert(0);
		break;
	}
}
void Hero::ChangeAction(TypeHeroAction new_action)
{
	//проверка на карте

	action_ = new_action;
}








Animal::Animal(float new_x, float new_y, int weight_, int height_):
	Coord_Object(new_x, new_y, weight_, height_)
{}


Bison::Bison(float new_x, float new_y, int weight_, int height_):
	Animal(new_x, new_y, weight_, height_),
	health_(static_cast<int>(TypeMaxHealth::BISON)),
	action_(TypeAnimalAction::Stay)
{}
int Bison::GetDamage()
{
	return damage_;
}
bool Bison::ReceiveDamage(int delivered_damage)
{
	health_ -= delivered_damage;

	if (health_ < 0)
		return false;
	return true;
}
void Bison::ChangeAction(TypeAnimalAction new_action)
{
	//какая-то проверка в map

	action_ = new_action;
}