#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Text.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "menu.cpp"

using namespace sf;
using namespace std;

int main()
{
    Menu();
    return 0;
}

class personaje {
    public:
        personaje();
    private:

};

personaje::personaje() {
    string path;
    for (int i=0; i<3; i++) {
        path = "auto"+ to_string(i+1);
        //vehiculo[i].loadFromFile(path);
    }
};




/*
g++ -c main.cpp
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app

*/
