#include "Menu.h"

void Menu::loadTexture(sf::Texture& texture, sf::Sprite& sprite, const std::string& fileName) 
{
    if (!texture.loadFromFile(fileName))
    {
        std::cerr << "Error: load from file -> " << fileName << std::endl;
    }
    sprite.setTexture(texture);
}

void Menu::drawIcon(sf::Sprite& icon, sf::RenderWindow& window)
{
    window.draw(icon);
}

void Menu::setIconScale(sf::Sprite& sprite, const sf::Vector2f& scale)
{
    sprite.setScale(scale);
}

void Menu::drawBounds(const sf::Sprite& sprite, sf::RenderWindow& window)
{
    sf::FloatRect bounds = sprite.getGlobalBounds();
    sf::RectangleShape rectangle(sf::Vector2f(bounds.width, bounds.height));
    rectangle.setPosition(bounds.left, bounds.top);
    rectangle.setFillColor(sf::Color::Transparent);
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setOutlineThickness(2.f);
    window.draw(rectangle);
}

Menu::Menu()
    : currentTool(tt_none)
    , scale(0.06f, 0.06f) 
    , moveSpeed(5.0f)
    , menuInteraction(sf::FloatRect(300.f, 0.0f, 1020.f, 70.f))  
{
    loadTexture(pencilTexture, pencilSprite, pencilName);
    loadTexture(eraserTexture, eraserSprite, eraserName);
    loadTexture(arrowTexture, arrowSprite, arrowName);

    setIconScale(pencilSprite, scale);
    setIconScale(eraserSprite, scale);
    setIconScale(arrowSprite, scale);

    menuSprites.push_back(pencilSprite);
    menuSprites.push_back(eraserSprite);
    menuSprites.push_back(arrowSprite);
}

bool Menu::interaction(const sf::FloatRect& bounds, sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    return bounds.contains(static_cast<float_t>(mousePos.x), static_cast<float_t>(mousePos.y));
}

void Menu::handleToolSelection(sf::RenderWindow& window)
{
    for (size_t i = 0; i < menuSprites.size(); ++i)
    {
        if (interaction(menuSprites[i].getGlobalBounds(), window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (menuSprites[i].getTexture() == pencilSprite.getTexture())
            {
                currentTool = tt_pencil;
            }
            else if (menuSprites[i].getTexture() == eraserSprite.getTexture())
            {
                currentTool = tt_erase;
            }
        }
    }
}

void Menu::interpolationSprites(sf::Sprite& targetSprite, const sf::Vector2f& targetPosition, sf::RenderWindow& window)
{
    sf::Vector2f currentPos = targetSprite.getPosition();
    static bool menuOpen = false;

    targetSprite.setPosition(targetPosition.x, targetPosition.y);

    if (interaction(menuInteraction, window)) 
    {
        targetSprite.setPosition(targetPosition.x, 30.0f);

        //drawBounds(targetSprite, window);

        if (targetSprite.getTexture() == arrowSprite.getTexture())
        {
            targetSprite.setPosition(targetPosition.x, 80.0f); 
        }   
    } 

    if (currentPos.y != targetSprite.getPosition().y)
    {
        float_t deltaY = targetSprite.getPosition().y - currentPos.y;
        targetSprite.setPosition(targetSprite.getPosition().x, currentPos.y + deltaY * moveSpeed * 0.01f);
    }

    if (currentPos.x != targetSprite.getPosition().x)
    {
        float_t deltaX = targetSprite.getPosition().x - currentPos.x;
        targetSprite.setPosition(currentPos.x + deltaX * moveSpeed * 0.01f, targetSprite.getPosition().y);
    }

    drawIcon(targetSprite, window);

    handleToolSelection(window);
}

void Menu::update(sf::RenderWindow& window)
{
    for (size_t i = 0; i < menuSprites.size(); ++i)
    {
        interpolationSprites(menuSprites[i], iconPositions[i], window);
    }
}