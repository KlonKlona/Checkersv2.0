#include "Menu.h"
#include <iostream>

    Menu::Menu(float width, float height) {
        if(!font.loadFromFile("arial.ttf"))
            std::cout << "Font hasn't been loaded" << std::endl;

        menu[0].setFont(font);
        menu[0].setColor(sf::Color::White);
        menu[0].setString("Play");
        menu[0].setCharacterSize( 50 );
        menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

        menu[1].setFont(font);
        menu[1].setColor(sf::Color::White);
        menu[1].setString("Options");
        menu[1].setCharacterSize( 50 );
        menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

        menu[2].setFont(font);
        menu[2].setColor(sf::Color::White);
        menu[2].setString("Exit");
        menu[2].setCharacterSize( 50 );
        menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

        selectedItemIndex = 0;

    }

    Menu::~Menu() {
    }

    void Menu::draw(sf::RenderWindow &window) {
        for(int i = 0 ; i < MAX_NUMBER_OF_ITEMS ; i++) {
            window.draw(menu[i]);
        }
    }

    void Menu::MoveUp() {
        if(selectedItemIndex >= 1) {
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex--;
            menu[selectedItemIndex].setColor(sf::Color::Red);
        }
    }

    void Menu::MoveDown() {
        if(selectedItemIndex < MAX_NUMBER_OF_ITEMS - 1) {
            menu[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex++;
            menu[selectedItemIndex].setColor(sf::Color::Red);
        }
    }

    sf::Vector2f Menu::getPosition(int n) {
        sf::Vector2f position = menu[n].findCharacterPos(100);
        return position;
    }

    void Menu::CheckMouse(sf::RenderWindow &window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition( window );
        sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
        for( int i = 0 ; i < MAX_NUMBER_OF_ITEMS ; i++) {
            if(menu[i].getGlobalBounds().contains( mousePosF ))
                menu[i].setColor( sf::Color( 250, 20, 20 ) );
            else
                menu[i].setColor( sf::Color::White );
        }
    }

    int Menu::CheckPress(sf::RenderWindow &window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition( window );
        sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );
            if(menu[0].getGlobalBounds().contains( mousePosF ))
                return 0;
            if(menu[1].getGlobalBounds().contains( mousePosF ))
                return 1;
            if(menu[2].getGlobalBounds().contains( mousePosF ))
                return 2;
    }


