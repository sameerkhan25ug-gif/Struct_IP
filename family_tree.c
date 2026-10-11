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
    strcpy(myself->name,"Sameer");
    myself->age=19;
    struct Person *father=NULL;
    struct Person *mother=NULL;
    return myself;
    }

void read_person_info(const char *role, char *name_out, int *age_out){
    printf("Enter the name of the paternal/Maternal grandfather : ");
    scanf("%s",name_out);
    printf("Enter the name of the paternal/Maternal grandfather : ");
    scanf("%d",*age_out);
}

int main() {

    
    return 0;
}

