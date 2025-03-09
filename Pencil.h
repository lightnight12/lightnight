#pragma once
#include "Tool.h"
#include <queue>
#include <iostream>

class Pencil : public Tool
{
private:
    int colorIndex = 0;

    std::vector<sf::Color> colors;

public:
    Pencil(Scene& sceneRef);

    void draw(sf::RenderWindow& window) override;
    void update(sf::RenderWindow& window) override;

    sf::Color setColor()
    {
        static bool isKeyPressed = false;  
        static sf::Color currentColor = sf::Color::White;  

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !isKeyPressed)
        {
            currentColor = sf::Color::White;
            isKeyPressed = true;  
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && !isKeyPressed)
        {
            currentColor = sf::Color::Black;
            isKeyPressed = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && !isKeyPressed)
        {
            currentColor = sf::Color::Red;
            isKeyPressed = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) && !isKeyPressed)
        {
            currentColor = sf::Color::Green;
            isKeyPressed = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && !isKeyPressed)
        {
            currentColor = sf::Color::Blue;
            isKeyPressed = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) && !isKeyPressed)
        {
            currentColor = sf::Color::Yellow;
            isKeyPressed = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && !isKeyPressed)
        {
            currentColor = sf::Color::Magenta;
            isKeyPressed = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && !isKeyPressed)
        {
            currentColor = sf::Color::Cyan;
            isKeyPressed = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) && !isKeyPressed)
        {
            currentColor = sf::Color(255, 255, 0, 128); 
            isKeyPressed = true;
        }

        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) && 
            !sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
        {
            isKeyPressed = false;  
        }

        return currentColor;
    }
};

class Fill : public Tool
{
private:
    sf::Color fillColor = sf::Color::Green;

public:
    Fill(Scene& sceneRef)
        : Tool(sceneRef)  
    {}


    void draw(sf::RenderWindow& window) override
    {}

    void update(sf::RenderWindow& window) override
    {
        fill(window);
    }

    void fill(sf::RenderWindow& window)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sprite.setColor(fillColor);
        }
    }
};

class ColorDetect : public Tool
{
private:
    sf::Color detectiveColor;
    sf::Color userColor;

public:
    ColorDetect(Scene& sceneRef) : Tool(sceneRef)
    {}

    /*void acceptColor(sf::RenderWindow& window)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (mousePos.x >= 0 && mousePos.y >= 0 && mousePos.x < window.getSize().x && mousePos.y < window.getSize().y)
        {
            sf::Texture texture;
            texture.create(window.getSize().x, window.getSize().y);
            texture.update(window);

            sf::Image image = texture.copyToImage();

            detectiveColor = image.getPixel(mousePos.x, mousePos.y);

            std::cout << "Detected color: R=" << (int)detectiveColor.r
                << " G=" << (int)detectiveColor.g
                << " B=" << (int)detectiveColor.b
                << " A=" << (int)detectiveColor.a << std::endl;
        }   
    }*/

    void draw(sf::RenderWindow& window) override
    { }

    void update(sf::RenderWindow& window) override
    { 
        //acceptColor(window);
    }





};
