#pragma once
#define LOLOLOL 5
enum class HeroAction {
	Nothing = 0,
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

enum class StatusBlock {
	Empty = 0,
	Ground
};
enum class StatusDrawing {
	Nothing = 0,
	Sky1,
	Sky2,
	Ground1,
	Ground2
};
enum class BusySide {
	Empty = 0,
	Rigth, Left, Up, Down,
	RightUp, RightDown,
	LeftUp, LeftDown
};









const int BLOCK_X = 30;
const int BLOCK_Y = 30;
const int COUNT_BLOCKS_X_ = 198;
const int COUNT_BLOCKS_Y_ = 108;

const int MAX_HEALTH_START = 10;
