#pragma once
#include "Map.h"
#include <cstdio>
#include <cassert>

M::Map::Map(int map_number) :
	vertices_(),
	tileset_(),
	tile_(M::MapTiles[map_number]),
	view_(sf::FloatRect(0.f, 0.f, tile_.width(), tile_.height())),
	cur_width_(2000),
	cur_height_(2000)
{
	view_.reset(sf::FloatRect(0.f, 0.f, tile_.width(), tile_.height()));
	// load the tileset texture
	if (!tileset_.loadFromFile("images/blocks.png")) {
		std::cerr << "Can not load image\n";
		exit(0);
	}

	// resize the vertex array to fit the level size
	vertices_.setPrimitiveType(sf::Quads);
	vertices_.resize(tile_.blocks_x() * tile_.blocks_y() * 4);

	// populate the vertex array, with one quad per tile
	for (unsigned int i = 0; i < tile_.blocks_x(); ++i)
		for (unsigned int j = 0; j < tile_.blocks_y(); ++j)
		{
			// get the current tile number
			int tile_number = tile_.level()[i + j * tile_.blocks_x()];
			// get a pointer to the current tile's quad
			sf::Vertex* quad = &vertices_[(i + j * tile_.blocks_x()) * 4];

			float bx = Blocks[tile_number].tile_x(),
				  by = Blocks[tile_number].tile_y();

			// define its 4 corners
			quad[0].position = sf::Vector2f(i       * tile_.tile_size().x, j       * tile_.tile_size().y);
			quad[1].position = sf::Vector2f((i + 1) * tile_.tile_size().x, j       * tile_.tile_size().y);
			quad[2].position = sf::Vector2f((i + 1) * tile_.tile_size().x, (j + 1) * tile_.tile_size().y);
			quad[3].position = sf::Vector2f(i       * tile_.tile_size().x, (j + 1) * tile_.tile_size().y);
			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(bx,                       by);
			quad[1].texCoords = sf::Vector2f(bx + tile_.tile_size().x, by);
			quad[2].texCoords = sf::Vector2f(bx + tile_.tile_size().x, by + tile_.tile_size().y);
			quad[3].texCoords = sf::Vector2f(bx,                       by + tile_.tile_size().y);
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


sf::Vector2f M::Map::AbsCoords(int x, int y) const {
	assert(x <= int(M::WindowWidth));
	assert(y <= int(M::WindowHeight));
	assert(x >= 0);
	assert(y >= 0);

	double left = (view_.getCenter().x - cur_width_ / 2);
	double top =  (view_.getCenter().y - cur_height_ / 2);
	double cur_x = left + double(x) / M::WindowWidth * cur_width_;
	double cur_y = top + double(y) / M::WindowHeight * cur_height_;
	cur_x = cur_x / tile_.width() * tile_.blocks_x();
	cur_y = cur_y / tile_.height() * tile_.blocks_y();

	return sf::Vector2f(cur_x, cur_y);
}
sf::Vector2f M::Map::AbsCoords(sf::Vector2u coords) const {
	return AbsCoords(coords.x, coords.y);
}
sf::Vector2f M::Map::AbsCoords(sf::Vector2i coords) const {
	return AbsCoords(coords.x, coords.y);
}

void M::Map::update(int delta, int x, int y) {
	const int scroll_area = 100;
	const int scroll_speed = 20;
	
	view_.zoom(float(delta) / 10 + 1);
	if (view_.getCenter().x < view_.getSize().x / 2 ||
		view_.getCenter().x + view_.getSize().x / 2 > tile_.width() ||
		view_.getCenter().y < view_.getSize().y / 2 ||
		view_.getCenter().y + view_.getSize().y / 2 > tile_.height())
	view_.zoom(float(delta * (-1)) / 10 + 1);
	
	cur_width_ = view_.getSize().x;
	cur_height_ = view_.getSize().y;

	if (x < scroll_area) {
		if (view_.getCenter().x - scroll_speed >= cur_width_ / 2)
			view_.setCenter(sf::Vector2f(view_.getCenter().x - scroll_speed, view_.getCenter().y));
	}
	if (x > M::WindowWidth - scroll_area) {
		if (view_.getCenter().x + scroll_speed + cur_width_ / 2 <= tile_.width())
			view_.setCenter(sf::Vector2f(view_.getCenter().x + scroll_speed, view_.getCenter().y));
	}
	if (y < scroll_area) {
		if (view_.getCenter().y - scroll_speed >= cur_height_ / 2)
			view_.setCenter(sf::Vector2f(view_.getCenter().x, view_.getCenter().y - scroll_speed));
	}
	if (y > M::WindowHeight - scroll_area) {
		if (view_.getCenter().y + scroll_speed + cur_height_ / 2 <= tile_.height())
			view_.setCenter(sf::Vector2f(view_.getCenter().x, view_.getCenter().y + scroll_speed));
	}
	
	//printf("X: %d\nY: %d\nViewPoint left:%g top:%g -> width:%g height:%g\nSize x:%g y:%g\nCenter x:%g y:%g\n", x, y,
    	//view_.getViewport().left, view_.getViewport().top, view_.getViewport().width, view_.getViewport().height,
		//view_.getSize().x, view_.getSize().y, view_.getCenter().x, view_.getCenter().y);

}

bool M::Map::isSoft(sf::Vector2u coords) const {
	return M::Blocks[level[int(AbsCoords(coords).x) + int(AbsCoords(coords).y) * 100]].isSoft();
}
bool M::Map::isSoft(sf::Vector2i coords) const {
	return M::Blocks[level[int(AbsCoords(coords).x) + int(AbsCoords(coords).y) * 100]].isSoft();
}
bool M::Map::isSoft(int x, int y) const {
	return M::Blocks[level[int(AbsCoords(x, y).x) + int(AbsCoords(x, y).y) * 100]].isSoft();
}

