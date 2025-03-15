#ifndef __NODE_H__
#define __NODE_H__

typedef int Data;
typedef struct Node {
    Data data;
    struct Node* next;
} Node;

Node *new_node(Data);
void delete_node(Node*);
void print_node(Node*);

#endif