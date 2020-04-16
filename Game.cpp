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
void Coord_Object::ChangeCoord(float new_x, float new_y)
{
	x_ = new_x;
	y_ = new_y;
}
void Coord_Object::ChangeSpeed(float speed_x, float speed_y)
{
	speed_x_ = speed_x;
	speed_y_ = speed_y;
}
void Coord_Object::ChangeCoordSpeed(float new_x, float new_y, float speed_x, float spped_y)
{
	x_ = new_x;
	y_ = new_y;
	speed_x_ = speed_x;
	speed_y_ = spped_y;
}



Image_Object::Image_Object(std::string file, float new_x, float new_y, int weight, int height):
	Coord_Object(new_x, new_y, weight, height),
	texture_(),
	sprite_(),
	current_frame_(0)
{}
sf::Sprite Image_Object::GetSprite()
{
	return sprite_;
}
void Image_Object::ChangeSprite(TypeHeroAction new_action)
{
	current_frame_ = 0;
	switch (new_action) //начальный спрайт всавляем можно сделать enum из enum-ов, либо просто массив из sf::IntRect
		                //который потом и вставляется в sprite_.setTextureRect(sf::IntRect)
	{
	default:
		break;
	}
}
void Image_Object::UpdateSprite()
{
	//current_frame_ += time * коэффициент
	//sprite_.setTextureRect(sf::IntRect(  + коэффициент * static_cast<int>(current_frame_), , , );
}





















Hero::Hero(std::string file, float new_x, float new_y, int weight_, int height_):
	Image_Object(file, new_x, new_y, weight_, height_),
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

	if (action_ != new_action) {
		action_ = new_action;
		this->ChangeSprite(action_);
		this->ChangeSpeed(action_);
	}
	else
		this->UpdateSprite();

	switch (action_) {
	case TypeHeroAction::MoveLeft:
		this->ChangeCoord(action_);
	default:
		break;
	}
	//if в зависимости от action 
	//
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