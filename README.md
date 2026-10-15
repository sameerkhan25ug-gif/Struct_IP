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







