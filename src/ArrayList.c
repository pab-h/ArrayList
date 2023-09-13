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

void add(ArrayList* list, void* value) {
    Node* node = createNode(value);
    
    if (size(list) == 0) {
        list->head = node;
        list->tail = node;
        list->size++;

        return;
    }

    list->tail->next = node;
    list->tail = node;

    list->size++;

}

void addAll(ArrayList* list, void** values) {
    int size = sizeof(values) / sizeof(*values);
    
    for(int i = 0; i < size; i++) {
        add(list, *(values + i));
    }
}
