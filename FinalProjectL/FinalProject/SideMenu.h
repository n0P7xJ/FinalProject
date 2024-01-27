#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include <iostream>

using namespace std;

class SideMenu
{
public:
	SideMenu(const sf::Vector2f& size, const sf::Vector2f& position);
	void Visible();
	void draw(sf::RenderWindow& sideWindow);

	void setBackground(const string& bg);
private:
	sf::RectangleShape RectMenu;
	bool isVisible;  //для того шоб коли нажимаєш на кнопку то появляється або пропадає прямокутник(true/false)
	sf::Texture backgroundTexture;
};

