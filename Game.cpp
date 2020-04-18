#include "Game.h"

Coord_Object::Coord_Object() {}
Coord_Object::Coord_Object(float new_x, float new_y, int new_weight, int new_height, float* current_time) :
    x_(new_x),
    y_(new_y),
    speed_x_(0),
    speed_y_(0),
    weight_(new_weight),
    height_(new_height),

    current_time_(current_time),
    action_(TypeAction::Stay)
{}
void Coord_Object::ChangeAction(TypeAction new_action)
{
    action_ = new_action;

    switch (action_)
    {
    case TypeAction::Stay:
        speed_x_ = 0.0;
        speed_y_ = 0.0;
        break;
    case TypeAction::GoingHome:
        break;
    case TypeAction::MoveRight:
        speed_x_ = SPEED_RIGHT;
        speed_y_ = 0;
        break;
    case TypeAction::MoveLeft:
        speed_x_ = -1 * SPEED_RIGHT;
        speed_y_ = 0;
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
void Coord_Object::DisplaceCoordinates()
{
    x_ += speed_x_;
    y_ += speed_y_;
}





Image_Object::Image_Object(std::string file, float new_x, float new_y, int weight, int height, float* current_time) :
    Coord_Object(new_x, new_y, weight, height, current_time),
    image_(),
    texture_(),
    sprite_(),
    number_sprite_(0),
    current_frame_(0)
{
    image_.loadFromFile(file);
    image_.createMaskFromColor(sf::Color(255, 255, 255));
    texture_.loadFromImage(image_);
    sprite_.setTexture(texture_);
    sprite_.setPosition(new_x, new_y);
}
void Image_Object::ChangeSprite(const int new_sprite)
{
    current_frame_ = 0;
    number_sprite_ = new_sprite;
    sprite_.setTextureRect(Sprites_Hero[number_sprite_][0]);
}
void Image_Object::UpdateSprite()
{
    current_frame_ += SPEED_FRAME;
    if ((int)current_frame_ > 26)
        current_frame_ -= 26;

    sprite_.setTextureRect(Sprites_Hero[number_sprite_][(int)current_frame_]);
}
void Image_Object::Draw(sf::RenderWindow& window)
{
    window.draw(sprite_);
}
void Image_Object::DisplaceSprite()
{
    sprite_.setPosition(this->x_, this->y_);
}
const int Image_Object::FindSprite(TypeAction new_action) const
{
    switch (new_action)
    {
    case TypeAction::Stay:
        return Sprites_Hero_Stay;
        break;
    case TypeAction::GoingHome:
        break;
    case TypeAction::MoveRight:
        return Sprites_Hero_MoveRight;
        break;
    case TypeAction::MoveLeft:
        return Sprites_Hero_MoveLeft;
        break;
    case TypeAction::Jump:
        return Sprites_Hero_Jump;
        break;
    case TypeAction::Fall:
        return Sprites_Hero_Fall;
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










Hero::Hero(std::string file, float new_x, float new_y, int weight_, int height_, float* current_time) :
    Image_Object(file, new_x, new_y, weight_, height_, current_time),
    health_(static_cast<int>(TypeMaxHealth::HERO_START)),
    weapon_(new Weapon)
{}
Hero::~Hero()
{
    delete weapon_;
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
        break;
    }
}
void Hero::DoAction(TypeAction new_action)
{
    //�������� �� �����
    //return ���� TypeHeroAction, � ������� ����� �������� ��� ������ ���� ���������

    //if � ����������� �� action

    if (this->action_ != new_action) {
        this->ChangeAction(new_action);
        this->ChangeSprite(this->FindSprite(new_action));
    }
    else {
        this->UpdateSprite();
    }

    DisplaceCoordinates();
    DisplaceSprite();
}






/*
Animal::Animal(std::string file, float new_x, float new_y, int weight_, int height_):
Image_Object(file, new_x, new_y, weight_, height_)
{}


//NOT DONE!!!!!---------------------------------------------------------------------�
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

//UNTIL THIS-------------------------------------------------------------------------�
*/