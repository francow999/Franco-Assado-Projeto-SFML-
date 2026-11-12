#include<cliente.hpp>
#include <cstdlib> 

Cliente::Cliente(){
    srand(time(0));                          // Inicializa a semente do gerador de números aleatórios
    this->qtdeIngredientes = rand() % 6 + 1; // Gera um número entre 1 e 6
    //this->idPersonagem = rand() % 3 + 1;      // Gera um número entre 1 e 3 para o ID do personagem
    this->idPersonagem = 1; // Para teste, define o ID do personagem como 1
    this->pedido.push_back(1);                    // Adiciona o ID do ingrediente "Pão de cima" (ID 1)
    for (int i = 0; i < this->qtdeIngredientes; ++i) {
        int ingredienteId = rand() % 5 + 3;  // Gera um número entre 3 e 7
        this->pedido.push_back(ingredienteId);    // Adiciona o ID do ingrediente aleatório
    }
    this->pedido.push_back(2);                    // Adiciona o ID do ingrediente "Pão de baixo" (ID 2)
    this->qtdeIngredientes += 2;             // Adiciona 2 para contar os pães

    for (int id = qtdeIngredientes-1; id >= 0; --id)
    {
        this->falas.push(pedido[id]); // Adiciona o ID do ingrediente à fila de falas
    }
}

int Cliente::getTamPilha() const {
    return this->pedido.size();
}

std::vector<int> Cliente::getPedido() const {
    return this->pedido;
}

bool Cliente::temFala() const {
    return !this->falas.empty();
}

int Cliente::proximaFala() {
    int id = this->falas.front();
    this->falas.pop();
    return id;
}

int Cliente::getIdPersonagem() const {
    return this->idPersonagem;
}