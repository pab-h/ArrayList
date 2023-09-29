#ifndef ARRAYLIST_HEADER

#define ARRAYLIST_HEADER

typedef struct Node {
    void* value;
    struct Node* next;
} Node;

typedef struct ArrayList {
    Node* head;
    Node* tail;

    int size;
} ArrayList;

typedef struct Iterator {
    ArrayList* list;
    Node* current;
} Iterator;

ArrayList* createArrayList();

ArrayList* arrayListFrom(void** values, int size);

void add(ArrayList* list, void* value);

void addAll(ArrayList* list, void** values, int size);

void clear(ArrayList* list);

void destroy(ArrayList* list);

void* get(ArrayList* list, int index);

void set(ArrayList* list, int index, void* value);

int indexOf(ArrayList* list, void* value);

void removeValue(ArrayList* list, void* value);

void removeAt(ArrayList* list, int index);

int size(ArrayList* list);

ArrayList* subArrayList(ArrayList* list, int start, int end);

void** toArray(ArrayList* list);

Iterator* iterator(ArrayList* list);


void* next(Iterator* iterator);

int hasNext(Iterator* iterator);

#endif