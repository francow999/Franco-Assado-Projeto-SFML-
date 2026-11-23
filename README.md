# Projeto de Faculdade - Franco Assado
Este é um projeto de um jogo 2D desenvolvido com o objetivo de demonstrar algumas estruturas
de dados. Mais especificamente, como as pilhas, filas e estruturas não-lineares funcionam. Inspirado em jogos de flash, principalmente Pappa's Burgueria. 

## Requisitos
Certifique-se de que você tenha as seguintes ferramentas instaladas:

- Git
- CMake (3.16 para frente).
- Um compilador C++
- Quaisquer pacotes que o Linux exigir para a execução do SFML.

<br>

Detalhe: O jogo foi feito usando o SFML na versão 2.6.1. Versões posteriores podem quebrar
o projeto!.

## Como o Jogo Funciona?
É simples: Sempre terá alguns clientes aparecendo, e você deve atendê-los memorizando a comanda. Após o cliente terminar de fazer o pedido, você monta o lanche e entrega para ele clicando no botão verde, pontuando um score. Caso você tenha usado um ingrediente errado, basta clicar no botão vermelho para remover o elemento do topo. Caso erre, você automaticamente perde!
Esc: Sai do jogo.
Espaço ou Enter: Reinicia caso tenha dado Game-Over.

## Como Rodar o Jogo?
Se você estiver usando Linux:
Acesse o repositório clonado e digite os seguintes comandos no terminal:

> cmake -S . -B build <br>
> cmake --build build <br>
> ./build/sfml-app <br>

Se você estiver usando Windows:
