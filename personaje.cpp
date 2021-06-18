#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

using namespace std;
using namespace sf;

class player {

	string playerClass;
	float speed, attack;

public:
	int hp, shiftTime;

	player(int choice) {
		if (choice == 1) {
			playerClass = "Warrior";
			speed = 1;
			attack = 60;
			hp = 190;
			shiftTime = 3;
			Texture autoT;
            autoT.loadFromFile("recursos/auto2.jpg");
            autoT.setSmooth(true);
            Sprite autoS(autoT);
            autoS.setScale(sf::Vector2f(1.f, 2.f));
            autoS.scale(sf::Vector2f(0.5f, 0.3f));
		}//if 1
		if (choice == 2) {
			playerClass = "Wizard";
			speed = 1.2;
			attack = 20;
			hp = 385;
			shiftTime = 2;
			Texture autoT;
            autoT.loadFromFile("recursos/auto3.jpg");
            autoT.setSmooth(true);
            Sprite autoS(autoT);
            autoS.setScale(sf::Vector2f(1.f, 2.f));
            autoS.scale(sf::Vector2f(0.5f, 0.3f));
		}//if 2
		if (choice == 3) {
			playerClass = "Archer";
			speed = 1.3;
			attack = 40;
			hp = 949;
			shiftTime = 1;
			Texture autoT;
            autoT.loadFromFile("recursos/auto4.jpg");
            autoT.setSmooth(true);
            Sprite autoS(autoT);
            autoS.setScale(sf::Vector2f(1.f, 2.f));
            autoS.scale(sf::Vector2f(0.5f, 0.3f));
		}//if 3
	}

	string printClass() {
		return playerClass;
	}
};
