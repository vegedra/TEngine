typedef struct object {
	  const char	*description;  // Como o item/ator é descrito em texto narrativo
	  const char	*tag;  // Como o item/ator é reconhecido pelo parser
	  struct object *location; // Onde o item/ator está localizado, sendo um pointer pro 'struct location'
	} OBJECT;
	
	extern OBJECT objs[];
	
	#define room1 (objs + 0)
	#define room2 (objs + 1)
	#define silver (objs + 2)
	#define gold (objs + 3)
	#define guard (objs + 4)
	#define player (objs + 5)

	#define endOfObjs (objs + 6)
	
	/* Exemplo de uso dos ponteiros criados:
	printf("You are in %s.\n", field->description);  

	Lista todos os itens e atores no 'room2'
	struct object *obj;
	for (obj = objs; obj < objs + 5; obj++)
	{
	if (obj->location == room2)
	{
		printf("%s\n", obj->description);
	}
	}

	Agora todos os objetos estão na mesma lista  */