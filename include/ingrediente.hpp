#include <SFML/Graphics.hpp>
#include <memory>

class Ingrediente{
    public:
        Ingrediente(std::string vTextura, std::string vNome, int vId, sf::Vector2f vPosicao);
        ~Ingrediente();
        void setTextura(std::string s);
        void setNome(std::string s);
        std::string getNome() const;
        std::string getCaminho() const;
        const sf::Sprite& getSprite() const;
        //const sf::Texture& getTextura() const;
        int getId() const;
        sf::Vector2f getPosicao() const;
    private:
        std::unique_ptr<sf::Texture> textura;
        std::unique_ptr<sf::Sprite> sprite;
        sf::Vector2f posicao;
        std::string nome;
        std::string caminho;
        int const id;
};