#include <stdio.h>
#include "object.h"

OBJECT objs[] = {
	// Por serem parecidos, iremos juntar as listas de locais com os itens/atores
	{"location 1 Description", NULL},  // room1 é oq o jogador digita
	{"location 2 Description", NULL},
	{"a silver coin", "silver", room1},
	{"a gold coin", "gold", room2},
	{"a burly guard", "guard", room1},
	{"yourself", "yourself", room1},
};