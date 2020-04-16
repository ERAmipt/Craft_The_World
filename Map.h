#pragma once
/*
namespace M {
	class Block
	{
	public:

		Block();
		explicit Block(StatusBlock new_status, StatusDrawing new_status_drawing, sf::Texture texture, sf::IntRect rect, float coord_x, float coord_y);

		sf::Sprite GetBlock();
		void ChangeBlock(sf::IntRect, StatusBlock new_status, StatusDrawing new_status_drawing);
		bool isEmpty();

	private:

		sf::Sprite sprite_;
		StatusBlock status_block_;
		StatusDrawing status_drawing_;
	};
	class Map
	{
	public:

		Map(std::string, sf::RenderWindow* window);
		BusySide CheckSides(Coord_Object* object);
		bool CheckCoord(sf::IntRect());

	private:

		void GetStartBlocks();

		Block blocks_[COUNT_BLOCKS_X_][COUNT_BLOCKS_Y_] = {};
		sf::RenderWindow* window_;

		sf::Image image_;
		sf::Texture texture_;
	};
	
	bool posibility(float start_x, float start_y, float end_x, float end_y)
	{

	}
	Map main_map;
}

M::Block::Block() :
	sprite_(),
	status_block_(StatusBlock::Empty),
	status_drawing_(StatusDrawing::Nothing)
{}
M::Block::Block(StatusBlock new_status, StatusDrawing new_status_drawing, sf::Texture texture, sf::IntRect rect, float coord_x, float coord_y) :
	sprite_(),
	status_block_(new_status),
	status_drawing_(new_status_drawing)
{
	sprite_.setTexture(texture);
	sprite_.setTextureRect(rect);
	sprite_.setPosition(coord_x, coord_y);
}
sf::Sprite M::Block::GetBlock()
{
	return sprite_;
}
void M::Block::ChangeBlock(sf::IntRect rect, StatusBlock new_status, StatusDrawing new_status_drawing)
{
	sprite_.setTextureRect(rect);
	status_block_ = new_status;
	status_drawing_ = new_status_drawing;
}
bool M::Block::isEmpty()
{
	if (status_block_ == StatusBlock::Empty)
		return true;
	return false;
}






Map::Map(std::string file, sf::RenderWindow* window):
	blocks_(),
	window_(window),

	image_(),
	texture_()
{
	image_.loadFromFile (file);
	image_.createMaskFromColor(sf::Color(255, 255, 255));

	texture_.loadFromImage(image_);

	//GetStartBlocks();
}
void Map::GetStartBlocks()
{
	//пилить
}
BusySide Map::CheckSides(Coord_Object* object)
{
	//пилить
}
*/