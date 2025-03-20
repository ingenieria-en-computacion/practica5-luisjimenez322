#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stack_create() // Crea una nueva pila vacia

{
    Stack *s = (Stack *)malloc(sizeof(Stack)); // Asigna memoria dinamica para la pila
    if (s == NULL) 
    {
        printf("Error: No se pudo asignar memoria para la pila.\n");
        return NULL;
    }
    s->top = NULL;  // Inicia la pila vacia
    return s;
}

void stack_push(Stack* s, Data d) // Inserta un elemento en la parte superior de la pila
{
    if (s == NULL) 
    {
        printf("Error: Puntero a la pila invalido.\n");
        return;
    }
    Node *n = new_node(d);  // Crea un nuevo nodo
    if (n == NULL) 
    {
        printf("Error: No se pudo asignar memoria para el nodo.\n");
        return;
    }
    n->next = s->top;  // Enlaza el nuevo nodo al tope de la pila
    s->top = n;        // Actualiza el tope de la pila
}

Data stack_pop(Stack* s) // Elimina y devuelve el elemento en la parte superior de la pila
{
    if (s == NULL || s->top == NULL) 
    {
        printf("Error: Pila vacia o invalida.\n");
        return -1; 
    }
    Node *temp = s->top;   //Guarda el nodo a eliminar
    Data val = temp->data; //Obtiene el valor del nodo
    s->top = temp->next;   //Actualiza el tope al siguiente nodo
    delete_node(temp);     //Libera la memoria del nodo eliminado
    return val;
}

int stack_is_empty(Stack* s) // Verifica si la pila esta vacia
{
    if (s == NULL) 
    {
        return -1;
    }
    return (s->top == NULL);
}

void stack_empty(Stack* s) // Elimina todos los elementos de la pila
{
    if (s == NULL) 
    {
        return;
    }
    while (!stack_is_empty(s)) 
    {
        stack_pop(s);  // Elimina todos los elementos
    }
}

void stack_delete(Stack *s) // Elimina la pila y libera la memoria 
{
    if (s == NULL) 
    {
        return;
    }
    stack_empty(s);    // Vacia la pila antes de liberarla
    free(s);           // Libera la memoria de la pila
}

void stack_print(Stack *s) // Imprime los elementos de la pila

{
    if (s == NULL || s->top == NULL) 
    {
        printf("Pila vacia o invalida.\n");
        return;
    }
    Node *temp = s->top; 
    printf("Pila: ");
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}