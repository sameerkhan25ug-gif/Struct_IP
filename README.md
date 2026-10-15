# Struct_IP
This repo consist of the my course Imperative Programming's Assignment

The whole project revolves around taking the input from the user about his ownself , his parents (i.e mother and father) , his paternal grandparents , maternal grandparents and diaplaying the output in proper sequence, which ultimatey forms the family tree for **3 Genreation**.

The whole project is define in such a way that its take all inputs and displays outputs through the help of the function to **_avoid_** redundancy and make it much **_more efficient_** in terms of working.

All the function that we have define are designed to do some specific task that ultimately build our whole project. 

#### _Lets understand each functions and their roles_ 

```
typedef struct Person { 
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person; // Type def is use for alias which ultimately reduces our effort instead of calling whole struct Person 'some instance of it ' we can directly call that struct with Person.
```

Here we have define the how the struct Person structure is .

The next function is 
```
Person* create_person(const char *name, int age){
    Person *ptr =(Person*) malloc(sizeof(struct Person)); //Allocates appropiate and sufficient memory using malloc() as per defination of struct Person for a single Person
    if( ptr==NULL){
        printf("Memory is not allocated kindky try again ");
        return NULL;
    }
    strcpy(ptr->name, name) ; // This is inbuilt function in C what is do is that it copies the name and paste in variable name
    ptr->age= age ; //Its sets the value for person age 
    struct Person *father=NULL;
    struct Person *mother=NULL;//sets father and mother pointers to NULL, and returns the allocated memory address.
    return ptr;
    }
```
This is very important function which assigns the memory as per defination of struct , sets name and age , and points to other structs.


The next function is ; 
```
void read_person_info(const char *role, char *name_out, int *age_out){
    printf("The person is %s\n", role);
    printf("Enter the name of the %s : ",role);
    scanf("%s",name_out);
    printf("Enter the age of the %s : ",role);
    scanf("%d",age_out);
}
```
This function basically takes the input about the user and his family.







