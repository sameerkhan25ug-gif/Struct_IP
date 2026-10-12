#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;

// Person* create_person(const char *name, int age){
//     Person *myself =malloc(sizeof(struct Person));
//     strcpy(myself->name,"Sameer");
//     myself->age=19;
//     struct Person *father=NULL;
//     struct Person *mother=NULL;
//     return myself;
//     }
Person* create_person(const char *name, int age){
    printf("Enter the name of person : ");
    char entered_name;
    scanf("%s",&entered_name);
    printf("Enter the age : ");
    scanf("%d",&age);
    
    }

void read_person_info(const char *role, char *name_out, int *age_out){
    printf("Enter the name of the paternal/Maternal grandfather : ");
    scanf("%s",name_out);
    printf("Enter the name of the paternal/Maternal grandfather : ");
    scanf("%d",*age_out);
}
// void link_parents(Person *myself, Person *father, Person *mother){
//     myself->father = father;
//     myself->mother= mother;

// }
void link_parents(Person *child, Person *father, Person *mother){
    child->father = father;
    child->mother= mother;
}
void print_family_relationships(const Person *me){
    printf(" 1.Myself\n");
    printf("My name is %s | age =%d", me->name, me->age);
    printf("2.My Parents \n");
    printf("Mother %s | age= %d \n", me->mother , me->mother->age);
    printf("Father %s | age= %d \n", me->father , me->father->age);
    printf(" 3.My Paternal-Parents \n");
    printf("Mother %s | age= %d \n", me->father->father , me->father->father->age);
    printf("Father %s | age= %d \n", me->father->mother , me->father->mother->age);
    printf(" 4.My Maternal-Parents \n");
}
int main() {
    Person *myself;
    Person *father;
    Person *mother;
    Person *maternal_father;
    Person *maternal_mother;
    Person *paternal_father;
    Person *paternal_mother;

    link_parents(myself , father , mother );
    link_parents(father , paternal_father , paternal_mother);
    link_parents(mother , maternal_mother , maternal_father);
    // myself->father = father;
    // myself->mother= mother;
    // father->father= paternal_father;
    // father->mother=paternal_mother;
    // mother->father=maternal_father;
    // mother->mother=maternal_mother;
    maternal_mother->mother=NULL;
    maternal_father->mother=NULL;
    paternal_father->father=NULL;
    paternal_father->mother=NULL;
    
    return 0;
}

