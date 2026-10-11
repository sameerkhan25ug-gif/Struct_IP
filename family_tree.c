#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

Person* create_person(const char *name, int age){
    Person *myself =malloc(sizeof(struct Person));
    *myself->name=strcpy(myself->name,"Sameer");
    myself->age=19;
    struct Person *father=NULL;
    struct Person *mother=NULL;
    return myself;
    }

int main() {

    
    return 0;
}

