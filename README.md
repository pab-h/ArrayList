# ArrayList em C
É literalmente uma cópia do [ArrayList do Java](https://docs.oracle.com/javase/8/docs/api/java/util/ArrayList.html)

# Header

```C
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

ArrayList* arrayListFrom(void** values);

void add(ArrayList* list, void* value);

void addAll(ArrayList* list, void** values);

void clear(ArrayList* list);

void destroy(ArrayList* list);

void* get(ArrayList* list, int index);

int indexOf(ArrayList* list, void* value);

void remove(ArrayList* list, void* value);

void removeAt(ArrayList* list, int index);

int size(ArrayList* list);

ArrayList* subArrayList(ArrayList* list, int start, int end);

void set(ArrayList* list, int index, void* value);

void** toArray(ArrayList* list);

void iterator(ArrayList* list);


void* next(Iterator* iterator);

int hasNext(Iterator* iterator);

#endif
```
