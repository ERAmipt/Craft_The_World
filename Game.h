#pragma once
#include "Constants.h"
#include "Start_Sprites.h"
#include "Map.h"
#include <cassert>
#include <SFML/Graphics.hpp>



//Realisation in -> Game.cpp 



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
	explicit Coord_Object(float new_x, float new_y, int weight_, int height_, float* current_time);

	void ChangeAction(TypeAction new_action);  //use Hero::ChangeActionTo instead if it's possible - more safety! I will close the opportinity to get this func soon!!
	void DisplaceCoordinates();

	bool IsEmptyRight(const M::Map& map);
	bool IsEmptyLeft(const M::Map& map);
	bool IsEmptyUp(const M::Map& map);
	bool IsEmptyDown(const M::Map& map);
	TypeAction CheckOportunityAction(TypeAction new_action, const M::Map& map);


	float GetX() const { return x_; }
	float GetY() const { return y_; }
	float GetSpeedX() const { return speed_x_; }
	float GetSppedY() const { return speed_y_; }
	int GetWeight() const { return weight_; }
	int GetHeight() const { return height_; }
	TypeAction GetAction() const { return action_; }

protected:

	float x_;
	float y_;
	float speed_x_;
	float speed_y_;
	int weight_;
	int height_;

	float* current_time_;
	TypeAction action_;
	Coord_Object();
};




class Image_Object : public Coord_Object
{
public:

	Image_Object(std::string file, float new_x, float new_y, int weight_, int height_, float* current_time);
	
	sf::Sprite GetSprite() { return sprite_; }
	
	const int FindSprite(TypeAction new_action) const;
	void ChangeSprite(TypeAction new_action);
	void ChangeImage(TypeAction new_action);
	
	void UpdateSprite();
	void DisplaceSprite();

	void ChangeActionTo(TypeAction new_action);

	void Draw(sf::RenderWindow& window);

private:

	sf::Image image_;
	sf::Texture texture_;
	sf::Sprite sprite_;
	int number_sprite_;
	double current_frame_;  
};






class Hero : public Image_Object
{
public:

	Hero(std::string, float new_x, float new_y, int weight_, int height_, float* current_time);
	~Hero();

	int GetDamageWeapon() { return weapon_->GetDamage(); }
	void ChangeWeapon(TypeWeapon typeweapon);

	void DoAction(TypeAction new_action);  //we have to check it before, 
	void ContinueAction();
	void CorrectAction(TypeAction new_action); //not do it so frequantly

private:

	int health_;
	Weapon* weapon_;

	
};

















/*
class Animal : public Image_Object
{
public:
	Animal(std::string file, float new_x, float new_y, int weight_, int height_);
	virtual int GetDamage() = 0; // it means returns the damage of that animal
	virtual bool ReceiveDamage(int) = 0; // it means get other damage and returns (is_alive())
	virtual void ChangeAction(TypeAction new_action) = 0;
	//т.к. мы наследуемся от координат, поэтому можем передавать в функции проверки на карте и просто указатель на животного
};
class Bison : public Animal
{
public:

	Bison(std::string file, float new_x, float new_y, int weight_, int height_);

	int GetDamage() override;
	bool ReceiveDamage(int delivered_damage) override;
	void ChangeAction(TypeAction new_action) override;  //we have to check it before, 

private:
	int health_;
	TypeAction action_;
	const int damage_ = 2;
};
*/