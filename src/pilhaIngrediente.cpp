#include<pilhaIngrediente.hpp>

//Push e pop de Ingredientes
void pilhaIngrediente::push(std::unique_ptr<Ingrediente> ingrediente) {
    this->ingredientes.push_back(std::move(ingrediente));
}

void pilhaIngrediente::pop(std::unique_ptr<Ingrediente> ingrediente) {
    if (!this->ingredientes.empty()) {
        this->ingredientes.pop_back();
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
    return this->ingredientes.back().get();
}

void pilhaIngrediente::desenhar(sf::RenderTarget& alvo, sf::Vector2f base, float passo) const {
    float y = base.y;
    for (const auto& ingrediente : this->ingredientes) {
        sf::Sprite sprite = ingrediente->getSprite();
        sprite.setPosition(base.x, y);
        alvo.draw(sprite);
        y -= passo; // Incrementa a posição y para o próximo ingrediente
    }
}