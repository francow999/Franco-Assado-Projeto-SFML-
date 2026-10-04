#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
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

        //Tela
        sf::RenderWindow *window;
        sf::Event ev;
        sf::VideoMode videoMode;

        //Posições do Mouse
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;
        
        //Funções Privadas
        void initVariables();
        void initWindow();
        void initIngredientes();
    public:
        //Construtor e Destrutor
        Game();
        virtual ~Game();

        //Getters
        const bool getWindowIsOpen() const;

        //Funções
        void update();
        void render();
        void updateMousePositions();
        void pollEvents();
};