#pragma once
#include <SFML/Graphics.hpp>


#define MAX_NUMBER_OF_ITEMS 3

class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    sf::Vector2f getPosition(int n);
    void CheckMouse(sf::RenderWindow &window);
    int CheckPress(sf::RenderWindow &window);
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
