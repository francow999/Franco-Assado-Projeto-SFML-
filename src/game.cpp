#include <game.hpp>
#include <iostream>
#include <string>
//Funções Privadas
void Game::initVariables()
{
    this->window = nullptr;

    //double width = this->ingredientes[0]->getSprite().getGlobalBounds().width;
    //double height = this->ingredientes[0]->getSprite().getGlobalBounds().height;
}

void Game::initIngredientes()
{
    this->ingredientes.push_back(std::make_unique<Ingrediente>("./assets/sprites/bunTop.png", "Topo do Pao", 1, sf::Vector2f(100.0f, 100.0f)));
    this->ingredientes.push_back(std::make_unique<Ingrediente>("./assets/sprites/tomato.png", "Tomate", 6, sf::Vector2f(100.0f, 200.0f)));
    this->ingredientes.push_back(std::make_unique<Ingrediente>("./assets/sprites/onions.png", "Cebola", 7, sf::Vector2f(100.0f, 150.0f)));
    this->ingredientes.push_back(std::make_unique<Ingrediente>("./assets/sprites/lettuce.png", "Alface", 5, sf::Vector2f(100.0f, 300.0f)));
    this->ingredientes.push_back(std::make_unique<Ingrediente>("./assets/sprites/cheese.png", "Queijo", 4, sf::Vector2f(100.0f, 250.0f)));
    this->ingredientes.push_back(std::make_unique<Ingrediente>("./assets/sprites/patty.png", "Carne", 3, sf::Vector2f(100.0f, 350.0f)));
    this->ingredientes.push_back(std::make_unique<Ingrediente>("./assets/sprites/bunBottom.png", "Sola do Pao", 2, sf::Vector2f(100.0f, 400.0f)));
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 1000;
    this->window = new sf::RenderWindow(this->videoMode, "Franco Assado", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

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
            case sf::Event::MouseButtonPressed:
                if (this->ev.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f pos = this->window->mapPixelToCoords({this->ev.mouseButton.x, this->ev.mouseButton.y});
                    this->clickIngredientes(pos);

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

    this->window->draw(this->ingredientes[0]->getSprite());
    this->window->draw(this->ingredientes[2]->getSprite());
    this->window->draw(this->ingredientes[3]->getSprite());
    this->window->draw(this->ingredientes[4]->getSprite());
    this->window->draw(this->ingredientes[5]->getSprite());
    this->window->draw(this->ingredientes[6]->getSprite());
    this->window->draw(this->ingredientes[1]->getSprite());

    //Faz o display na tela
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

void Game::clickIngredientes(const sf::Vector2f& pos)
{
    for (const auto& ingrediente : this->ingredientes)
    {
        if (ingrediente->getSprite().getGlobalBounds().contains(pos))
        {
            std::cout << "Ingrediente clicado: " << ingrediente->getNome() << "\n";
            this->stackIngrediente.push(std::make_unique<Ingrediente>(
                ingrediente->getCaminho(), ingrediente->getNome(),
                ingrediente->getId(), ingrediente->getPosicao()
            ));
            std::cout << "Topo da pilha: " << this->stackIngrediente.top()->getNome() << std::endl;
        }
    }
}