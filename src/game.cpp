#include<game.hpp>
#include<iostream>
#include<string>
#include<algorithm>

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

    this->texturePlate.loadFromFile("./assets/sprites/trayAndPlate.png");
    this->spritePlate.setTexture(this->texturePlate);
    this->spritePlate.setScale(4.0f, 4.0f);
    this->spritePlate.setPosition(420.0f, 450.0f);
}

void Game::initClientes()
{
    const std::vector<std::string> caminhosClientes = {
        "./assets/sprites/AnnoyingDog.png",
        "./assets/sprites/ThwompSM64.png",
        "./assets/sprites/remove.png"
    };

    this->texturasClientes.resize(caminhosClientes.size());
    for (std::size_t i = 0; i < caminhosClientes.size(); ++i) {
        if (!this->texturasClientes[i].loadFromFile(caminhosClientes[i])) {
            std::cerr << "Erro ao carregar a textura do cliente: " << caminhosClientes[i] << std::endl;
        }
    }

    this->spriteCliente.setTexture(this->texturasClientes[this->cliente.getIdPersonagem() - 1]); // Define a textura inicial do cliente
    this->spriteCliente.setScale(0.5f, 0.5f);
    this->spriteCliente.setPosition(620.0f, 40.0f); // Define a posição inicial do cliente
}

