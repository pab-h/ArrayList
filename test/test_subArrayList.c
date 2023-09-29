#include <stdio.h>
#include <stdlib.h>

#include "../header/ArrayList.h"


typedef struct User {
    int id;
    int card;
    float cash;
} User; 

int main() {

    User* user1 = (User*) malloc(sizeof(User)); 

    user1->id = 1;
    user1->card = 12312;
    user1->cash = 123.12;

    User* user2 = (User*) malloc(sizeof(User)); 

    user2->id = 2;
    user2->card = 123;
    user2->cash = 1.12;
    
    User* user3 = (User*) malloc(sizeof(User)); 

    user3->id = 3;
    user3->card = 333;
    user3->cash = 1.33;

    User* user4 = (User*) malloc(sizeof(User)); 

    user3->id = 4;
    user3->card = 444;
    user3->cash = 1.44;

    ArrayList* list = createArrayList();

    add(list, (void*) user1);
    add(list, (void*) user2);
    add(list, (void*) user3);
    add(list, (void*) user4);

    printf("%d\n", size(list));   

    ArrayList* subList = subArrayList(list, 1, 3);  

    printf("%d\n", size(subList));   

    destroy(list);
    free(subList);
    
    return 0;
}
