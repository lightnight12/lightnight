#pragma once
#include "Tool.h"

class Erase : public Tool 
{
private:
    float_t eraseRadius;

public:
    Erase(Scene& sceneRef);

    void draw(sf::RenderWindow& window) override;

    void update(sf::RenderWindow& window) override;
};