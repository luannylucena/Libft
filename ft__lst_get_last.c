#include "libft.h"

//essa função pega o último elemento da lista
t_node *ft_get_last_node(t_node *stack) //tem como parâmetro o ponteiro stack (nó inicial)
{
    if(!*node) //se não existe (null).
        return(NULL); //só retorna.
    while(*stack->next != NULL) //enquanto o próximo nó for diferente de NULO, não chegou ao fim, então vamos percorrendo.
        stack = stack->next; // O primeiro nó vai recebendo o próximo, próximo.. 
    return(stack); //qdo o próximo for NULO, ou seja, o último nó, ele retorna o stack.
}