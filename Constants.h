#pragma once

enum class TypeAction {
	Stay = 0,
	GoingHome,
	MoveRight,
	MoveLeft,
	Jump, 
	Fall,
	ClimbUp,
	ClimbDown,
	Attack
};



enum class TypeWeapon {
	Nothing = 0,
	WoodSword,
	ElderSword,
	SilverSword, 
	GoldenSword
};
enum class TypeArmor {
	Nothing = 0,
	WoodArmor,
	ElderArmor,
	SilverArmor,
	GoldenArmor
};
enum class TypeAx {
	Nothing = 0,
	WoodAx,
	ElderAx,
	SilverAx,
	GoldenAx
};
enum class TypePickax {
	Nothing = 0,
	WoodPickax,
	ElderPickax,
	SilverPickax,
	GoldenPickax
};












const int BLOCK_X = 30;
const int BLOCK_Y = 30;
const int COUNT_BLOCKS_X_ = 198;
const int COUNT_BLOCKS_Y_ = 108;

const int START_X = 1000;
const int START_Y = 1000;

const int HERO_WEIGHT = 105;
const int HERO_HEIGHT = 140;



const float SPEED_FRAME = (float)0.1;
const float SPEED_RIGHT = (float)0.4;

enum class TypeMaxHealth {
	HERO_START = 10,
	BISON = 10
};
