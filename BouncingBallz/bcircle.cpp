#include "pch.h"
#include <iostream>
#include "bcircle.h"
#include <SFML\Graphics.hpp>

#define M_PI 3.14159265358979323846

using namespace sf;
static int collision_cnt = 0;

BCircle::BCircle(float i) : CircleShape(i)
{
	
}
	
void BCircle::bmove()
{
	move_vector = new_move_vector;
	move(move_vector);
	new_move_vector = move_vector;
}

void BCircle::calculate_move_vector(std::vector<BCircle> circles, int cur_pos)
{
	if ((getPosition().x <= 0.f) || (getPosition().x >= 350.f))
		new_move_vector.x = -move_vector.x;
	if ((getPosition().y <= 0.f) || (getPosition().y >= 350.f))		
		new_move_vector.y = -move_vector.y;
	test_collision(circles, cur_pos);
}

void BCircle::set_move_vector(Vector2f set_vector)
{
	new_move_vector = set_vector;
}

sf::Vector2f BCircle::get_move_vector()
{
	return move_vector;
}
void BCircle::test_collision(std::vector<BCircle> circles, int cur_pos)
{	
	float centerPositionX = getPosition().x + 25;
	float centerPositionY = getPosition().y + 25;

	for(int i = 0; i < circles.size(); i++)
	{
		if (i != cur_pos)
		{
			float otherPositionX = circles[i].getPosition().x + 25;
			float otherPositionY = circles[i].getPosition().y + 25;
			float phi;
			float distance = hypotf((otherPositionX - centerPositionX), (otherPositionY - centerPositionY));
			if (distance < 50)
			{
				if (collision_cnt == 0)
				{
					//new_move_vector = circles[i].get_move_vector();
					phi = acos((otherPositionX - centerPositionX) / distance);
					std::cout << "PHI = " << phi << " DIST = " << distance << std::endl;
					new_move_vector.x = cos(phi)*move_vector.x + cos(phi + M_PI / 2) * move_vector.y;
					new_move_vector.y = sin(phi)*move_vector.x + sin(phi + M_PI / 2) * move_vector.y;
					std::cout << "Circ 1 = " << cur_pos << "   Circ 2 = " << i << std::endl;
					//v1fx = cos(phi)*v1fxr+cos(phi+ M_PI/2)*v1fyr
					//std::cout << "Old vector: " << move_vector.x << " and " << move_vector.y << std::endl;
					//std::cout << "New vector: " << new_move_vector.x << " and " << new_move_vector.y << std::endl;
				}
			}
		}
	}
	if (collision_cnt < 3)
		collision_cnt++;
	else
		collision_cnt = 0;
}

