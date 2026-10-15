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
        return NULL;
    }
    strcpy(ptr->name, name) ;
    ptr->age= age ;
    strcpy(ptr->name,name);
    struct Person *father=NULL;
    struct Person *mother=NULL;
    return ptr;
    }

void read_person_info(const char *role, char *name_out, int *age_out){
    printf("The peron is %s\n", role);
    printf("Enter the name of the %s : ",role);
    scanf("%s",name_out);
    printf("Enter the age of the %s : ",role);
    scanf("%d",age_out);
}

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
    Person *father;
    Person *mother;
    Person *paternal_father;
    Person *paternal_mother;
    Person *maternal_father;
    Person *maternal_mother;
    

    Person *roles_arr[7]={ myself ,father , mother , paternal_father , paternal_mother , maternal_father , maternal_mother };

    char *myname[] = {"Yourself" , "Father" , "Mother", "Paternal-father" , "Paternal-mother" , "Maternal-fathers" , "Maternal_Mothers"  };
    
    // for (int i=0 ; i <7 ; i++ ){
    //     char *name;
    //     int age;
    //     read_person_info(myname[i], name , &age  );
    //     roles_arr[i]=create_person(name , age );

    // }
    char name0[100];
        int age0;
        int i=0;
        read_person_info(myname[i], name0 , &age0  );
        printf("%p",myself);
        myself=create_person(name0 , age0 );
        printf("%p",myself);
    
        i++;
        char name1[100];
        int age1;
        read_person_info(myname[i], name1 , &age1  );
        father=create_person(name1 , age1 );
         i++;
        char name2[100];
        int age2;
        read_person_info(myname[i], name2 , &age2  );
        mother=create_person(name2 , age2 );
        i++;
        char name3[100];
        int age3;
        read_person_info(myname[i], name3 , &age3  );
        paternal_father=create_person(name3 , age3 );
        i++;
        char name4[100];
        int age4;
        read_person_info(myname[i], name4 , &age4  );
        paternal_mother=create_person(name4 , age4 );
        i++;
        char name5[100];
        int age5;
        read_person_info(myname[i], name5 , &age5  );
        maternal_father=create_person(name5 , age5 );
        i++;
        char name6[100];
        int age6;
        read_person_info(myname[i], name6 , &age6  );
        maternal_mother=create_person(name6 , age6 );

    link_parents(myself , father , mother );
    link_parents(father , paternal_father , paternal_mother);
    link_parents(mother , maternal_father, maternal_mother);
    
    print_family_relationships(myself);
    
    Person *arr[7]={myself , mother , father , maternal_father , maternal_mother , paternal_father , paternal_mother};
    free_family_tree(arr , 7);

    
    return 0;
}

