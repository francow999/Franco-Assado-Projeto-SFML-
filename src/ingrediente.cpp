#include <ingrediente.h>

Ingrediente::Ingrediente(std::string vTextura, std::string vNome, int vId) : id(vId)
{
    this->nome = vNome;
    this->textura.loadFromFile(vTextura);
    this->sprite.setTexture(textura);
}

//Nome do Ingrediente
void Ingrediente::setNome(std::string s)
{
    this->nome = s;
    return;
}

std::string Ingrediente::getNome() const
{
    return this->nome;
}

//Textura (Emenda com o sprite)
void Ingrediente::setTextura(std::string vTextura)
{
    this->textura.loadFromFile(vTextura);
    this->sprite.setTexture(textura);
    return;
}