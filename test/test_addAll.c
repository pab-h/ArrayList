#include <stdio.h>
#include <stdlib.h>

#include "../header/ArrayList.h"

typedef struct User {
    int id;
    int card;
    float cash;
} User; 

int main() {

    User user1; 

    user1.id = 1;
    user1.card = 12312;
    user1.cash = 123.12;

    User user2; 

    user2.id = 2;
    user2.card = 123;
    user2.cash = 1.12;

    User** users = (User**) malloc(2 * sizeof(User*));

    *(users + 0) = &user1;
    *(users + 1) = &user2;

    ArrayList* list = arrayListFrom((void**) users, 2);

    printf("%d\n", size(list));    

    destroy(list);

    return 0;
}
