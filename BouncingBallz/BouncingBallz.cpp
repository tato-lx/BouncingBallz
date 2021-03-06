// Helloworld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
//#include <windows.h>
#include <SFML\Graphics.hpp>
#include "bcircle.h"

#define NUM_CIRCLES 2

std::vector<BCircle> circles;

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
	BCircle shape(25.f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(100.f, 100.f);
	circles.insert(circles.begin(), shape);
	shape.setFillColor(sf::Color::Yellow);
	shape.setPosition(270.f, 270.f);
	circles.insert(circles.begin(), shape);
	window.setFramerateLimit(10);
	sf::Vector2f v1(5.f, 3.f);
	sf::Vector2f v2(3.f, 6.f);
	circles[0].set_move_vector(v1);
	circles[1].set_move_vector(v2);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (int i = 0; i < NUM_CIRCLES; i++)
		{
			window.draw(circles[i]);
//			std::cout << "Draw!" << std::endl;
		}
		window.display();
		for (int i = 0; i < NUM_CIRCLES; i++)
		{
//			std::cout << "move # " << i << std::endl;
			circles[i].bmove();
		}
		for (int i = 0; i < NUM_CIRCLES; i++)
		{
			circles[i].calculate_move_vector(circles, i);
		}
	}

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
