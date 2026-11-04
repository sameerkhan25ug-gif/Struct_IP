
// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Taxon {
    char name[50];
    int lifespan;              
    struct Taxon *parent_group;
} Taxon;

    


Taxon* create_taxon(const char *name, int lifespan){
    Taxon *ptr= (Taxon*)(malloc(sizeof(Taxon)));
    if(ptr==NULL){
        printf("Memory allocation failed");
        
    }
    strcpy(ptr->name, name);
    ptr->lifespan=lifespan;
    struct Taxon *parent_group=NULL;

    return ptr;
    
}
void read_taxon_info(const char *label, char *name_out, int *lifespan_out){
    printf("The element of taxon is %s\n",label);
    printf("Enter the name : ");
    scanf("%s",name_out);
    printf("Enter the lifespan : ");
    scanf("%d",lifespan_out);
           
}
void link_parent(Taxon *child, Taxon *parent){
    child->parent_group=parent;
    
}
void print_taxonomy(Taxon *family){
    printf("This is family \n");
    printf("The family 's name is %s",family->name);
    printf("The family 's name is %d",family->lifespan);
    printf("This is Genera 1 \n");
    printf("The Genera 1  name is %s\n",family->parent_group->name);
    printf("The Genera 1 name is %d\n",family->parent_group->lifespan);
    printf("This is Genera 2 \n");
    printf("The Genera 2 name is %s\n",family->parent_group->parent_group->name);
    printf("The Genera 2 name is %d\n",family->parent_group->parent_group->lifespan);

    printf("This is Species 1 \n");
    printf("The Species 1 name is %s\n",family->parent_group->parent_group->parent_group->name);
    printf("TheSpecies 1 name is %d\n",family->parent_group->parent_group->parent_group->lifespan);
 
    printf("This is Species 2 \n");
    printf("The Species 2 name is %s\n",family->parent_group->parent_group->parent_group->parent_group->name);
    printf("TheSpecies 2 name is %d\n",family->parent_group->parent_group->parent_group->parent_group->lifespan);

    printf("This is Species 3 \n");
    printf("The Species 3 name is %s\n",family->parent_group->parent_group->parent_group->parent_group->parent_group->name);
    printf("TheSpecies 3 name is %d\n",family->parent_group->parent_group->parent_group->parent_group->parent_group->lifespan);

    printf("This is Species 4\n");
    printf("The Species 3 name is %s\n",family->parent_group->parent_group->parent_group->parent_group->parent_group->parent_group->name);
    printf("TheSpecies 3 name is %d\n",family->parent_group->parent_group->parent_group->parent_group->parent_group->parent_group->lifespan);
}
    


void free_tree(Taxon *all_taxa[], int total_count){
    for ( int i=0 ; i < total_count ; i++){
        free(all_taxa[i]);
        printf("Freed %d",i);
    }
}


int main() {

    Taxon *family;
    Taxon *Genera1;
    Taxon *Genera2;
    Taxon *species1;
    Taxon *species2;
    Taxon *species3;
    Taxon *species4;
    char *elements[]={"Family ", "Genera1", "Genera 2 ", "Species 1 ", "Species 2 ", "Species 3 ",  "Species 4 " };
    
    int i=0; 
    char family_Main[100];
    int lifespan_fam;
    read_taxon_info(elements[i],family_Main , &lifespan_fam );
    family=create_taxon(family_Main , lifespan_fam);
     printf("Memory allocated is %p\n",family);
    
    i++; 
    char genera1[100];
    int lifespan_G1;
    read_taxon_info(elements[i],genera1 , &lifespan_G1 );
    Genera1=create_taxon(genera1 , lifespan_G1);
     printf("Memory allocated is %p\n",Genera1);

    i++;
    char genera2[100];
    int lifespan_G2;
    read_taxon_info(elements[i],genera2 , &lifespan_G2 );
    Genera2=create_taxon(genera1 , lifespan_G2);
    printf("Memory allocated is %p\n",Genera2);
    
    i++;
    char Species1[100];
    int lifespan_S1;
    read_taxon_info(elements[i], Species1 , &lifespan_S1 );
    species1=create_taxon(Species1 , lifespan_S1);
    printf("Memory allocated is %p\n",Species1);
    
    
    
    i++;
    char Species2[100];
    int lifespan_S2;
    read_taxon_info(elements[i], Species2 , &lifespan_S2);
    species2=create_taxon(Species2 , lifespan_S2);
    printf("Memory allocated is %p\n",Species2);
    
    
    

    i++;
    char Species3[100];
    int lifespan_S3;
    read_taxon_info(elements[i],Species3 , &lifespan_S3);
    species3=create_taxon(Species3 , lifespan_S3);
    printf("Memory allocated is %p\n",Species3);
    

    i++;
    char Species4[100];
    int lifespan_S4;
    read_taxon_info(elements[i],Species4 , &lifespan_S4);
    species4=create_taxon(Species4 , lifespan_S4);
    printf("Memory allocated is %p\n",Species4);  

    link_parent(family ,Genera1 );
    link_parent(Genera1 ,Genera2 );
    link_parent(Genera2 ,species1 );
    link_parent(species1 ,species2 );
    link_parent(species2 ,species3 );
    link_parent(species3 ,species4 );
                               
    print_taxonomy(family);

    Taxon *arr[7]={family , Genera1 , Genera2 ,species1, species2, species3, species4 };

    free_tree(arr , 7);

    

    
    
    
    return 0;
}