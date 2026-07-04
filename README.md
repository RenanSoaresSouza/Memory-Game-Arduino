# Memory-Game
jogo da memória feito em **PlatformIO, Arduino e C++**, um jogo da memória cujo o jogo ira fornecer e mostrar uma sequência de luzes
e o usuário deverá seguir essa sequência sem errar nenhum passo, o jogador deverá memorizar todos os passos para que ele possa continuar o Jogo,
o jogo irá continuar acrecentando passos até que o jogador acabe errando, e por fim, reniciando o jogo.

Foco de Aprendizado:
- Arduino
- C++
- POO
- Circuitos Eletrônicos
- Hardware
## Circuito Elétrico
Busquei utilizar mais componentes eletrônicos a fim de entender melhor os seus funcionamentos e suas utilidades na prática.

Componentes Utilizados:
- 4 Leds
- 4 Diodos retificadores (1N4007)
- 4 Resistores de 330Ω
- 4 Botões
- 1 Resistor de 1kΩ
- 1 Buzzer Ativo de 5V
- 1 Transistor BJT NPN (2N2222)
- 1 Arduino UNO R3 CH340
### Esquemático do circuito

![image](img/Schematic_Memory-Game-Sheet_2026-07-03.png)

## Arquitetura do Projeto
~~~~
  ├── .vscode/        # Extensões do Visual Studio Code
  ├── img/            # Imagem do Circuito Elétrico
  ├── include/        # Bibliotecas incluidas no projeto 
  ├── lib/            # arquivos .h utilizados no projeto 
  ├── src/            # pasta principal do programa
  └── test/           # pasta reservada pelo PlatformIO para testes
~~~~
## Como Rodar Localmente
Você precisará ter instalado:
- Visual Studio Code
- git
- PlatformIO IDE (extensão do Visual Studio Code)

Clone o repositório com
~~~
git clone https://github.com/RenanSoaresSouza/Memory-Game.git
~~~
Abra a Platform IDE no Visual Studio Code e depois coloque na placa com as devidas configurações.

