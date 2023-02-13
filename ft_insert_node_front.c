#include "libft.h"

//função que vai inserir um novo nó no começo da lista. 
//parâmetros: -stack (ponteiro p/ ponteiro que aponta pro 1º nó da lista) e new_node (endereço de ponteiro para o nó a ser adicionado na lista).
t_node  *ft_insert_node_back(t_node **stack, t_node *new_node)
{
    t_node aux;

    if(!*stack || !new_node) //faço a condição de verificação de existência.
        return ;
    new_node->next = *stack; //o próximo nó recebe o valor do primeiro nó.
    *stack = new_node; //o primeiro nó da pilha recebe no novo nó.
}
