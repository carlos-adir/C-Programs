Aqui existem dois jogos tetris, um roda no terminal e outro já possui interface gráfica.

# Tetris

O arquivo para rodar o tetris no terminal é o ```tetris.c``` e pode ser compilado e executado através dos comandos:

```
gcc -Wall -ansi tetris.c -o jogo
./jogo
```

# Tetris com interface

O arquivo para rodar o tetris com interface é o ```tetris_interface.c``` e pode ser compilado e executado através dos comandos:

```
gcc -Wall -ansi tetris.c -o jogo -lSDL
```

Ele utiliza a biblioteca [SDL](https://www.libsdl.org/) e pode ser executado apenas clicando no executavel ```jogo``` dentro da pasta