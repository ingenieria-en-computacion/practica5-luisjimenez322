#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node *new_node(Data d) // Crea un nuevo nodo
{
    Node *n = (Node *)malloc(sizeof(Node)); //Memoria dinamica
    if (n == NULL) 
    {
        printf("Error: No se pudo asignar memoria.\n");
        return NULL;
    }
    n->data = d;    //Asigna el valor
    n->next = NULL; //Inicializa el apuntador next como NULL
    return n;
}

void delete_node(Node* n) //Elimina un nodo y libera memoria

{
    if (n != NULL) 
    {
        free(n); //Libera memoria
    }
}

void print_node(Node* n) //Imprime la info contenida en un nodo

{
    if (n == NULL) 
    {
        printf("Nodo invalido.\n");
        return;
    }

    printf("Dato: %d, Siguiente: %p\n", n->data, (void*)n->next);
}