#include<game.h>

int main() {
    //Inicializar a game engine:
    Game game;
    
    //Game Loop
    while (game.getWindowIsOpen()) {
          
        //Update
        game.update();
        //Render
        game.render();
    }

    //Fim da aplicação
    return 0;
}
