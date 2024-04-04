/* Coded by Ivo - 02/04/24 -- Programando um Text Game 

LEMBRETES: (Mais informa��es no .txt)
!= significa 'is not equal to' 
gcc -o JOGO main.c parsexec.c location.c   -- para compilar  */

#include <stdio.h>  // C standard library 
#include <stdbool.h>  // Adiciona booleans 
#include "parsexec.h"  // importa fun��o criada 
#include <locale.h>  // Para mostrar caracteres especiais 

// Declara variavel estatica (explico o que � em location.c)
static char input[100] = "olhar ao redor";  // buffer de string que coleta input do teclado. 

/* Fun��o declarada e definida com o tipo de retorno bool, que indica que a fun��o retorna um valor 
de true ou false. O static antes da declara��o indica que essa fun��o s� � vis�vel dentro do arquivo 
onde est� declarada */
static bool getInput(void) {
	printf("\n> ");  // Prompt com o texto para o jogador digitar. 
	return fgets(input, sizeof input, stdin) != NULL;  // Fun��o fgets (standard) pega input do teclado. 
}

int main() {  // Fun��o main() � o ponto inicial de um programa em C e que chama as outras fun��es.   
    setlocale(LC_ALL, "Portuguese");  // Parte para deixar em portugues
    printf("\t TEngine - Text Adventure Game Engine\n");
	printf("\t \t By Pedro Ivo - 2024 \n");	// \t = Tabula��o  
    printf("\nBem-vindo(a) � sala padr�o.");
	
	while (parseAndExecute(input) && getInput());  // main loop, chamando as outras fun��es at� elas darem 'false'. 
	printf("\nSaindo...\n"); // Mensagem de quando o programa termina
	
    return 0;  // Fun��o main() retorna um zero exit code para indicar que o programa terminou.  
}