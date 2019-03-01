#pragma once
#include "pch.h"
#include <SFML\Graphics.hpp>

class BCircle : public sf::CircleShape
{
public:
	BCircle(float i);
	void bmove();
	void set_move_vector(sf::Vector2f);
private:
	void calculate_move_vector();
	sf::Vector2f move_vector;
};