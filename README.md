# Family tree project
This repo consist of the my course Imperative Programming's Assignment

The whole project revolves around taking the input from the user about his ownself , his parents (i.e mother and father) , his paternal grandparents , maternal grandparents and diaplaying the output in proper sequence, which ultimatey forms the family tree for **3 Genreation**.

The whole project is define in such a way that its take all inputs and displays outputs through the help of the function to **_avoid redundancy_** and make it much **_more efficient_** in terms of working.

All the function that we have define are designed to do some specific task that ultimately build our whole project. 

#### _Lets understand each functions and their roles_ 

```
typedef struct Person { 
    char name[50]; // Its specifies that a struct contain a name maximum characters that can be entered will 50 
    int age;// Its specifies that a struct contain a age 
    struct Person *father; //This specifies that the struct itself will consists of another struct
    struct Person *mother;//This specifies that the struct itself will consists of another struct
} Person; // Typedef is use to declare alias which ultimately reduces our effort instead of calling whole struct Person 'some instance of it ' we can directly call that struct by just calling by it alias that is Person.
```
Moreover, here we have define the how the struct Person structure is.

The next function is 
```
Person* create_person(const char *name, int age){
    Person *ptr =(Person*) malloc(sizeof(struct Person)); //Allocates appropiate and sufficient memory using malloc() as per defination of struct Person for a single Person
    if( ptr==NULL){
        printf("Memory is not allocated kindky try again ");
        return NULL;
    }//It is condition which is checking whether memory is allocated successfully or not. We know if malloc fails to assign memory it returns *NULL*.
    strcpy(ptr->name, name) ; // This is inbuilt function in C what is do is that it copies the name and paste in variable name
    ptr->age= age ; //Its sets the value for person age 
    struct Person *father=NULL;//This sets mother pointer for particular instance to NULL
    struct Person *mother=NULL;//This sets father pointers for particular instance to NULL.
    return ptr; //Here we are defing the return type of the function. Here it expects returns type to be of pointer.
    }
```
**_This is very important function which assigns the memory as per defination of struct , sets name and age , and points to other structs._**


The next function is ; 
```
void read_person_info(const char *role, char *name_out, int *age_out){ //This are the parameter of function where it expects the pointer to char , int and expects pointer to char of type const("Const assures that the value to which its is pointing to cannot be change")
    printf("The person is %s\n", role); //Prints the role for which we expects the input.
    printf("Enter the name of the %s : ",role);//Ask user to enter the name of specified role
    scanf("%s",name_out);//This helps to store the enter value in variable name_out
    printf("Enter the age of the %s : ",role);//Ask user to enter the age of specified role
    scanf("%d",age_out);//This helps to store the enter value in variable age_out
}
```
**_This function basically takes the input about the user and his family._**

```
void link_parents(Person *child, Person *father, Person *mother){// This function expects three arguments that should be pointer to struct
    child->father = father;// This will help to link child struct to its parents struct
    child->mother= mother;//This will help to link child struct to its parents struct
}
```
**_This is very important function which will help us to link structs so that we can establish a relationship between different struct._**

```
void print_family_relationships(const Person *me){
    printf(" 1.All about your family tree !\n");
    printf("Your name is:  %s | Your age is=%d\n", me->name, me->age);
    printf("2.Your Parents \n");
    printf("Your Father name is: %s | His age is = %d \n", me->father , me->father->age);
    printf("Your Mother  name is: %s | Her age is = %d \n", me->mother , me->mother->age);
    printf(" 3.Your Paternal-Parents \n");
    printf("Your paternal grand-father's name is : %s |His age is = %d \n", me->father->father , me->father->father->age);
    printf("Your Paternal Grand-mother's name is : %s |Her age is = %d \n", me->father->mother , me->father->mother->age);
    printf(" 4.Your Maternal-Parents \n");
    printf("Your maternal grand-father's nameis :  %s |His age is = %d \n", me->mother->father , me->mother->father->age);
    printf("Your maternal grand-mother's name is :  %s |Her age is = %d \n", me->mother->mother , me->mother->mother->age);

}
```
**_This is the function that will help us to prints all the inputs. Moreover here we traversing from struct to other struct._**
```
void free_family_tree(Person *people[], int count){
        for ( int i=1 ; i <count; i++){
            free(people[i]);
            printf("free %d",i);
        }
    }
```
We know we allocated memoery for every instances of the struct through malloc after and this is **_dynamic memory_** allocation which means it wont get free until we free it . So what this function does is that **_it runs a loop for all seven people and frees a memory of each instance of struct_**.




