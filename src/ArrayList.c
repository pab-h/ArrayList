#include "../header/ArrayList.h"
#include "stdlib.h"

Node* createNode(void* value) {
    Node* node = (Node*) malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;

    return node;
}

ArrayList* createArrayList() {
    ArrayList* list = (ArrayList*) malloc(sizeof(ArrayList));

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

ArrayList* arrayListFrom(void** values) {
    ArrayList* list = createArrayList();

    addAll(list, values);

    return list;
}

