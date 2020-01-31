#pragma once
#include "pch.h"
#include <stdio.h>
#include <SFML\Graphics.hpp>

class BCircle : public sf::CircleShape
{
public:
	BCircle(float i);
	void bmove();
	void set_move_vector(sf::Vector2f);
	void set_new_move_vector(sf::Vector2f);
	sf::Vector2f get_move_vector();
	void test_collision(std::vector<BCircle>, int);
	void calculate_move_vector(std::vector<BCircle>, int);
private:
	sf::Vector2f move_vector;
	sf::Vector2f new_move_vector;
};