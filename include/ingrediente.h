#include <SFML/Graphics.hpp>

class Ingrediente{
    public:
        Ingrediente(std::string vTextura, std::string vNome, int vId);
        void setTextura(std::string s);
        void setNome(std::string s);
        std::string getNome() const;
        //void setId(int i);
    private:
        sf::Texture textura;
        sf::Sprite sprite;
        std::string nome;
        int const id;
};