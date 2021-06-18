#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class juego {
  public:
    juego(int resolucionX, int resolucionY, string titulo);
    void dibujar();
    void gameLoop();
  private:
    RenderWindow * ventana1;
    int fps;
};
