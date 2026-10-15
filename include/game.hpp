#pragma once

#include <vector>
#include <pilhaIngrediente.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

/*
    Classe que age como a "game engine",
    classe "Wrapper".
*/
class Game
{
    private:
        //Variáveis

        //Objetos do Jogo
        std::vector<std::unique_ptr<Ingrediente>> ingredientes;
        pilhaIngrediente stackIngrediente;        

        //Tela
        sf::RenderWindow *window;
        sf::Event ev;
        sf::VideoMode videoMode;

        //Posições do Mouse
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;
        
        //Funções Privadas
        void initVariables();
        void initIngredientes();
        void initWindow();
    public:
        //Construtor e Destrutor
        Game();
        virtual ~Game();

        //Getters
        const bool getWindowIsOpen() const;

        //Funções
        void update();
        void render();
        void clickIngredientes(const sf::Vector2f& pos);
        void updateMousePositions();
        void updateIngredientes();
        void pollEvents();
};