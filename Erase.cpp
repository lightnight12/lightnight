#include "Erase.h"

Erase::Erase(Scene& sceneRef)
    : Tool(sceneRef), eraseRadius(10.0f)
{
}

void Erase::draw(sf::RenderWindow& window) 
{
}

void Erase::update(sf::RenderWindow& window) 
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
    {
        if (!isDrawing)
        {
            isDrawing = true;
        }

        auto it = scene.lines.begin();

        while (it != scene.lines.end())
        {
            bool eraseLine = false;

            for (const auto& vertex : *it)
            {
                float_t dx = vertex.position.x - mousePos.x;
                float_t dy = vertex.position.y - mousePos.y;

                if (std::sqrt(dx * dx + dy * dy) <= eraseRadius)
                {
                    eraseLine = true;
                    break;
                }
            }

            if (eraseLine)
            {
                it = scene.lines.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
    else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        isDrawing = false;
    }
}
