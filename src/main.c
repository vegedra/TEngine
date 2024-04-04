/* Coded by Ivo - 02/04/24 -- Programando um Text Game 

LEMBRETES: (Mais informa��es no .txt)
!= significa 'is not equal to' 
gcc -o JOGO main.c parsexec.c location.c misc.c object.c substantivo.c   -- para compilar  */

#include <stdio.h>  // C standard library 
#include <stdbool.h>  // Adiciona booleans 
#include "parsexec.h"  // importa fun��o criada 
#include <locale.h>  // Para mostrar caracteres especiais - nao vou usar

// Declara variavel estatica (explico o que � em location.c)
static char input[100] = "look around";  // buffer de string que coleta input do teclado. 

/* Fun��o declarada e definida com o tipo de retorno bool, que indica que a fun��o retorna um valor 
de true ou false. O static antes da declara��o indica que essa fun��o s� � vis�vel dentro do arquivo 
onde est� declarada */
static bool getInput(void) {
	printf("\n> ");  // Prompt com o texto para o jogador digitar. 
	
	/* a fun��o fgets() l� uma linha de texto da entrada padr�o (stdin) e armazena essa linha
	na vari�vel input, cujo tamanho � determinado por 'sizeof input'. A entrada padr�o stdin 
	representa o teclado. A express�o != NULL verifica se a fun��o fgets() teve sucesso na leitura da linha. 
	Se sim, retorna um ponteiro para a string lida, caso contr�rio, retorna NULL. Ou seja, verifica se
	uma linha de texto foi lida com sucesso da entrada padr�o e retorna 1 se sim, ou 0 se n�o.  */
	return fgets(input, sizeof input, stdin) != NULL;  // Fun��o fgets (standard) pega input do teclado. 
}

// Fun��o main() � o ponto inicial de um programa em C e que chama as outras fun��es. O void � pq n tem parametros
int main(void) {  // Fun��o main() � o ponto inicial de um programa em C e que chama as outras fun��es.   
    //setlocale(LC_ALL, "Portuguese");  // Parte para deixar em portugues
    printf("\t TEngine - Text Adventure Game Engine\n");
	printf("\t \t By Pedro Ivo - 2024 \n");	// \t = Tabula��o  
    printf("\nWelcome to the default room.");
	
	while (parseAndExecute(input) && getInput());  // main loop, chamando as outras fun��es at� elas darem 'false'. 
	printf("\nExiting...\n"); // Mensagem de quando o programa termina
	
    return 0;  // Fun��o main() retorna um zero exit code para indicar que o programa terminou.  
}