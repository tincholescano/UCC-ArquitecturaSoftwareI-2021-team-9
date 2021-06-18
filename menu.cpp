#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "juego.cpp"

using namespace sf;
using namespace std;

void Menu();
void Help(int i);

void Menu() {
    RenderWindow menu(VideoMode(800, 600), "DRAG RACING");

    // Fondo de pantalla
    Texture tfondo;
    tfondo.loadFromFile("recursos/fondo.jpg");
    tfondo.setSmooth(true);
    Sprite sfondo(tfondo);
    sfondo.setScale(sf::Vector2f(1.f, 2.f));
    sfondo.scale(sf::Vector2f(0.5f, 0.3f));

    while (menu.isOpen()) {
        Event event;
        while (menu.pollEvent(event)) {
            if (event.type == Event::Closed)
                menu.close();
        }
        menu.clear();

        // Texto de menu
        Font font;
        font.loadFromFile("SFML/automati.ttf");
        Text text("Bienvenido a Drag Racing \n\n Tecla I para iniciar \n\n Tecla H para instrucciones \n\n Tecla F para salir", font);
        text.setCharacterSize(20);
        text.setStyle(Text::Bold);
        text.setFillColor(Color::White);
        text.setPosition(menu.getSize().x*0.02, menu.getSize().y - 150);


        menu.draw(sfondo);
        menu.draw(text);
        menu.display();
        if (event.type == Event::TextEntered) {
            if (Keyboard::isKeyPressed(Keyboard::F)) {
                menu.close();
            } else if (Keyboard::isKeyPressed(Keyboard::I)) {
                menu.close();
                juego();
            } else {
                menu.close();
                Help(1);
            }
        }
    }
};

void Help(int i) {
    RenderWindow h(VideoMode(800, 450), "DRAG RACING");

    // Fondo de pantalla
    Texture tfondo;
    tfondo.loadFromFile("recursos/fondoHelp.jpg");
    tfondo.setSmooth(true);
    Sprite sfondo(tfondo);
    sfondo.setScale(sf::Vector2f(1.f, 1.f));
    sfondo.scale(sf::Vector2f(0.5f, 0.5f));

    while (h.isOpen()) {
        Event event;
        while (h.pollEvent(event)) {
            if (event.type == Event::Closed)
                h.close();
        }
        h.clear(Color::White);

        // Texto de Help
        string txt;
        string txt1 = "  INTRODUCCION AL JUEGO \n\n  Deberas enfrentarte en una \n carrera en linea recta contra \nun enemigo veloz y demostrar \n    tus reflejos y habilidades \n       para poder derrotarlos";
        string txt2 = "               Como jugar? \n  Al iniciar la pantalla de juego \n   deberas apretar el boton S \n para que empieze el contador. \n Al apagarse las luces deberas \n        apretar D para poner \n         la siguiente marcha";
        Font font;
        font.loadFromFile("SFML/arial.ttf");
        if (i==1) {
            txt = txt1;
        } else {
            txt = txt2;
        }
        Text ins(txt, font);
        ins.setCharacterSize(15);
        ins.setStyle(Text::Bold);
        ins.setFillColor(Color::White);
        ins.setPosition(h.getSize().x*0.35, h.getSize().y - 370);

        h.draw(sfondo);
        h.draw(ins);
        h.display();

        if (event.type == Event::TextEntered) {
            if (Keyboard::isKeyPressed(Keyboard::F)) {
                h.close();
                Menu();
            } else {
                h.close();
                Help(2);
            }
        }
    }
};
