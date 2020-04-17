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

	action_(TypeAction::Stay)
{}
void Coord_Object::ChangePosition(TypeAction new_action)
{
	if (action_ != new_action) {
		switch (action_)
		{
		case TypeAction::Stay:
			break;
		case TypeAction::GoingHome:
			break;
		case TypeAction::MoveRight:
			break;
		case TypeAction::MoveLeft:
			break;
		case TypeAction::Jump:
			break;
		case TypeAction::Fall:
			break;
		case TypeAction::ClimbUp:
			break;
		case TypeAction::ClimbDown:
			break;
		case TypeAction::Attack:
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
void Coord_Object::ChangeAction(TypeAction new_action)
{
	action_ = new_action;
}



Image_Object::Image_Object(std::string file, float new_x, float new_y, int weight, int height):
	Coord_Object(new_x, new_y, weight, height),
	image_(),
	texture_(),
	sprite_(),
	current_frame_(0)
{
	image_.loadFromFile(file);
	image_.createMaskFromColor(sf::Color(255, 255, 255));
	texture_.loadFromImage(image_);
	sprite_.setTexture(texture_);
	sprite_.setPosition(new_x, new_y);
}
sf::Sprite Image_Object::GetSprite()
{
	return sprite_;
}
void Image_Object::ChangeSprite(sf::IntRect&& new_rect)
{
	current_frame_ = 0;
	sprite_.setTextureRect(new_rect);
}
void Image_Object::UpdateSprite()
{
	//current_frame_ += time * �����������
	//sprite_.setTextureRect(sf::IntRect(  + ����������� * static_cast<int>(current_frame_), , , );
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
void Hero::DoAction(TypeAction new_action)
{
	//�������� �� �����
	//return ���� TypeHeroAction, � ������� ����� �������� ��� ������ ���� ���������

	//if � ����������� �� action 
	
	this->ChangePosition(new_action);

	if (this->GetAction() != new_action) {
		this->ChangeAction(new_action);
		this->ChangeSprite(std::move(FindSprite(new_action)));
	}
	else
		this->UpdateSprite();
}
sf::IntRect Hero::FindSprite(TypeAction new_action)
{
	switch (new_action)
	{
	case TypeAction::Stay:
		return Sprite_Hero_Stay;
		break;
	case TypeAction::GoingHome:
		break;
	case TypeAction::MoveRight:
		return Sprite_Hero_MoveRight;
		break;
	case TypeAction::MoveLeft:
		return Sprite_Hero_MoveLeft;
		break;
	case TypeAction::Jump:
		return Sprite_Hero_Jump;
		break;
	case TypeAction::Fall:
		return Sprite_Hero_Fall;
		break;
	case TypeAction::ClimbUp:
		break;
	case TypeAction::ClimbDown:
		break;
	case TypeAction::Attack:
		break;
	default:
		break;
	}
	std::cerr << "Action wasn't found!\n";
}







Animal::Animal(std::string file, float new_x, float new_y, int weight_, int height_):
	Image_Object(file, new_x, new_y, weight_, height_)
{}


//NOT DONE!!!!!-----------------------------------------------------------------------
Bison::Bison(std::string file, float new_x, float new_y, int weight_, int height_):
	Animal(file, new_x, new_y, weight_, height_),
	health_(static_cast<int>(TypeMaxHealth::BISON)),
	action_(TypeAction::Stay)
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
void Bison::ChangeAction(TypeAction new_action)
{
	//�����-�� �������� � map

	this->action_ = new_action;
}

//UNTIL THIS---------------------------------------------------------------------------