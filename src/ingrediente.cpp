#pragma once
#include <ingrediente.hpp>

Ingrediente::Ingrediente(std::string vTextura, std::string vNome, int vId, sf::Vector2f vPosicao) : id(vId)
{
    this->nome = vNome;
    this->caminho = vTextura;
    this->textura = std::make_unique<sf::Texture>();
    this->sprite = std::make_unique<sf::Sprite>();
    this->textura->loadFromFile(vTextura);
    this->sprite->setScale(3.0f, 3.0f);
    this->sprite->setTexture(*this->textura);
    this->posicao = vPosicao;
    this->sprite->setPosition(this->posicao);
}

Ingrediente::~Ingrediente()
{
    // Os unique_ptr lidam com a limpeza automática
    // Explicação: unique_ptr são ponteiros inteligentes
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
    this->textura->loadFromFile(vTextura);
    this->sprite->setTexture(*this->textura);
    return;
}

//Sprite (Objeto que será desenhado na tela)
const sf::Sprite& Ingrediente::getSprite() const{
    return *this->sprite;
}

/*
const sf::Texture& Ingrediente::getTextura() const {
    // Implementação futura, se necessário
    return *this->textura;
}
*/
std::string Ingrediente::getCaminho() const
{
    return this->caminho;
}

int Ingrediente::getId() const {
    return this->id;
}

sf::Vector2f Ingrediente::getPosicao() const {
    return this->posicao;
}