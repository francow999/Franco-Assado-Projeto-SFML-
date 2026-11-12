#include <vector>
#include <cliente.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum class Estado {Revelando, Montando, Resultado, GameOver};

/*
    Classe que age como a "game engine",
    classe "Wrapper".
*/
class Game
{
    private:
        //Variáveis
        bool debugHitbox;

        //Objetos do Jogo
        std::vector<std::unique_ptr<Ingrediente>> ingredientes;
        pilhaIngrediente stackIngrediente;        
        Cliente cliente;
        sf::Sprite spritePlate;
        sf::Texture texturePlate;
        std::vector<int> falados;
        float intervaloFalas = 1.5f; // Intervalo de tempo entre falas em segundos
        std::vector<sf::Texture> texturasClientes;
        sf::Sprite spriteCliente;
        sf::Sprite spriteDesfazer; //Botões
        sf::Texture textureDesfazer;
        sf::Sprite spriteEnviar;
        sf::Texture textureEnviar;
        bool acertou = false;

        //Tela
        sf::RenderWindow *window;
        sf::Event ev;
        sf::VideoMode videoMode;

        //Posições do Mouse
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;
        
        //States e clock
        Estado estadoAtual;
        sf::Clock clock;
        
        //Máquina de Estados do jogo
        void mudarEstado(Estado novoEstado);
        void updateRevelando();
        void updateMontando();
        void updateResultado();

        //Funções Privadas
        void enviarLanche();
        void novoCliente();
        void initVariables();
        void initIngredientes();
        void initWindow();
        void initClientes();
        void initBotoes();
    public:
        //Construtor e Destrutor
        Game();
        virtual ~Game();

        //Getters
        const bool getWindowIsOpen() const;

        //Funções
        void desenharBalao(); // Função para desenhar o balão de fala do cliente
        void update();
        void render();
        void clickIngredientes(const sf::Vector2f& pos);
        void updateMousePositions();
        void updateIngredientes();
        void pollEvents();
};