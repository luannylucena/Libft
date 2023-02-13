#include "libft.h"

//função que vai inserir um novo vó ao final da lista. 
//parâmetros: -stack (ponteiro p/ ponteiro que aponta pro 1º nó da lista) e new_node (endereço de ponteiro para o nó a ser adicionado na lista).


t_node  *ft_insert_node_back(t_node **stack, t_node *new_node)
{
    t_node  *aux; //cria-se uma variável auxiliar

    if(!stack || !new_node) //verifica se os parâmetros são nulos
        return ; //então, somente retorna.
    if(*stack == NULL)//se a lista está vazia
    {
        *stack = new_node; //inserir o novo nó, que será o primeiro da lista, consequentemente o último.
            return ; //retorno de segurança
    }
    aux = ft_get_last_node(*stack); //procura o úlitmo nó
    aux->next = new_node; // Adiciono o novo elemento depois do último da lista
}
