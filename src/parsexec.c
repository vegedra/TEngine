/* Coded by Ivo - 02/04/24 -- Programando um Text Game 
Código para a função 'parseAndExecute' */

#include <stdbool.h>
#include <stdio.h>
#include "location.h"
#include <string.h>  
/* \_ Inclui funções de manipular strings: 
strcmp: compara duas strings e retorna um numero inteiro que indica se a 1a string é menor, igual ou maior que a 2a; 
strtok: divide uma string em tokens/partes, com base em um delimitador específico. 
Cada chamada subsequente da função strtok() retorna o próximo token da string original, até que não haja 
mais tokens para retornar, momento em que a função retorna NULL.  */

// Define uma função que aceita uma string como entrada e retorna um valor booleano (true ou false)
bool parseAndExecute(char *input) {
	char *verbo = strtok(input, " \n");  // parser basico de verbo-noun (go north) com duas linhas 
	char *substantivo = strtok(NULL, " \n");
	
	if (verbo != NULL) {  /* != significa 'is not equal to' -- não faz nada se o jogador não digitar nada.
		Verifica se o input no teclado corresponde com os verbos reconhecidos, é case-sensitive. */
		if (strcmp(verbo, "quit") == 0) {
			return false;  // Retornar 'false' faz o main loop terminar 
		}
		
		/* else if = condicional usada para testar varias condições em sequencia. Compara se a string
		armazenada na variavel "verbo" com a string "olhar", ou seja, verifica se 'verbo' é igual a "olhar" */
		else if (strcmp(verbo, "look") == 0) {
			//printf("Text for look.\n");
			executeLook(substantivo);
		}
		
		else if (strcmp(verbo, "go") == 0) {
			//printf("Text for look.\n");
			executeGo(substantivo);
		}
		
		else {
			printf("I don't know what '%s' means.\n", verbo);  // Mostra o que o usuario digitou 
		}
	}
	return true;
}