#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace sf;
using namespace std;

void juego2();
void juego3();

void juego() {
    RenderWindow game(VideoMode(1200, 550), "Race");
    float speedE = 0;
    // Fondo de pantalla
    Texture tfondo;
    tfondo.loadFromFile("recursos/fondoCarrera.png");
    tfondo.setSmooth(true);
    Sprite sfondo(tfondo);
    sfondo.setScale(sf::Vector2f(1.f, 1.f));
    sfondo.scale(sf::Vector2f(0.73f, 0.8f));

    Texture tauto;
    tauto.loadFromFile("recursos/auto1.png");
    Sprite sauto(tauto);
    sauto.setScale(Vector2f(1.f, 1.f));
    sauto.scale(Vector2f(0.08f, 0.08f));
    sauto.setPosition(70.f, 340.f);
    sauto.rotate(180.f);

    Texture tautoEnemigo;
    tautoEnemigo.loadFromFile("recursos/auto2.png");
    float speed = 0.048;
    Sprite sautoEnemigo(tautoEnemigo);
    sautoEnemigo.setScale(sf::Vector2f(1.f, 1.f));
    sautoEnemigo.scale(sf::Vector2f(0.08f, 0.08f));
    sautoEnemigo.setPosition(70.f, 265.f);
    sautoEnemigo.rotate(180.f);

    Texture velT;
    velT.loadFromFile("recursos/vel.png");
    Sprite velS(velT);
    velS.setScale(Vector2f(1.f, 1.f));
    velS.scale(Vector2f(0.2f, 0.8f));
    velS.setPosition(540.f, 436.f);

    Texture velAT;
    velAT.loadFromFile("recursos/velA.png");
    Sprite velAS(velAT);
    velAS.setScale(Vector2f(1.f, 1.f));
    velAS.scale(Vector2f(0.6f, 0.3f));
    velAS.setPosition(635.f, 441.f);

    Texture velVT;
    velVT.loadFromFile("recursos/velV.png");
    Sprite velVS(velVT);
    velVS.setScale(Vector2f(1.f, 1.f));
    velVS.scale(Vector2f(0.6f, 0.3f));
    velVS.setPosition(661.f, 441.f);

    Texture velRT;
    velRT.loadFromFile("recursos/velR.png");
    Sprite velRS(velRT);
    velRS.setScale(Vector2f(1.f, 1.f));
    velRS.scale(Vector2f(0.6f, 0.3f));
    velRS.setPosition(682.f, 441.f);

    Texture gearT;
    gearT.loadFromFile("recursos/gear.png");
    Sprite gearS(gearT);
    gearS.setPosition(130.f, 436.f);

    string txt = "D";
    Font font;
    font.loadFromFile("SFML/arial.ttf");
    Text ins(txt, font);
    ins.setCharacterSize(30);
    ins.setStyle(Text::Bold);
    ins.setFillColor(Color::White);
    ins.setPosition(236.f, 465.f);

    Texture metaT;
    metaT.loadFromFile("recursos/meta.png");
    Sprite metaS(metaT);
    metaS.setScale(Vector2f(1.f, 1.f));
    metaS.scale(Vector2f(0.78f, 0.8f));
    metaS.setPosition(1100.f, 188.f);

    while (game.isOpen()) {
        Event event;
        while (game.pollEvent(event)) {
            if (event.type == Event::Closed)
                game.close();
        }
        game.clear();
        game.draw(sfondo);
        game.draw(sautoEnemigo);
        game.draw(sauto);
        game.draw(velAS);
        game.draw(velVS);
        game.draw(velRS);
        game.draw(velS);
        game.draw(gearS);
        game.draw(ins);
        game.draw(metaS);
        game.display();

        int a=3;

        while (a) {
            sauto.move((0.04f)+speedE, 0.f);
            sautoEnemigo.move((speed), 0.f);
            velS.move(0.02f, 0.f);

            if (sauto.getGlobalBounds().intersects(metaS.getGlobalBounds())) {
                sauto.setPosition(70.f, 340.f);
                sautoEnemigo.setPosition(70.f, 265.f);
                velS.setPosition(540.f, 436.f);
                gearS.setPosition(130.f, 436.f);
                speedE = 0;
                game.close();
                juego2();
            };

            if (sautoEnemigo.getGlobalBounds().intersects(metaS.getGlobalBounds())) {
                sauto.setPosition(70.f, 340.f);
                sautoEnemigo.setPosition(70.f, 265.f);
                velS.setPosition(540.f, 436.f);
                gearS.setPosition(130.f, 436.f);
                speedE = 0;
            };

            if (velS.getGlobalBounds().intersects(velRS.getGlobalBounds())) {
                velS.setPosition(682.f, 436.f);
            }


            if (event.type == Event::TextEntered) {
                if (Keyboard::isKeyPressed(Keyboard::F)) {
                    game.close();
                } else if (Keyboard::isKeyPressed(Keyboard::Num1) && velS.getGlobalBounds().intersects(velAS.getGlobalBounds())) {
                    speedE = 0.008;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num2) && velS.getGlobalBounds().intersects(velAS.getGlobalBounds())) {
                    speedE = 0.008;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 500.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num3) && velS.getGlobalBounds().intersects(velAS.getGlobalBounds())) {
                    speedE = 0.008;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(178.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num1) && velS.getGlobalBounds().intersects(velVS.getGlobalBounds())) {
                    speedE = 0.01;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num2) && velS.getGlobalBounds().intersects(velVS.getGlobalBounds())) {
                    speedE = 0.02;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 500.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num3) && velS.getGlobalBounds().intersects(velVS.getGlobalBounds())) {
                    speedE = 0.03;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(178.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num1) && velS.getGlobalBounds().intersects(velRS.getGlobalBounds())) {
                    speedE = -0.02;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num2) && velS.getGlobalBounds().intersects(velRS.getGlobalBounds())) {
                    speedE = -0.02;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 500.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num3) && velS.getGlobalBounds().intersects(velRS.getGlobalBounds())) {
                    speedE = -0.02;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(178.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::R)) {
                    sauto.setPosition(70.f, 340.f);
                    sautoEnemigo.setPosition(70.f, 265.f);
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 436.f);
                    speedE = 0;
                }
            }
            a--;
        }
    }
};


