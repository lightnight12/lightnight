#include "Scene.h"

std::stack<std::vector<sf::Vertex>> Scene::Undo; 
std::stack<std::vector<sf::Vertex>> Scene::Redo;

Scene::Scene() 
    : spriteColor(60, 60, 60)
{
    texture.create(1920, 1080); 
    sf::Image img;
    img.create(1920, 1080, spriteColor); 
    texture.loadFromImage(img);

}

sf::Color Scene::getPixelColor(sf::Vector2i position)
{
    if (position.x >= 0 && position.x < texture.getSize().x &&
        position.y >= 0 && position.y < texture.getSize().y)
    {
        sf::Image img = texture.copyToImage();
        return img.getPixel(position.x, position.y);
    }
    return sf::Color::Transparent; 
}
void Scene::setPixelColor(sf::Vector2i position, sf::Color color)
{
    if (position.x >= 0 && position.x < texture.getSize().x &&
        position.y >= 0 && position.y < texture.getSize().y)
    {
        sf::Image img = texture.copyToImage();
        img.setPixel(position.x, position.y, color);
        texture.update(img); 
    }
}


void Scene::createSheet(sf::RenderWindow& window)
{
    if (texture.getSize().x > 0 && texture.getSize().y > 0)
    {
        sprite.setTexture(texture);
        sf::Vector2u windowSize = window.getSize();
        sprite.setScale(static_cast<float_t>(windowSize.x) / texture.getSize().x, static_cast<float_t>(windowSize.y) / texture.getSize().y);
    }
}

void Scene::drawSheet(sf::RenderWindow& window)
{
    createSheet(window);
    window.draw(sprite);
}

void Scene::undo(sf::RenderWindow& window) 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)))
    {
        if (!Undo.empty())
        {
            auto lineToRestore = Undo.top();
            lines.push_back(lineToRestore); 

            Undo.pop(); 
        }
    }
}