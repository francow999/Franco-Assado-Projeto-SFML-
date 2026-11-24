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
o projeto!

## Como o Jogo Funciona?
É simples: Sempre terá alguns clientes aparecendo, e você deve atendê-los memorizando a comanda. Após o cliente terminar de fazer o pedido, você monta o lanche e entrega para ele clicando no botão verde, pontuando um score. Caso você tenha usado um ingrediente errado, basta clicar no botão vermelho para remover o elemento do topo. Caso erre, você automaticamente perde!
Tente acertar o máximo possível para se gabar de quantas comandas você conseguiu concluir.
Esc: Sai do jogo.
Espaço: Reinicia caso tenha dado Game-Over.

## Como Rodar o Jogo?
Se você estiver usando Linux:
Acesse o repositório clonado e digite os seguintes comandos no terminal:

> cmake -S . -B build <br>
> cmake --build build <br>
> ./build/sfml-app <br>

Se você estiver usando Windows:

1. Instale o que o projeto precisa

- Git: https://git-scm.com. É obrigatório mesmo que você baixe o ZIP, porque o CMake usa o git para baixar o SFML.
- CMake (3.16 ou mais novo): https://cmake.org/download. No instalador, marque "Add CMake to the system PATH".
- Um compilador C++: instale o Visual Studio 2022 Community (ou só as Build Tools) e marque a carga de trabalho "Desenvolvimento para desktop com C++".

2. Baixe o projeto num caminho curto e sem acentos, por exemplo C:\dev. O Windows limita o tamanho dos caminhos, e a compilação do SFML cria pastas profundas.

> cd C:\dev
> git clone https://github.com/francow999/Franco-Assado-Projeto-SFML-.git
> cd Franco-Assado-Projeto-SFML-

3. Compile. Abra o Developer PowerShell for VS 2022 ou o PowerShell comum e rode:

> cmake -S . -B build
> cmake --build build --config Release

A primeira compilação baixa e compila o SFML, então precisa de internet e leva alguns minutos.

4. Execute. O executável fica em build\Release, junto com as pastas e DLLs de que precisa:

> cd build\Release
> .\sfml-app.exe

Também funciona com duplo clique em sfml-app.exe dentro dessa pasta. Sempre execute a partir dela, porque o jogo procura assets ao lado do executável.