void Game::initBotoes()
{
    if (!this->textureDesfazer.loadFromFile("./assets/sprites/remove.png")) {
        std::cerr << "Erro ao carregar a textura do botão Desfazer" << std::endl;
    }
    this->spriteDesfazer.setTexture(this->textureDesfazer);
    this->spriteDesfazer.setScale(3.0f, 3.0f);
    this->spriteDesfazer.setPosition(700.0f, 450.0f);

    if (!this->textureEnviar.loadFromFile("./assets/sprites/send.png")) {
        std::cerr << "Erro ao carregar a textura do botão Enviar" << std::endl;
    }
    this->spriteEnviar.setTexture(this->textureEnviar);
    this->spriteEnviar.setScale(3.0f, 3.0f);
    this->spriteEnviar.setPosition(900.0f, 450.0f);
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 1000;
    this->window = new sf::RenderWindow(this->videoMode, "Franco Assado", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::enviarLanche()
{
    if (this->stackIngrediente.isEmpty()) {
        std::cout << "A pilha de ingredientes está vazia. Não é possível enviar o lanche." << std::endl;
        return;
    }
    this->acertou = (this->stackIngrediente.ids() == this->falados);
    this->mudarEstado(Estado::Resultado);
}

void Game::mudarEstado(Estado novoEstado)
{
    this->estadoAtual = novoEstado;
    this->clock.restart(); // Reinicia o relógio para medir o tempo no novo estado
}

//Construtor e Destrutor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initIngredientes();
    this->initClientes();
    this->initBotoes();
    this->mudarEstado(Estado::Revelando);   
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

void Game::novoCliente()
{
    this->stackIngrediente = pilhaIngrediente(); // Reinicia a pilha de ingredientes
    this->falados.clear(); // Limpa as falas anteriores
    this->cliente = Cliente(); // Cria um novo cliente
    this->spriteCliente.setTexture(this->texturasClientes[this->cliente.getIdPersonagem()]);
    this->mudarEstado(Estado::Revelando); // Muda para o estado de revelação
}

void Game::desenharBalao()
{
    if (this->falados.empty()) {
        return; // Se não houver falas, retorna sem desenhar nada
    }

    float t = this->clock.getElapsedTime().asSeconds();
    const float pause = 0.15f;
    if (t > this->intervaloFalas - pause) {
        return; // Não desenha o balão se estiver no intervalo de pausa
    }
    
    sf::RectangleShape balao(sf::Vector2f(140.0f, 120.0f));
    balao.setPosition(430.0f, 50.0f);
    balao.setFillColor(sf::Color(sf::Color::White));
    balao.setOutlineColor(sf::Color::Black);
    balao.setOutlineThickness(3.0f);
    this->window->draw(balao);

    float k = std::min(t / 0.12f, 1.0f); // Normaliza o tempo para o intervalo de 0 a 1
    float escala = 2.0f * (0.6 + 0.4f * k); // Escala de 1.2 a 2.0

    int id = this->falados.back();
    for (const auto& ingrediente : this->ingredientes)
    {
        if (ingrediente->getId() == id)
        {
            sf::Sprite sprite = ingrediente->getSprite();
            sprite.setPosition(452.0f, 60.0f);
            sprite.setScale(3.0f, 3.0f);
            this->window->draw(sprite);
            break;
        }
    }

    for (std::size_t i = 0; i < this->falados.size(); ++i)
    {
        sf::CircleShape bolinha (5.f);
        bolinha.setFillColor(sf::Color::White);
        bolinha.setOutlineColor(sf::Color::Black);
        bolinha.setPosition(440.f + i * 16.f, 180.f);
        this->window->draw(bolinha);
    }
}   

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
                // pollEvents, dentro do case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::F1) this->debugHitbox = !this->debugHitbox;
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

//Updates

void Game::updateResultado()
{
    if (this->clock.getElapsedTime().asSeconds() >= 1.5f) // 3 segundos
    {
        this->novoCliente(); // Cria um novo cliente e reinicia o jogo
    }
    if (this->acertou) {
        std::cout << "Parabéns! Você acertou o pedido do cliente!" << std::endl;
    } else {
        std::cout << "Que pena! Você errou o pedido do cliente." << std::endl;
        this->mudarEstado(Estado::GameOver);
    }
}

void Game::updateRevelando()
{
    if (this->clock.getElapsedTime().asSeconds() >= this->intervaloFalas) // 3 segundos
    {
        this->clock.restart(); // Reinicia o relógio para medir o tempo no novo estado
        if (this->cliente.temFala())
        {
            int id = this->cliente.proximaFala();
            this->falados.push_back(id);
        }
        else
        {
            this->mudarEstado(Estado::Montando);
        }
    }
}

void Game::updateMontando()
{
    if (this->clock.getElapsedTime().asSeconds() >= 60.0f) // 60 segundos
    {
        this->mudarEstado(Estado::GameOver);
    }
}

void Game::update()
{
    this->pollEvents();
    this->updateMousePositions();

    switch(this->estadoAtual)
    {
        case Estado::Revelando:
            this->updateRevelando();
            break;
        case Estado::Montando:
            this->updateMontando();
            break;
        case Estado::Resultado:
            this->updateResultado();
            break;
        case Estado::GameOver:
            // Implementar lógica de Game Over, se necessário
            break;
    }
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

    this->window->draw(this->spritePlate);

    // DEPURAÇÃO: contorno vermelho das hitboxes
    if (this->debugHitbox) {
        for (const auto& ing : this->ingredientes) {
            sf::FloatRect h = ing->getHitbox();
            sf::RectangleShape r(sf::Vector2f(h.width, h.height));
            r.setPosition(h.left, h.top);
            r.setFillColor(sf::Color::Transparent);
            r.setOutlineColor(sf::Color::Red);
            r.setOutlineThickness(1.f);
            this->window->draw(r);
        }
    }

    this->stackIngrediente.desenhar(*this->window, sf::Vector2f(500.0f, 450.0f), 24.0f);

    if (this->estadoAtual == Estado::Revelando)
    {
        this->desenharBalao();
    }

    if (this->estadoAtual == Estado::Montando || this->estadoAtual == Estado::Revelando)
    {
        this->window->draw(this->spriteCliente);
    }

    this->window->draw(this->spriteDesfazer);
    this->window->draw(this->spriteEnviar);

    //Faz o display na tela
    this->window->display();
}

void Game::clickIngredientes(const sf::Vector2f& pos)
{
    if (this->estadoAtual != Estado::Montando) {
        return; // Não processa cliques se não estiver no estado Montando
    }
    if (this->spriteDesfazer.getGlobalBounds().contains(pos)) {
        this->stackIngrediente.pop(); // Remove o ingrediente do topo da pilha
        return; // Sai da função após desfazer
    }
    if (this->spriteEnviar.getGlobalBounds().contains(pos)) {
        this->enviarLanche(); // Chama a função para enviar o lanche
        return; // Sai da função após enviar
    }
    if (this->stackIngrediente.size() >= 12) {
        return; // Não processa cliques se a pilha estiver cheia
    }
    for (const auto& ingrediente : this->ingredientes)
    {
        if (ingrediente->getHitbox().contains(pos) && this->estadoAtual == Estado::Montando)
        {
            //std::cout << "Ingrediente clicado: " << ingrediente->getNome() << std::endl; //Debug terminal
            this->stackIngrediente.push(std::make_unique<Ingrediente>(
                ingrediente->getCaminho(), ingrediente->getNome(),
                ingrediente->getId(), ingrediente->getPosicao()
            ));
            break; // Sai do loop após encontrar o primeiro ingrediente clicado
        }
    }
}