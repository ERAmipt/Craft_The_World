#pragma once

enum class TypeAction {
	Stay = 0,
	GoingHome,

	MoveRight, MoveLeft,
	
	Jump, JumpRight, JumpLeft,
	Fall, FallRight, FallLeft, FallEnd,
	
	ClimbUp,
	ClimbDown,
	Attack
};
/*in case of adding new actions:
	add to ChangeAction
	add to CheckOpotrunityAction
	add to FindSprite and StartSprites.h in order to take new sprites

	if it's temporary action - check time in UpdateSprite

	in order to get access to user - add to CheckKeyboard() and CheckPermanentAction()
*/


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









const int BLOCK_X = 32; //waiting for delete
const int BLOCK_Y = 32; //waiting for delete


const int COUNT_SPRITES = 27;






const int START_X = 400;
const int START_Y = 500;

const int HERO_WEIGHT = 105;
const int HERO_HEIGHT = 130;



const float TIME_JUMPING = (float)13.0;
const float TIME_LANDING = (float)5.0;


const float SPEED_FRAME = (float)0.02;
const float SPEED_RIGHT = (float)0.35;
const float SPEED_UP = (float)0.6;

enum class TypeMaxHealth {
	HERO_START = 10,
	BISON = 10
};
