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
	height_(new_height),

	action_(TypeHeroAction::Nothing)
{}
void Coord_Object::ChangePosition(TypeHeroAction new_action)
{
	if (action_ != new_action) {
		switch (action_)
		{
		case TypeHeroAction::Nothing:
			break;
		case TypeHeroAction::GoingHome:
			break;
		case TypeHeroAction::MoveRight:
			break;
		case TypeHeroAction::MoveLeft:
			break;
		case TypeHeroAction::Jump:
			break;
		case TypeHeroAction::Fall:
			break;
		case TypeHeroAction::ClimbUp:
			break;
		case TypeHeroAction::ClimbDown:
			break;
		case TypeHeroAction::Attack:
			break;
		default:
			break;
		}
	}
	else {
		x_ += speed_x_;
		y_ += speed_y_;
	}
}



Image_Object::Image_Object(std::string file, float new_x, float new_y, int weight, int height):
	Coord_Object(new_x, new_y, weight, height),
	image_(),
	texture_(),
	sprite_(),
	current_frame_(0)
{
	image_.loadFromFile(file);
	//setColorMask
	texture_.loadFromImage(image_);
	sprite_.setTexture(texture_);
	sprite_.setPosition(new_x, new_y);
}
sf::Sprite Image_Object::GetSprite()
{
	return sprite_;
}
void Image_Object::ChangeSprite(TypeHeroAction new_action)
{
	current_frame_ = 0;
	//начальный спрайт всавляем можно сделать enum из enum-ов, либо просто массив из sf::IntRect
	//который потом и вставляется в sprite_.setTextureRect(sf::IntRect)
	switch (new_action)
	{
	case TypeHeroAction::Nothing:
		break;
	case TypeHeroAction::GoingHome:
		break;
	case TypeHeroAction::MoveRight:
		break;
	case TypeHeroAction::MoveLeft:
		break;
	case TypeHeroAction::Jump:
		break;
	case TypeHeroAction::Fall:
		break;
	case TypeHeroAction::ClimbUp:
		break;
	case TypeHeroAction::ClimbDown:
		break;
	case TypeHeroAction::Attack:
		break;
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
void Hero::DoAction(TypeHeroAction new_action)
{
	//проверка на карте
	//return нудо TypeHeroAction, в котором будет заложено ЧТО делать надо персонажу

	//if в зависимости от action 
	
	this->ChangePosition(new_action);

	if (this->GetAction() != new_action) 
		this->ChangeSprite(new_action)
		;
	else
		this->UpdateSprite()
		;
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