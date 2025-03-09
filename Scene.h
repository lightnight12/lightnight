#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <stack>

class Scene
{
public:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Color spriteColor; 

    std::vector<sf::Vertex> currentLine;
    std::vector<std::vector<sf::Vertex>> lines;

    static std::stack<std::vector<sf::Vertex>> Undo;  
    static std::stack<std::vector<sf::Vertex>> Redo;

    Scene();

    sf::Color getPixelColor(sf::Vector2i position);
    void setPixelColor(sf::Vector2i position, sf::Color color);
    sf::Texture getTexture()
    {
        return texture;
    }

    void createSheet(sf::RenderWindow& window);
    void drawSheet(sf::RenderWindow& window);
    void undo(sf::RenderWindow& window);
};


