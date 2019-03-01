#include "pch.h"
#include <iostream>
#include "bcircle.h"
#include <SFML\Graphics.hpp>

using namespace sf;
BCircle::BCircle(float i) : CircleShape(i)
{
	
}
	
void BCircle::bmove()
{
	move(move_vector);
	calculate_move_vector();
}

void BCircle::calculate_move_vector()
{
	if ((getPosition().x <= 0.f) || (getPosition().x >= 350.f))
		move_vector.x = -move_vector.x;
	if ((getPosition().y <= 0.f) || (getPosition().y >= 350.f))		
		move_vector.y = -move_vector.y;
}

void BCircle::set_move_vector(Vector2f set_vector)
{
	move_vector = set_vector;
}


