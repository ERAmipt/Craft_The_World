#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
namespace M {

	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	class Map : public sf::Drawable, public sf::Transformable
	{
	public:

		bool load()
		{	
			unsigned int width = 16;
			unsigned int height = 8;
			sf::Vector2u tileSize = { 64, 64 };

			// load the tileset texture
			if (!m_tileset.loadFromFile("images/blocks.png"))
				return false;

			// resize the vertex array to fit the level size
			m_vertices.setPrimitiveType(sf::Quads);
			m_vertices.resize(width * height * 4);

			// populate the vertex array, with one quad per tile
			for (unsigned int i = 0; i < width; ++i)
				for (unsigned int j = 0; j < height; ++j)
				{
					// get the current tile number
					int tileNumber = level[i + j * width];
					// get a pointer to the current tile's quad
					sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

					int tu = 0, tv = 0;
					switch (tileNumber) {
						case 0:
							tu = 192;
							tv = 416;
							break;
						case 1:
							tu = 896;
							tv = 32;
							break;
						default:
							std::cerr << "Unknown tileNumber";
							return false;
					}

					// define its 4 corners
					quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
					quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
					quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
					quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

					// define its 4 texture coordinates
					quad[0].texCoords = sf::Vector2f(tu, tv);
					quad[1].texCoords = sf::Vector2f(tu + 64, tv);
					quad[2].texCoords = sf::Vector2f(tu + 64, tv + 64);
					quad[3].texCoords = sf::Vector2f(tu, tv + 64);
				}

			return true;
		}

	private:

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			// apply the transform
			states.transform *= getTransform();

			// apply the tileset texture
			states.texture = &m_tileset;

			// draw the vertex array
			target.draw(m_vertices, states);
		}

		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
	};

	// create the tilemap from the level definition
	//Map map;
	
}
	/*
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