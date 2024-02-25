#pragma once

#include <SFML/Graphics.hpp>
#include "SystemTime.h"

// Головні параметри натройки

//Параметри вікна
#define sizeWindowX 1176
#define sizeWindowY 770

//Параметри бокса при співідношині 6:7
#define sizeBoxX 168
#define sizeBoxY 110

//Лінії для масива 
#define lineHorizont  6
#define lineVetrikal  7

//TextBox
// Text default value
static const unsigned int defaultCharacterSize = 20;
static const sf::Color defaultFillColorText = sf::Color::Black;
static const sf::Font defaultFontText = [] {
    sf::Font font;
    if (!font.loadFromFile("Font/Oswald.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
    return font;
}();
static const std::string defaultString = "";
// Rectangle default value
static const sf::Color defaultFillColorBox = sf::Color::White;
static const sf::Vector2f defaultSize(1.f, 1.f);
// Other
static const sf::Vector2f defaultPosition(0.f, 0.f);

enum StatusProgram {
    main = 0,
    calendar,
    menu,
    task,
    other
};

static const SystemTime systemTime;
