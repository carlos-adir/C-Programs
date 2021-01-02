# Calculadora

## Objetivo

Implementar em C uma calculadora com o modos:

- **Expressão literal** tal como ```3+4*(5+2)``` 
- [**RPN**][wikipedia_rpn] tal como ``` 5 2 + 4 * 3 +``` 

Para melhor compreensão, recomendo olhar o arquivo ```Report.pdf``` que mostra bem do que se trata e exemplos de como utilizar

## Codigo

Foi utilizado alocação dinâmica de memória com ```malloc``` para armazenar as pilhas.

Os seguintes arquivos são responsáveis por:

* ```entrada.h```: Lê o que o usuário digita através do teclado, sem precisar apertar enter
* ```data.h```: Contém o tipo basico de número(no caso, usado ```float```) e suas operações matemáticas
* ```expressao.h```: Tem as funções para transformar uma expressão matemática e colocar no modo **RPN**
* ```rpn.h```: Tem as funções para somar pilhas
* ```pilha_char.h```: Contém o básico para criar uma pilha de caracteres
* ```pilha_num.h```: Contém o básico para criar uma pilha de números.

## Como rodar

Em linux, basta digitar o comando ```make``` no terminal estando dentro desta pasta.
Ele compilará o código usando o ```gcc``` e em seguida irá executa-lo usando o ```valgrind``` para achar falhas na memória.

Para sair do programa, basta pressionar o botão ```Esc```.


[wikipedia_rpn]: https://pt.wikipedia.org/w/index.php?title=Nota%C3%A7%C3%A3o_polonesa_inversa&oldid=59205853