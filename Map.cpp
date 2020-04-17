#pragma once
#include "Map.h"
#include <cstdio>

M::Map::Map() :
	vertices_(),
	tileset_(),
	view_(sf::FloatRect(0.f, 0.f, M::TileSize.x * Height, M::TileSize.x * Height))
{
	// load the tileset texture
	if (!tileset_.loadFromFile("images/blocks.png")) {
		std::cerr << "Can not load image\n";
	}

	// resize the vertex array to fit the level size
	vertices_.setPrimitiveType(sf::Quads);
	vertices_.resize(Width * Height * 4);

	// populate the vertex array, with one quad per tile
	for (unsigned int i = 0; i < Width; ++i)
		for (unsigned int j = 0; j < Height; ++j)
		{
			// get the current tile number
			int tileNumber = level[i + j * Width];
			// get a pointer to the current tile's quad
			sf::Vertex* quad = &vertices_[(i + j * Width) * 4];

			float bx = Blocks[tileNumber].getX(),
				  by = Blocks[tileNumber].getY();

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * M::TileSize.x, j * TileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * M::TileSize.x, j * TileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * M::TileSize.x, (j + 1) * TileSize.y);
			quad[3].position = sf::Vector2f(i * M::TileSize.x, (j + 1) * TileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(bx, by);
			quad[1].texCoords = sf::Vector2f(bx + M::TileSize.x, by);
			quad[2].texCoords = sf::Vector2f(bx + M::TileSize.x, by + M::TileSize.x);
			quad[3].texCoords = sf::Vector2f(bx, by + M::TileSize.x);
		}
}

void M::Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &tileset_;

	// draw the vertex array
	target.draw(vertices_, states);
}

void M::ScrollMap(Map& map, int delta, float x, float y) {
	//map.view_.zoom((float)delta / 10 + 1.0);
	//map.view_.setCenter(sf::Vector2f(x, y));
	//printf("ViewPoint left:%g top:%g -> width:%g height:%g\nSize x:%g y:%g\nCenter x:%g y:%g\n",
	//	map.view_.getViewport().left, map.view_.getViewport().top, map.view_.getViewport().width, map.view_.getViewport().height,
	//	map.view_.getSize().x, map.view_.getSize().y, map.view_.getCenter().x, map.view_.getCenter().y);
}

bool M::Map::isSoft(int x, int y) const {
	int pos = int((float(Height) * x / 1080) * Width + (float(Width) * x / 1920));
	//std::cout << pos << std::endl;
	//return M::Blocks[M::level[pos]].isSoft();
	return true;
}

