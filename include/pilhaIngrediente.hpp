#include <ingrediente.hpp>
#include <stack>
#include <vector>

class pilhaIngrediente{
    public:
        void push(std::unique_ptr<Ingrediente> ingrediente);
        void pop();
        const Ingrediente* top() const;
        int size() const;
        bool isEmpty() const;
        void desenhar(sf::RenderTarget& alvo, sf::Vector2f base, float passo) const;
        std::vector<int> ids() const;
    private:
        std::vector<std::unique_ptr<Ingrediente>> ingredientes;
};