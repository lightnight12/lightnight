#include "main.h"
#include <iostream>
using namespace std;



int main()
{
    sf::RenderWindow window(sf::VideoMode(1720, 900), "Whiteboard");
    window.setFramerateLimit(60);

#pragma region SET_ICON
    sf::Image icon;
    if (!icon.loadFromFile("D:/Visual Studio Projects/Whiteboard/Textures/write.png"))
    {
        std::cerr << "Error loading icon" << std::endl;
        return -1;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
#pragma endregion

    Scene scene;
    auto menu = std::make_unique<Menu>();
    auto pencil = std::make_unique<Pencil>(scene);
    auto erase = std::make_unique<Erase>(scene); 
    auto fill = std::make_unique<Fill>(scene); 
    auto colorDetect = std::make_unique<ColorDetect>(scene);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        scene.drawSheet(window);
        scene.undo(window);

        menu->update(window);

        if (menu->currentTool == Menu::tt_pencil) 
        { 
            pencil->update(window); 
        }
        else if (menu->currentTool == Menu::tt_erase) 
        {
            erase->update(window);
        }

        fill->update(window);
        colorDetect->update(window);

        pencil->draw(window);
        erase->draw(window);


        window.display();
    }

    return 0;
}
