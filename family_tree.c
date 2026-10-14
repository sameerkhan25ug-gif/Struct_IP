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
    Person *ptr =(Person*) malloc(sizeof(struct Person));
    if( ptr==NULL){
        printf("Memory is not allocated kindky try again ");
        // break; //Assuming we dont need to run the further code itself if allocation fails 
        return NULL;// We have already specify return type as struct so returning 1 is not possible 
    }
    strcpy(ptr->name, name) ; // Returning an error - cannot alocate this way becayse it array not string pointer .
    ptr->age= age ;
    strcpy(ptr->name,name);
    struct Person *father=NULL;
    struct Person *mother=NULL;
    return ptr;
    }
// Person* create_person(const char *name, int age){
//     printf("Enter the name of person : ");
//     char entered_name;
//     scanf("%s",&entered_name);
//     printf("Enter the age : ");
//     scanf("%d",&age);   
//     }

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
    printf("\n");
    printf("2.My Parents \n");
    printf("My Father is: %s | His age is = %d \n", me->father , me->father->age);
    printf("My Mother is: %s | Her age is = %d \n", me->mother , me->mother->age);
    printf(" 3.My Paternal-Parents \n");
    printf("My paternal grand-father %s |His age is = %d \n", me->father->mother , me->father->mother->age);
    printf("My Paternal Grand-mother is : %s |Her age is = %d \n", me->father->father , me->father->father->age);
    printf(" 4.My Maternal-Parents \n");
    printf("My maternal grand-father is :  %s |His age is = %d \n", me->mother->father , me->mother->father->age);
    printf("My maternal grand-mother is :  %s |Her age is = %d \n", me->mother->mother , me->mother->mother->age);
    

}

void free_family_tree(Person *people[], int count){
        for ( int i=1 ; i <count; i++){
            free(people[i]);
        }
    }
int main() {
    Person *myself;
    myself=create_person("Sameer",20);
    Person *father;
    father=create_person("Vasim", 49);
    Person *mother;
    mother=create_person("Nafisa" , 45);
    Person *maternal_father;
    maternal_father=create_person("Najar", 80 );
    Person *maternal_mother;
    maternal_mother=create_person("Billo", 78);
    Person *paternal_father;
    paternal_father=create_person("Rahis", 85);
    Person *paternal_mother;
    paternal_mother=create_person("Mariyam", 82);

    link_parents(myself , father , mother );
    link_parents(father , paternal_father , paternal_mother);
    link_parents(mother ,  maternal_father, maternal_mother);
    print_family_relationships(myself);
    // myself->father = father;
    // myself->mother= mother;
    // father->father= paternal_father;
    // father->mother=paternal_mother;
    // mother->father=maternal_father;
    // mother->mother=maternal_mother;
    // maternal_mother->mother=NULL;
    // maternal_father->mother=NULL;
    // paternal_father->father=NULL;
    // paternal_father->mother=NULL;
    Person *arr[7]={myself , mother , father , maternal_father , maternal_mother , paternal_father , paternal_mother};
    free_family_tree(arr , 7);

    
    return 0;
}

