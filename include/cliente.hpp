#include <pilhaIngrediente.hpp>
#include <stack>
#include <queue>

class Cliente
{
    private:
        //Pilha de Ingredientes do Cliente
        //A pilha irá usar o ID do ingrediente para representar o pedido do cliente
        //Muito mais fácil do que usar uma pilha de ponteiros para os ingredientes, 
        //pois o cliente não precisa saber a posição do ingrediente na tela, apenas o ID
        std::vector<int> pedido;
        std::queue<int> falas; // Fila de falas do cliente
        int qtdeIngredientes;
        int idPersonagem; // ID do personagem do cliente 
    public:
        void setIdPersonagem(int id);
        int getIdPersonagem() const;
        int getTamPilha() const;
        std::vector<int> getPedido() const;
        bool temFala() const;
        int proximaFala();
        Cliente();
};