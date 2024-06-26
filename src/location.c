/* Coded by Ivo - 03/04/24 -- Programando um Text Game 
Código para as localidades */

/* Usaremos uma 'struct' para representar uma localidade, com dois atributos:
descrição: como é descrito no texto de narrativa;
tag: como a locação é reconhecida pelo parser.  */

// Os comandos 'look around' e 'go <location>' funcionam

#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"
#include "substantivo.h"

/* Definimos um type (struct location), variable (locs) e colocamos os valores inicias em um só statement
struct location {
	// const = indica que o valor não pode ser alterado ; * = indica sequencia de caracteres
	const char *description;
	const char *tag;
} locs[] = {  // O compilador determina automaticamente o tamanho baseado no numero de elementos
	{"location 1 Description", "room1"},  // room1 é oq o jogador digita
	{"location 2 Description", "room2"}
};  -- NAO USAREMOS POR CONTA DO OBJECT.C   */

/* Compilador calcula o numero total de localidades
#define numberOfLocations (sizeof locs / sizeof *locs)  -- NAO USAREMOS POR CONTA DO OBJECT.C   */

/* A locação inicial do jogador é 0, se mudar o valor ele vai pra outro lugar
Declara uma variavel estatica, que é uma variavel que persiste até o final do programa e é 
acessivel apenas dentro do arquivo que foi declarada. 
Unsigned significa que a variavel só pode ter valores positivos (não negativos).  */
// static unsigned locationOfPlayer = 0;  -- NAO USAREMOS POR CONTA DO OBJECT.C 

// Função com retorno tipo void, ou seja, ela não retorna nenhum valor
void executeLook(const char *substantivo) {
	if (substantivo != NULL && strcmp(substantivo, "around") == 0) {
		printf("You are in %s.\n", player->location->description);
		// Usa a função em misc.c para mostrar a lista de items e atores presentes na locação atual
		listObjectsAtLocation(player->location);
	} else {
		printf("I don't understand what you want to see.\n");
	}
}

void executeGo(const char *substantivo) {
	// Usando a função getVisible nos livramos do loop da função executeGo, melhorando o código
	OBJECT *obj = getVisible("Where you want to go", substantivo);
	if (obj == NULL) {
		// Já é feito pelo getVisible
	} else if (obj->location == NULL && obj != player->location) {
		printf("OK.\n");
		player->location = obj;
		/* Depois que o jogador se move, a nova locação é descrita, como se o jogador tivesse
		digitado 'look around'  */
		executeLook("around");
	} else {
		printf("You can't get much closer than this.\n");
	}
}
	/* CODIGO ANTIGO!!
	unsigned i;
	/* Estrutura de repetição loop for ; executa um bloco de codigo repetidamente enquanto uma 
	condição for verdadeira. 
	for (i = 0; i < numberOfLocations; i++) {  // i++ incrementa o valor de i em 1 automaticamente
		if (substantivo != NULL && strcmp(substantivo, locs[i].tag) == 0) {
			if (i == locationOfPlayer) {
				printf("You can't get much closer than this.\n");
			} else {
				printf("OK.\n");
				locationOfPlayer = i;
				/* Depois que o jogador se move, a nova locação é descrita, como se o jogador tivesse
				digitado 'look around'  
				executeLook("around");
			}
			return;
		}
	}
	printf("I don't understand where you want to go.\n");  */