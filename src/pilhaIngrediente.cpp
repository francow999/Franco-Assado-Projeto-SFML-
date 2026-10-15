#include<pilhaIngrediente.hpp>

//Push e pop de Ingredientes
void pilhaIngrediente::push(std::unique_ptr<Ingrediente> ingrediente) {
    this->ingredientes.push(std::move(ingrediente));
}

void pilhaIngrediente::pop(std::unique_ptr<Ingrediente> ingrediente) {
    if (!this->ingredientes.empty()) {
        this->ingredientes.pop();
    }
}

bool pilhaIngrediente::isEmpty() const {
    return this->ingredientes.empty();
}

const Ingrediente* pilhaIngrediente::top() const
{
    if (this->ingredientes.empty()) {
        return nullptr; // Retorna nullptr se a pilha estiver vazia
    }
    return this->ingredientes.top().get();
}