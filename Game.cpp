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

//use ChangeActionTo instead!!!
void Coord_Object::ChangeAction(TypeAction new_action)
{
    action_ = new_action;

    switch (action_)
    {
    case TypeAction::Stay:
        speed_x_ = 0.0;
        speed_y_ = 0.0;
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
        speed_x_ = 0;
        speed_y_ = -SPEED_UP;
        break;
    case TypeAction::JumpLeft:
        speed_x_ = -SPEED_RIGHT;
        speed_y_ = -SPEED_UP;
        break;
    case TypeAction::JumpRight:
        speed_x_ = SPEED_RIGHT;
        speed_y_ = -SPEED_UP;
        break;


    case TypeAction::Fall:
        speed_x_ = 0;
        speed_y_ = SPEED_UP;
        break;
    case TypeAction::FallRight:
        speed_x_ = SPEED_RIGHT;
        speed_y_ = SPEED_UP;
        break;
    case TypeAction::FallLeft:
        speed_x_ = -SPEED_RIGHT;
        speed_y_ = SPEED_UP;
        break;
    case TypeAction::FallEnd:
        speed_x_ = 0;
        speed_y_ = 0;
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
//Attention!!!

void Coord_Object::DisplaceCoordinates()
{
    x_ += speed_x_ * (*current_time_);
    y_ += speed_y_ * (*current_time_);
}

//Should be in M:: space I think and easy to get using only Coord_Hero*----
bool Coord_Object::IsEmptyRight(const M::Map& map)
{
    //x_ and y_ are the right-up coordinates

    int current_y = int(y_);
    int current_x = int(x_ + weight_);
    //constants in Constants.h
    for (int i = 0; i < height_ / BLOCK_Y; ++i) {
        if (!map.isSoft(current_x, current_y))
            return false;

        current_y += BLOCK_Y;
    }
    //checking for the opposite boundary of hero
    if (!map.isSoft(current_x, int(y_ + height_)))
        return false;
    
    return true;
}
bool Coord_Object::IsEmptyLeft(const M::Map& map)
{
    int current_y = int(y_);

    for (int i = 0; i < height_ / BLOCK_Y; ++i) {
        if (!map.isSoft(int(x_), current_y))
            return false;
        current_y += BLOCK_Y;
    }
    if (!map.isSoft(int(x_), int(y_ + height_)))
        return false;

    return true;
}
bool Coord_Object::IsEmptyUp(const M::Map& map)
{
    int current_x = int(x_);
    for (int i = 0; i < weight_ / BLOCK_X; ++i) {
        if (!map.isSoft(current_x, int(y_)))
            return false;
        current_x += BLOCK_X;
    }
    if (!map.isSoft(int(x_ + weight_), int(y_)))
        return false;
    return true;
}
bool Coord_Object::IsEmptyDown(const M::Map& map)
{
    int current_x = int(x_);
    int current_y = int(y_ + height_);

    for (int i = 0; i < weight_ / BLOCK_X; ++i) {
        if (!map.isSoft(current_x, current_y))
            return false;
        current_x += BLOCK_X;
    }
    if (!map.isSoft(int(x_ + weight_), current_y))
        return false;

    return true;
}
//------------------------------------------------------------------------

TypeAction Coord_Object::CheckOportunityAction(TypeAction new_action, const M::Map& map)
{
    if (IsEmptyDown(map)) {
        if (new_action == TypeAction::MoveRight || new_action == TypeAction::FallRight) {
            
            if (!IsEmptyRight(map))
                return TypeAction::Fall;
            return TypeAction::FallRight;

        }
        else if (new_action == TypeAction::MoveLeft || new_action == TypeAction::FallLeft) {

            if (!IsEmptyLeft(map))
                return TypeAction::Fall;
            return TypeAction::FallLeft;

        }
        else {
            return TypeAction::Fall;
        }
    }
    switch (new_action)
    {
    case TypeAction::MoveRight:
        if (IsEmptyRight(map))
            return TypeAction::MoveRight;
        else
            return TypeAction::Stay;
        break;
    case TypeAction::MoveLeft:
        if (IsEmptyLeft(map))
            return TypeAction::MoveLeft;
        else
            return TypeAction::Stay;
        break;


    case TypeAction::Jump:
        if (IsEmptyUp(map)) 
            return TypeAction::Jump;
        else
            return TypeAction::Stay;
        break;
    case TypeAction::JumpRight:
        if (IsEmptyRight(map) && IsEmptyUp(map))
            return TypeAction::JumpRight;
        else
            return TypeAction::Stay;
        break;
    case TypeAction::JumpLeft:
        if (IsEmptyLeft(map) && IsEmptyUp(map))
            return TypeAction::JumpLeft;
        else
            return TypeAction::Stay;
        break;


    case TypeAction::ClimbUp:
        break;
    case TypeAction::ClimbDown:
        break;
    case TypeAction::Attack:
        break;
    }

    return TypeAction::Stay;
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
void Image_Object::ChangeActionTo(TypeAction new_action)
{
    ChangeAction(new_action);
    ChangeSprite(FindSprite(new_action));
}

void Image_Object::UpdateSprite()
{
    current_frame_ += SPEED_FRAME * (*current_time_);

    if (this->action_ == TypeAction::Jump && current_frame_ > TIME_JUMPING) {
        ChangeActionTo(TypeAction::Fall);
        return;
    }
    if (this->action_ == TypeAction::FallEnd && current_frame_ > TIME_LANDING) {
        ChangeActionTo(TypeAction::Stay);
        return;
    }


    if ((int)current_frame_ > COUNT_SPRITES - 1)
        current_frame_ -= COUNT_SPRITES - 1;

    sprite_.setTextureRect(Sprites_Hero[number_sprite_][(int)current_frame_]);
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


    case TypeAction::MoveRight:
        return Sprites_Hero_MoveRight;
        break;
    case TypeAction::MoveLeft:
        return Sprites_Hero_MoveLeft;
        break;
    

    case TypeAction::Jump:
        return Sprites_Hero_Jump;
        break;
    case TypeAction::JumpLeft:
        return Sprites_Hero_JumpLeft;
        break;
    case TypeAction::JumpRight:
        return Sprites_Hero_JumpRight;
        break;


    case TypeAction::Fall:
        return Sprites_Hero_Fall;
        break;
    case TypeAction::FallLeft:
        return Sprites_Hero_FallLeft;
        break;
    case TypeAction::FallRight:
        return Sprites_Hero_FallRight;
        break;
    case TypeAction::FallEnd:
        return Sprites_Hero_FallEnd;
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
    return 0;
}

void Image_Object::Draw(sf::RenderWindow& window)
{
    window.draw(sprite_);
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

void Hero::DoAction(TypeAction new_action)
{
    if (this->action_ != new_action) {
        ChangeActionTo(new_action);
    }
    else {
        this->UpdateSprite();
    }

    DisplaceCoordinates();
    DisplaceSprite();
}
void Hero::ContinueAction()
{
    this->UpdateSprite();
    this->DisplaceSprite();
    this->DisplaceCoordinates();
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






/*
Animal::Animal(std::string file, float new_x, float new_y, int weight_, int height_):
Image_Object(file, new_x, new_y, weight_, height_)
{}


//NOT DONE!!!!!---------------------------------------------------------------------Ч
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
//кака€-то проверка в map

this->action_ = new_action;
}

//UNTIL THIS-------------------------------------------------------------------------Ч
*/