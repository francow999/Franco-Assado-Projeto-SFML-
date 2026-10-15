#include <ingrediente.hpp>
#include <stack>

class pilhaIngrediente{
    public:
        void push(std::unique_ptr<Ingrediente> ingrediente);
        void pop(std::unique_ptr<Ingrediente> ingrediente);
        const Ingrediente* top() const;
        bool isEmpty() const;
    private:
        std::stack<std::unique_ptr<Ingrediente>> ingredientes;
};