#pragma once
enum class TypeHeroAction {
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
enum class TypeAnimalAction {
	Stay = 0,
	GoRight,
	GoLeft,
	GoUp,
	GoDown,
	Attack
};


enum class TypeAnimal {
	Nothing = 0,
	Bison,
	Boar,
	Monster
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






//эти константы на тебе
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
//вот они были для map, теперь надо вставлять Tilemap








const int BLOCK_X = 30;
const int BLOCK_Y = 30;
const int COUNT_BLOCKS_X_ = 198;
const int COUNT_BLOCKS_Y_ = 108;


enum class TypeMaxHealth {
	HERO_START = 10,
	BISON = 10
};
