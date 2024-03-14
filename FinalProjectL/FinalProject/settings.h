#pragma once

#include <SFML/Graphics.hpp>
#include "SystemTime.h"

// Головні параметри натройки

//Параметри вікна
#define sizeWindowX 1176
#define sizeWindowY 872

//Лінії для масива 
#define lineHorizontX  7
#define lineVetrikalY  7

//Параметри бокса при співідношині 7:7
#define sizeBoxX sizeWindowX/lineHorizontX
#define sizeBoxMainY sizeWindowY/8  // 111
#define sizeBoxY (sizeWindowY-sizeBoxMainY)/lineVetrikalY
//Road to files
#define fonsPNG "Image/fons.png"
#define fonPNG "Image/fon.png"
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
    static const std::wstring defaultWstring = L"";
    // Rectangle default value
    static const sf::Color defaultFillColorBox = sf::Color::White;
    static const sf::Vector2f defaultSize(1.f, 1.f);
    // Other
    static const sf::Vector2f defaultPosition(0.f, 0.f);

   static const std::string daysOfWeek[] = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY","SUNDAY"};

    enum StatusProgram 
    {
        calendar = 0,
        menu,
        task,
        setting,
        other
    };

    static const SystemTime systemTime;



