extern bool parseAndExecute(char *input);

/* informa ao compilador que existe uma função chamada parseAndExecute que retorna um valor booleano (bool) 
e aceita um argumento do tipo ponteiro para caractere (char *input). No entanto, o extern aqui não é 
necessário para a declaração de uma função, já que a declaração de uma função é implicitamente extern em C.

A função parseAndExecute é responsável por analisar e executar comandos do usuário dentro do jogo. Ela 
aceita uma string (char *input) como entrada, que provavelmente é o comando digitado pelo jogador, e 
retorna um valor booleano indicando se o comando foi processado com sucesso ou não.

Por exemplo, ela poderia retornar true se o comando foi reconhecido e executado corretamente e false se 
o comando não foi reconhecido ou ocorreu um erro durante a execução.

Essa função é crucial para a lógica do jogo, pois permite que o jogador interaja com o mundo do 
jogo fornecendo comandos de entrada. Certifique-se de implementar essa função adequadamente em seu 
código-fonte (.c) para que ela faça o que é esperado de acordo com a mecânica do seu jogo. */