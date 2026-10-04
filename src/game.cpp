#include <game.h>
#include <ingrediente.h>
#include <iostream>
#include <string>

//Funções Privadas
void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 1000;
    this->window = new sf::RenderWindow(this->videoMode, "Franco Assado", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

/*
void Game::initIngredientes()
{
    Ingrediente paoSola;
    paoSola.setNome("Sola do Pao");
    paoSola.setTextura("./assets/bunback.png");    
    return;
}
*/

//Construtor e Destrutor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initIngredientes();
}

Game::~Game()
{
    delete this->window;
}

const bool Game::getWindowIsOpen() const
{
    return this->window->isOpen();
}

//Funções

void Game::pollEvents()
{
    //Event Polling
    while (this->window->pollEvent(ev)) {
        switch(this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                {
                      this->window->close();
                }
                break;
            }
        }
}

void Game::update()
{
    this->pollEvents();

    this->updateMousePositions();
}

void Game::render()
{
    /*
        Renderização:
        - Limpa a tela antiga
        - Renderiza os objetos novos
        - Faz o display na tela
    */

    //Limpa a tela antiga(Preto por padrão)
    this->window->clear();

    //"Desenha" os objetos novos do jogo

    this->window->display();
}

void Game::updateMousePositions()
{
    /*
        @ return void;
        - Atualiza a posição do mouse em relação à tela do jogo (Vector2i);
    */

    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}
