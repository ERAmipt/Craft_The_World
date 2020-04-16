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
	health_(MAX_HEALTH_START),
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
void Hero::ChangeAction(HeroAction new_action)
{

}
