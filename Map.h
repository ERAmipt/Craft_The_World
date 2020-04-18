#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MapTiles.h"

namespace M {

	const static size_t WindowWidth = 1920;
	const static size_t WindowHeight = 1080;

	class Block
	{
	public:

		Block(std::string name, sf::Vector2f tileset_coords, sf::Vector2f size, bool hard) :
			tileset_coords_(tileset_coords),
			size_(size),
			hard_(hard),
			name_(name)
		{}

		float tile_x() { return tileset_coords_.x; };
		float tile_y() { return tileset_coords_.y; };
		bool  isSoft() { return !hard_; };
		float width()  { return size_.x; };
		float height() { return size_.y; };


	private:
		sf::Vector2f tileset_coords_;
		sf::Vector2f size_;
		bool hard_;
		std::string name_;
	};

	// Array with all type of Blocks
	static Block Blocks[] =
	{
		Block("Air", sf::Vector2f(192, 416), sf::Vector2f(64, 64), 0),
		Block("Grass", sf::Vector2f(896, 32), sf::Vector2f(64, 64), 1)
	};


	class Map : public sf::Drawable, public sf::Transformable
	{
	public:

		Map(int map_number);

		/////////////////////////////////////////////////////
		// Update map's view. Should be called every time user
		//    scroll the map or do another interact	
		//
		// Usage: map.update(0, sf::Mouse::getPosition().x, 
		//	     				sf::Mouse::getPosition().y);
		/////////////////////////////////////////////////////
		void update(int delta, int x, int y);

		sf::View view() { return view_; };

		/////////////////////////////////////////////////////
		// Return absolute coordinates of the desired 
		//    window based coordinates
		/////////////////////////////////////////////////////
		sf::Vector2f AbsCoords(sf::Vector2u coords) const;
		sf::Vector2f AbsCoords(sf::Vector2i coords) const;
		sf::Vector2f AbsCoords(int x, int y) const;

		/////////////////////////////////////////////////////
		// Check is block is soft
		/////////////////////////////////////////////////////
		bool isSoft(sf::Vector2u coords) const;
		bool isSoft(sf::Vector2i coords) const;
		bool isSoft(int x, int y) const;

	private:

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		sf::VertexArray vertices_;
		sf::Texture tileset_;
		M::MapTile tile_;
		sf::View view_;
		unsigned int cur_width_;
		unsigned int cur_height_;
	};
}
	
