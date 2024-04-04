#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "object.h"

static bool objectHasTag(OBJECT *obj, const char *substantivo) {
	return substantivo != NULL && *substantivo != '\0' && strcmp(substantivo, obj->tag) == 0;
}

/* Essa função determina o objeto que pertence ao substantivo, retornando um pointer para o objeto com a tag correspondente
ao substantivo, se não tiver tag correspondente, retorna NULL.  */
static OBJECT *getObject(const char *substantivo) {   
	OBJECT *obj, *res = NULL;
	for (obj = objs; obj < endOfObjs; obj++) {
		if (objectHasTag(obj, substantivo)) {
			res = obj;
		}
	}
	return res;
}

/* Mostra uma mensagem generica se nenhum objeto corresponde ao substantivo dado, ou se o objeto não estiver visivel
de onde o jogador está. Em ambos os casos, retorna NULL. */
OBJECT *getVisible(const char *intention, const char *substantivo) {
	OBJECT *obj = getObject(substantivo);
	if (obj == NULL) {
		printf("I don't understand %s.\n", intention);
	}
	// Condição que determina se um objeto especifico está visivel pro jogador, com 7 regras:
	else if (!(obj == player ||  // O proprio jogador;
			   obj == player->location ||  // Onde o jogador está;
			   obj->location == player ||  // Objetos que o jogador está segurando;
			   obj->location == player->location ||  // Objetos presentes onde o jogador está;
			   obj->location == NULL ||  // Qualquer lugar que o jogador possa ir, SERÁ REFEITO;
			   obj->location->location == player ||  //Objetos dentro de outros objetos segurados pelo jogador;
			   obj->location->location == player->location))  // Objetos dentro de outros objetos presentes no mesmo lugar.
	{
		printf("You don't see any %s here.\n", substantivo);
		obj = NULL;
	}
	return obj;
}