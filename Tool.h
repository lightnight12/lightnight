#pragma once
#include "Input.h"

class Tool : public Scene
{
protected:
    Scene& scene;
    bool isDrawing;


public:
    Tool(Scene& sceneRef)
        : scene(sceneRef), isDrawing(false)
    {}

    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void update(sf::RenderWindow& window) = 0;
    sf::Color setColor(sf::Color& color) {};
};