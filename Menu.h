#pragma once
#include "Pencil.h"
#include "Erase.h"
#include <iostream>

class Menu
{
private:
    sf::Vector2f currentPosition;

    void loadTexture(sf::Texture& texture, sf::Sprite& sprite, const std::string& fileName);

    void drawIcon(sf::Sprite& icon, sf::RenderWindow& window);

    void setIconScale(sf::Sprite& sprite, const sf::Vector2f& scale);

    void drawBounds(const sf::Sprite& sprite, sf::RenderWindow& window);

public:
    enum tooltype
    {
        tt_none,
        tt_pencil,
        tt_erase
    };
    tooltype currentTool;
    sf::Vector2f scale;
    float_t moveSpeed;
    sf::FloatRect menuInteraction;

    std::vector<sf::Sprite> menuSprites;
    std::vector<sf::Vector2f> iconPositions
    {
        {600.0f, -50.0f},
        {700.0f, -50.0f},
        {750.0f, 20.0f}
    };

    Menu();

    bool interaction(const sf::FloatRect& bounds, sf::RenderWindow& window);
    void handleToolSelection(sf::RenderWindow& window);
    void interpolationSprites(sf::Sprite& targetSprite, const sf::Vector2f& targetPosition, sf::RenderWindow& window);
    void update(sf::RenderWindow& window);

private:
#pragma region Texture
    // Текстури для спрайтів
    sf::Texture pencilTexture;
    sf::Sprite pencilSprite;
    std::string pencilName = "D:/Visual Studio Projects/Whiteboard/Textures/pancil.png";

    sf::Texture eraserTexture;
    sf::Sprite eraserSprite;
    std::string eraserName = "D:/Visual Studio Projects/Whiteboard/Textures/eraser.png";

    sf::Texture arrowTexture;
    sf::Sprite arrowSprite;
    std::string arrowName = "D:/Visual Studio Projects/Whiteboard/Textures/arrow-down.png";
#pragma endregion
};
