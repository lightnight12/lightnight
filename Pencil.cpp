#include "Pencil.h"

Pencil::Pencil(Scene& sceneRef)
    : Tool(sceneRef)
{
    colors =
    {
        sf::Color::White, 
        sf::Color::Black, 
        sf::Color::Red, 
        sf::Color::Green, 
        sf::Color::Blue, 
        sf::Color::Yellow, 
        sf::Color::Magenta, 
        sf::Color::Cyan 
    };
}
void Pencil::draw(sf::RenderWindow& window) 
{
    for (const auto& line : scene.lines)
    {
        if (!line.empty())
        {
            window.draw(&line[0], line.size(), sf::LinesStrip);
        }
    }

    if (!scene.currentLine.empty())
    {
        window.draw(&scene.currentLine[0], scene.currentLine.size(), sf::LinesStrip);
    }
}

void Pencil::update(sf::RenderWindow& window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::Color currentColor = setColor();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))  
    {
        if (!isDrawing)
        {
            isDrawing = true;
            scene.currentLine.clear();
        }

        scene.currentLine.push_back(sf::Vertex(mousePos, currentColor)); 
    }
    else if (isDrawing)
    {
        isDrawing = false;

        if (!scene.currentLine.empty())
        {
            scene.lines.push_back(scene.currentLine);
            Undo.push(scene.currentLine); 
            scene.currentLine.clear();  
        }
    }

    undo(window);


}