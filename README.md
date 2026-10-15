# Family tree project

**_Before we start I want to show how does the input and output will look for the project that I have made_**

**This below piece shows what the output will be for particular input**
```
The person is Yourself
Enter the name of Yourself : Varsha
Enter the age of Yourself : 20
The person is Father
Enter the name of Father : Pushkar
Enter the age of Father : 40
The person is Mother
Enter the name of Mother : Mahima
Enter the age of Mother : 38
The person is Paternal-father
Enter the name of Paternal-father : Rajendra
Enter the age of Paternal-father : 60
The person is Paternal-mother
Enter the name of Paternal-mother : Manisha
Enter the age of Paternal-mother : 57
The person is Maternal-fathers
Enter the name of Maternal-fathers : Jagdish
Enter the age of Maternal-fathers : 63
The person is Maternal_Mothers
Enter the name of Maternal_Mothers : Shruti
Enter the age of Maternal_Mothers : 60

//**Till here we had input from user.**( This line wont get printed , just to make destinction)

 1.All about your family tree !
Your name is:  Varsha | Your age is=20
2.Your Parents 
Your Father name is: Pushkar | His age is = 40 
Your Mother  name is: Mahima | Her age is = 38 
 3.Your Paternal-Parents 
Your paternal grand-father's name is : Rajendra |His age is = 60 
Your Paternal Grand-mother's name is : Manisha |Her age is = 57 
 4.Your Maternal-Parents 
Your maternal grand-father's nameis :  Jagdish |His age is = 63 
Your maternal grand-mother's name is :  Shruti |Her age is = 60 

//*This is the output for the input*( This line wont get printed , just to make destinction)
```
<img width="338" height="385" alt="image" src="https://github.com/user-attachments/assets/ecb6039f-edb9-4d77-83f8-ac2437359cd7" />

_Lets have a overview of my project_

This repo consist of my course Imperative Programming's Assignment.

The whole project revolves around taking the input from the user about his ownself , his parents (i.e mother and father) , his paternal grandparents , maternal grandparents and diaplaying the output in proper sequence, which ultimatey forms the family tree for **3 Genreation**.

The whole project is define in such a way that its take all inputs and displays outputs through the help of the function to **_avoid redundancy_** and make it much **_more efficient_** in terms of working.

All the function that we have define are designed to do some specific task that ultimately build our whole project. 

#### _Lets understand each functions and their roles_ 

```
typedef struct Person { 
    char name[50]; // Its specifies that a struct contain a variable name in which maximum characters that can be entered will 50 
    int age;// Its specifies that a struct contain a variable age of type int
    struct Person *father; //This specifies that the struct itself will consists of another struct
    struct Person *mother;//This specifies that the struct itself will consists of another struct
} Person; // Typedef is use to declare alias which ultimately reduces our effort instead of calling whole struct Person 'some instance of it ' we can directly call that struct by just calling by it alias that is Person.
```
Moreover, here we have define the how the **struct Person** structure is.

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
    return ptr; //Here we are defing the return type of the function. Here it expects returns type to be of pointer to struct.
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
**_This is the function that will help us to prints all the inputs. Moreover here we traversing from struct to other struct for a particular variable._**
```
void free_family_tree(Person *people[], int count){
        for ( int i=1 ; i <count; i++){
            free(people[i]);
            printf("free %d",i);
        }
    }
```
We know we allocated memory for every instances of the struct through malloc after and this is **_dynamic memory_** allocation which means it wont get free until we free it . So what this function does is that **_it runs a loop for all seven people and frees a memory of each instance of struct_**.


**Let see how we have define and called function in main**
```
    Person *myself;
    Person *father;
    Person *mother;
    Person *paternal_father;
    Person *paternal_mother;
    Person *maternal_father;
    Person *maternal_mother;
```

These are the struct pointer that we have define/instances.


```
   char *myname[] = {"Yourself" , "Father" , "Mother", "Paternal-father" , "Paternal-mother" , "Maternal-fathers" ,"Maternal_Mothers"  };
    
    char name0[100];
        int age0;
        int i=0;
        read_person_info(myname[i], name0 , &age0  );
        myself=create_person(name0 , age0 );
        
    
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
```

**I have create a array which contain all possible relationships so while calling the function read_person_info() we can ask user to enter the information for particular person.**

**Once we get the output from the function read_person_info we will use it as input for calling function create_person() . Moreover we assign the allocated memory to every instances that we have created.**


```
    link_parents(myself , father , mother );
    link_parents(father , paternal_father , paternal_mother);
    link_parents(mother , maternal_father, maternal_mother);
```
**We are calling function link_parents what it does is that is link children to their parents.**
```
print_family_relationships(myself);
```
**We willl be printing the whole family tree through calling function print_family. Moreover as we discussed that we will be traversing through struct. So here we will be traversing from myself to all other relations**
```
Person *arr[7]={myself , mother , father , maternal_father , maternal_mother , paternal_father , paternal_mother};
    free_family_tree(arr , 7);
```
**This function free_family will free all the dynamic memory that has been allocated.**

Last thing that we can do is that we can use valgrind that will ensure that there is no memory leaks. Since I was doing it on online C compiler I was unable to use valgrind command. Also in most of the cases when we are doing **free** there shouldn't be any memory leaks.


However what we do is that when we want to avoid and assure that there is no memory leak what we do is that we compile our code with -g . 
Then we will get by default ./a.out file. The we do : 

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out

(**refered to online command that sir has provided not really used it but have idea about it**) 