void juego2() {
    RenderWindow game(VideoMode(1200, 550), "Race");
    float speedE = 0;
    // Fondo de pantalla
    Texture tfondo;
    tfondo.loadFromFile("recursos/fondoCarrera.png");
    tfondo.setSmooth(true);
    Sprite sfondo(tfondo);
    sfondo.setScale(sf::Vector2f(1.f, 1.f));
    sfondo.scale(sf::Vector2f(0.73f, 0.8f));

    Texture tauto;
    tauto.loadFromFile("recursos/auto1.png");
    Sprite sauto(tauto);
    sauto.setScale(Vector2f(1.f, 1.f));
    sauto.scale(Vector2f(0.08f, 0.08f));
    sauto.setPosition(70.f, 340.f);
    sauto.rotate(180.f);

    Texture tautoEnemigo;
    tautoEnemigo.loadFromFile("recursos/auto3.png");
    float speed = 0.052;
    Sprite sautoEnemigo(tautoEnemigo);
    sautoEnemigo.setScale(sf::Vector2f(1.f, 1.f));
    sautoEnemigo.scale(sf::Vector2f(0.08f, 0.08f));
    sautoEnemigo.setPosition(70.f, 265.f);
    sautoEnemigo.rotate(180.f);


    Texture velT;
    velT.loadFromFile("recursos/vel.png");
    Sprite velS(velT);
    velS.setScale(Vector2f(1.f, 1.f));
    velS.scale(Vector2f(0.2f, 0.8f));
    velS.setPosition(540.f, 436.f);

    Texture velAT;
    velAT.loadFromFile("recursos/velA.png");
    Sprite velAS(velAT);
    velAS.setScale(Vector2f(1.f, 1.f));
    velAS.scale(Vector2f(0.6f, 0.3f));
    velAS.setPosition(635.f, 441.f);

    Texture velVT;
    velVT.loadFromFile("recursos/velV.png");
    Sprite velVS(velVT);
    velVS.setScale(Vector2f(1.f, 1.f));
    velVS.scale(Vector2f(0.6f, 0.3f));
    velVS.setPosition(661.f, 441.f);

    Texture velRT;
    velRT.loadFromFile("recursos/velR.png");
    Sprite velRS(velRT);
    velRS.setScale(Vector2f(1.f, 1.f));
    velRS.scale(Vector2f(0.6f, 0.3f));
    velRS.setPosition(682.f, 441.f);

    Texture gearT;
    gearT.loadFromFile("recursos/gear.png");
    Sprite gearS(gearT);
    gearS.setPosition(130.f, 436.f);

    string txt = "D";
    Font font;
    font.loadFromFile("SFML/arial.ttf");
    Text ins(txt, font);
    ins.setCharacterSize(30);
    ins.setStyle(Text::Bold);
    ins.setFillColor(Color::White);
    ins.setPosition(236.f, 465.f);

    Texture metaT;
    metaT.loadFromFile("recursos/meta.png");
    Sprite metaS(metaT);
    metaS.setScale(Vector2f(1.f, 1.f));
    metaS.scale(Vector2f(0.78f, 0.8f));
    metaS.setPosition(1100.f, 188.f);

    while (game.isOpen()) {
        Event event;
        while (game.pollEvent(event)) {
            if (event.type == Event::Closed)
                game.close();
        }
        game.clear();
        game.draw(sfondo);
        game.draw(sautoEnemigo);
        game.draw(sauto);
        game.draw(velAS);
        game.draw(velVS);
        game.draw(velRS);
        game.draw(velS);
        game.draw(gearS);
        game.draw(ins);
        game.draw(metaS);
        game.display();

        int a=3;

        while (a) {
            sauto.move((0.04f)+speedE, 0.f);
            sautoEnemigo.move((speed), 0.f);
            velS.move(0.02f, 0.f);

            if (sauto.getGlobalBounds().intersects(metaS.getGlobalBounds())) {
                sauto.setPosition(70.f, 340.f);
                sautoEnemigo.setPosition(70.f, 265.f);
                velS.setPosition(540.f, 436.f);
                gearS.setPosition(130.f, 436.f);
                speedE = 0;
                game.close();
                juego3();
            };

            if (sautoEnemigo.getGlobalBounds().intersects(metaS.getGlobalBounds())) {
                sauto.setPosition(70.f, 340.f);
                sautoEnemigo.setPosition(70.f, 265.f);
                velS.setPosition(540.f, 436.f);
                gearS.setPosition(130.f, 436.f);
                speedE = 0;
                game.close();
                juego();
            };

            if (velS.getGlobalBounds().intersects(velRS.getGlobalBounds())) {
                velS.setPosition(682.f, 436.f);
            }


            if (event.type == Event::TextEntered) {
                if (Keyboard::isKeyPressed(Keyboard::F)) {
                    game.close();
                } else if (Keyboard::isKeyPressed(Keyboard::Num1) && velS.getGlobalBounds().intersects(velAS.getGlobalBounds())) {
                    speedE = 0.008;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num2) && velS.getGlobalBounds().intersects(velAS.getGlobalBounds())) {
                    speedE = 0.008;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 500.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num3) && velS.getGlobalBounds().intersects(velAS.getGlobalBounds())) {
                    speedE = 0.008;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(178.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num1) && velS.getGlobalBounds().intersects(velVS.getGlobalBounds())) {
                    speedE = 0.01;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num2) && velS.getGlobalBounds().intersects(velVS.getGlobalBounds())) {
                    speedE = 0.02;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 500.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num3) && velS.getGlobalBounds().intersects(velVS.getGlobalBounds())) {
                    speedE = 0.03;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(178.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num1) && velS.getGlobalBounds().intersects(velRS.getGlobalBounds())) {
                    speedE = -0.02;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num2) && velS.getGlobalBounds().intersects(velRS.getGlobalBounds())) {
                    speedE = -0.02;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 500.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num3) && velS.getGlobalBounds().intersects(velRS.getGlobalBounds())) {
                    speedE = -0.02;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(178.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::R)) {
                    sauto.setPosition(70.f, 340.f);
                    sautoEnemigo.setPosition(70.f, 265.f);
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 436.f);
                    speedE = 0;
                }
            }
            a--;
        }
    }
};


