/* Coded by Ivo - 02/04/24 -- Programando um Text Game 
Código para a função 'parseAndExecute' */

#include <stdbool.h>
#include <stdio.h>
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
		if (strcmp(verbo, "sair") == 0) {
			return false;  // Retornar 'false' faz o main loop terminar 
		}
		
		/* else if = condicional usada para testar varias condições em sequencia. Compara se a string
		armazenada na variavel "verbo" com a string "olhar", ou seja, verifica se 'verbo' é igual a "olhar" */
		else if (strcmp(verbo, "olhar") == 0) {
			printf("Está um pouco escuro aqui.\n");
		}
		
		else if (strcmp(verbo, "ir") == 0) {
			printf("Está muito escuro para ir para algum lugar.\n");
		}
		
		else {
			printf("\nEu não sei o que '%s' significa.\n", verbo);  // Mostra o que o usuario digitou 
		}
	}
	return true;
}