#include <stdio.h>
#include "object.h"

int listObjectsAtLocation(OBJECT *location) {
	int count = 0;
	OBJECT *obj;
	for (obj = objs; obj < endOfObjs; obj++) {
		// Objeto player é excluido da lista
		if (obj != player && obj->location == location) {
			// A lista começa com o texto no printf somente quando sabemos que pelo menos um objeto foi encontrado
			if (count++ == 0) {
				printf("You see:\n");
			}
			printf("%s\n", obj->description);
		}
	}
	// A função retorna o numero de objetos na lista
	return count;
}