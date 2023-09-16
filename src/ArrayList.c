#include "../header/ArrayList.h"
#include "stdlib.h"

Node* createNode(void* value) {
    Node* node = (Node*) malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;

    return node;
}

void deleteNode(Node* node) {
    free(node->value);
    free(node);
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

int size(ArrayList* list) {
    return list->size;
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

void clear(ArrayList* list) {
    if (size(list) == 0) {
        return;
    }

    Node* current = list->head;

    while (current) {
        Node* next = current->next;

        deleteNode(current);

        current = next;
    }

    list->size = 0;

}

void destroy(ArrayList* list) {
    clear(list);
    free(list);

}

int isValidIndex(ArrayList* list, int index) {
    return 0 <= index && index <= size(list);
}

void removeAt(ArrayList* list, int index) {
    if (size(list) == 0) {
        return;
    }

    if (isValidIndex(list, index)) {
        return;
    }

    if (index == 0) {
        Node* tmp = list->head;

        list->head = list->head->next;

        deleteNode(tmp);

        list->size--;

        return;
    }

    Node* current = list->head;

    int currentIndex = 0;

    while (current && (currentIndex + 1) != index) {
        currentIndex++;
        current = current->next;
    }

    Node* tmp = current->next;
    current->next = tmp->next;

    deleteNode(tmp);

    list->size--;

}

void remove(ArrayList* list, void* value) {
    if (size(list) == 0) {
        return;
    }

    if (list->head->value == value) {

        Node* tmp = list->head;

        list->head = list->head->next;
        list->size--;

        deleteNode(tmp);

        return;
    }

    Node* current = list->head;
    
    while (current->next && current->next->value != value) {
        current = current->next;
    }

    if (current->next) {
        Node* tmp = current->next;
        current->next = tmp->next;

        deleteNode(tmp);

        list->size--;
    }

}

int indexOf(ArrayList* list, void* value) {
    Node* current = list->head;

    int currentIndex = 0;

    while (current) {

        if (current->value == value) {
            return currentIndex;
        }

        currentIndex++;
        current = current->next;
    }

    return -1;
}

void* get(ArrayList* list, int index) {
    if (isValidIndex(list, index)) {
        return NULL;
    }

    Node* current = list->head;

    int currentIndex = 0;

    while (current) {

        if (currentIndex == index) {
            return current;
        }

        currentIndex++;
        current = current->next;
    }

    return NULL;
}

void set(ArrayList* list, int index, void* value) {
    if (isValidIndex(list, index)) {
        return;
    }

    Node* current = list->head;

    int currentIndex = 0;

    while (current && currentIndex != index) {
        currentIndex++;
        current = current->next;
    }

    current->value = value;

}

ArrayList* subArrayList(ArrayList* list, int start, int end) {
    if (size(list) == 0) {
        return NULL;
    }

    if (isValidIndex(list, start) && isValidIndex(list, end)) {
        return NULL;
    }

    if (start > end) {
        int tmp = start;

        start = end;
        end = tmp;
    }

    ArrayList* subList = createArrayList();

    int index = 0;

    Node* current = list->head;

    while (current) {
        if (index > end) {
            break;
        }

        if (index >= start && index <= end) {
            add(subList, current->value);
        }

        index++;
        current = current->next;
    }

    return subList;
}

void** toArray(ArrayList* list) {
    if (size(list) == 0) {
        return NULL;
    }

    int array_size = size(list) + 1;

    void** array = malloc(array_size * sizeof(void*)); 

    Node* current = list->head;

    int index = 0;

    while (current) {

        *(array + index) = current->value;

        index++;
        current = current->next;
    }

    return array;
}
