#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(800, 800), "Project");
    CircleShape shape(30);
    shape.setFillColor(Color::Red);
    shape.setOrigin(Vector2f(0,0));
    shape.setPosition(Vector2f(400,400));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        window.clear();
        window.draw(shape);
        window.display();
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Right)){
                Vector2f pos = shape.getPosition();
                pos.x = pos.x + 2;
                shape.setPosition(pos);
            }
            if (Keyboard::isKeyPressed(Keyboard::Left)){
                Vector2f pos = shape.getPosition();
                pos.x = pos.x - 2;
                shape.setPosition(pos);
            }
            if (Keyboard::isKeyPressed(Keyboard::Up)){
                Vector2f pos = shape.getPosition();
                pos.y = pos.y - 2;
                shape.setPosition(pos);
            }
            if (Keyboard::isKeyPressed(Keyboard::Down)){
                Vector2f pos = shape.getPosition();
                pos.y = pos.y + 2;
                shape.setPosition(pos);
            }
        }
    }

    return 0;
}//
// Created by Michael Lee on 7/09/2022.
//
