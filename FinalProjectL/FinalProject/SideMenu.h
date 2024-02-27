#pragma once
#include <SFML/Graphics.hpp>
#include "TextBox.h"
#include "settings.h"
#include <iostream>

using namespace std;

class SideMenu : public TextBox
{
public:
	SideMenu(const sf::Vector2f& size, const sf::Vector2f& position);

	
	void draw(sf::RenderWindow& sideWindow);

	void setBackground(const string& bg);
	void setLogoSize(const sf::Vector2f& size);
	void setLogoPosition(const sf::Vector2f& position);

	/*bool isButtonClicked(const sf::Vector2f& mousePosition) const;*/
	bool Visible();  //��� ���� ��� ���� ������� �� ������ �� ����������� ��� ������� �����������(true/false)

	StatusProgram isButtonClicked(const sf::Vector2f& mousePosition) const;

protected:
	TextBox homeButton;
	TextBox calendarButton;
	TextBox settingButton;
private:
	sf::RectangleShape RectMenu;
	sf::Texture backgroundTexture;
	sf::Texture logoTexture;
	sf::Sprite logo;
	bool isVisible;
};