void juego3() {
    RenderWindow game(VideoMode(1200, 550), "Race");
    float speedE = 0;
    // Fondo de pantalla
    Texture tfondo;
    tfondo.loadFromFile("recursos/fondoCarrera.png");
    tfondo.setSmooth(true);
    Sprite sfondo(tfondo);
    sfondo.setScale(sf::Vector2f(1.f, 1.f));
    sfondo.scale(sf::Vector2f(0.73f, 0.8f));

    Texture tauto;
    tauto.loadFromFile("recursos/auto1.png");
    Sprite sauto(tauto);
    sauto.setScale(Vector2f(1.f, 1.f));
    sauto.scale(Vector2f(0.08f, 0.08f));
    sauto.setPosition(70.f, 340.f);
    sauto.rotate(180.f);

    Texture tautoEnemigo;
    tautoEnemigo.loadFromFile("recursos/auto4.png");
    float speed = 0.0561;
    Sprite sautoEnemigo(tautoEnemigo);
    sautoEnemigo.setScale(sf::Vector2f(1.f, 1.f));
    sautoEnemigo.scale(sf::Vector2f(0.08f, 0.08f));
    sautoEnemigo.setPosition(70.f, 265.f);
    sautoEnemigo.rotate(180.f);

    Texture velT;
    velT.loadFromFile("recursos/vel.png");
    Sprite velS(velT);
    velS.setScale(Vector2f(1.f, 1.f));
    velS.scale(Vector2f(0.2f, 0.8f));
    velS.setPosition(540.f, 436.f);

    Texture velAT;
    velAT.loadFromFile("recursos/velA.png");
    Sprite velAS(velAT);
    velAS.setScale(Vector2f(1.f, 1.f));
    velAS.scale(Vector2f(0.6f, 0.3f));
    velAS.setPosition(635.f, 441.f);

    Texture velVT;
    velVT.loadFromFile("recursos/velV.png");
    Sprite velVS(velVT);
    velVS.setScale(Vector2f(1.f, 1.f));
    velVS.scale(Vector2f(0.6f, 0.3f));
    velVS.setPosition(661.f, 441.f);

    Texture velRT;
    velRT.loadFromFile("recursos/velR.png");
    Sprite velRS(velRT);
    velRS.setScale(Vector2f(1.f, 1.f));
    velRS.scale(Vector2f(0.6f, 0.3f));
    velRS.setPosition(682.f, 441.f);

    Texture gearT;
    gearT.loadFromFile("recursos/gear.png");
    Sprite gearS(gearT);
    gearS.setPosition(130.f, 436.f);

    string txt = "D";
    Font font;
    font.loadFromFile("SFML/arial.ttf");
    Text ins(txt, font);
    ins.setCharacterSize(30);
    ins.setStyle(Text::Bold);
    ins.setFillColor(Color::White);
    ins.setPosition(236.f, 465.f);

    Texture metaT;
    metaT.loadFromFile("recursos/meta.png");
    Sprite metaS(metaT);
    metaS.setScale(Vector2f(1.f, 1.f));
    metaS.scale(Vector2f(0.78f, 0.8f));
    metaS.setPosition(1100.f, 188.f);

    while (game.isOpen()) {
        Event event;
        while (game.pollEvent(event)) {
            if (event.type == Event::Closed)
                game.close();
        }
        game.clear();
        game.draw(sfondo);
        game.draw(sautoEnemigo);
        game.draw(sauto);
        game.draw(velAS);
        game.draw(velVS);
        game.draw(velRS);
        game.draw(velS);
        game.draw(gearS);
        game.draw(ins);
        game.draw(metaS);
        game.display();

        int a=3;

        while (a) {
            sauto.move((0.04f)+speedE, 0.f);
            sautoEnemigo.move((speed), 0.f);
            velS.move(0.02f, 0.f);

            if (sauto.getGlobalBounds().intersects(metaS.getGlobalBounds())) {
                sauto.setPosition(70.f, 340.f);
                sautoEnemigo.setPosition(70.f, 265.f);
                velS.setPosition(540.f, 436.f);
                gearS.setPosition(130.f, 436.f);
                speedE = 0;
                game.close();
            };

            if (sautoEnemigo.getGlobalBounds().intersects(metaS.getGlobalBounds())) {
                sauto.setPosition(70.f, 340.f);
                sautoEnemigo.setPosition(70.f, 265.f);
                velS.setPosition(540.f, 436.f);
                gearS.setPosition(130.f, 436.f);
                speedE = 0;
                game.close();
                juego2();
            };

            if (velS.getGlobalBounds().intersects(velRS.getGlobalBounds())) {
                velS.setPosition(682.f, 436.f);
            }


            if (event.type == Event::TextEntered) {
                if (Keyboard::isKeyPressed(Keyboard::F)) {
                    game.close();
                } else if (Keyboard::isKeyPressed(Keyboard::Num1) && velS.getGlobalBounds().intersects(velAS.getGlobalBounds())) {
                    speedE = 0.008;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num2) && velS.getGlobalBounds().intersects(velAS.getGlobalBounds())) {
                    speedE = 0.008;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 500.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num3) && velS.getGlobalBounds().intersects(velAS.getGlobalBounds())) {
                    speedE = 0.008;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(178.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num1) && velS.getGlobalBounds().intersects(velVS.getGlobalBounds())) {
                    speedE = 0.01;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num2) && velS.getGlobalBounds().intersects(velVS.getGlobalBounds())) {
                    speedE = 0.02;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 500.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num3) && velS.getGlobalBounds().intersects(velVS.getGlobalBounds())) {
                    speedE = 0.03;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(178.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num1) && velS.getGlobalBounds().intersects(velRS.getGlobalBounds())) {
                    speedE = -0.02;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num2) && velS.getGlobalBounds().intersects(velRS.getGlobalBounds())) {
                    speedE = -0.02;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 500.f);

                } else if (Keyboard::isKeyPressed(Keyboard::Num3) && velS.getGlobalBounds().intersects(velRS.getGlobalBounds())) {
                    speedE = -0.02;
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(178.f, 436.f);

                } else if (Keyboard::isKeyPressed(Keyboard::R)) {
                    sauto.setPosition(70.f, 340.f);
                    sautoEnemigo.setPosition(70.f, 265.f);
                    velS.setPosition(540.f, 436.f);
                    gearS.setPosition(130.f, 436.f);
                    speedE = 0;
                }
            }
            a--;
        }
    }
};


/*
g++ -c main.cpp
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app

*/
