#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define HASH_TABLE_SIZE 10
//Define a struct for a hash table
struct hash_node{
    char *key;//this is key
    int value;//this is value that will be printed if you passed the key
    struct hash_node *next;
};
//Define the hash table structure
struct hash_table{
    struct hash_node *bucket[HASH_TABLE_SIZE];
};
//Hash function to calculate the index for a given key
unsigned int hash(const char *key){
    unsigned int hash=0;
    while(*key){
        hash= (hash *31)+ *key++;
    }
    return hash %HASH_TABLE_SIZE;
}
//Create new node
struct hash_node *create_hash_node(const char *key,int value){
    struct hash_node *new_node=(struct hash_node*) malloc(sizeof (struct hash_node));
    if (new_node){
        new_node->key = strdup(key);
        new_node->value = value;
        new_node->next = NULL;
    }
    return new_node;
}
void insert(struct hash_table *table,const char *key,int value){
    unsigned int index = hash(key);
    struct hash_node *current=table->bucket[index];
    struct hash_node *prev =NULL;
    while(current!=NULL){
        if(strcmp(current->key,key)==0){
            printf("The Element is already exist \nif you want to overwrite enter 1\n if it is just a mistake enter any thing");
            int overwrite;
            scanf("%d",&overwrite);
            if (overwrite==1)
                current->value=value;
            else
                return;

        }
        prev = current;
        current=current->next;
    }
    struct hash_node *new_node= create_hash_node(key,value);
    if (new_node==NULL){
        printf("Memory allocation failed");
        return;
    }
    else{
        if (prev==NULL){
            table->bucket[index]=new_node;
        }
        else{
            prev->next=new_node;
        }
    }

}
int get (struct hash_table *table,const char *key){
    unsigned int index= hash(key);
    struct hash_node *current = table->bucket[index];
    while (current!=NULL){
        if(strcmp(current->key,key)==0){
            return current ->value;
        }
        current=current->next;
    }
    return -1;
}

int main() {
    struct hash_table table = {NULL};
    printf("Hello, World!\n");
    insert(&table, "apple", 5);
    insert(&table, "apple", 99);

    insert(&table, "banana", 10);
    insert(&table, "orange", 15);
    insert(&table, "pple", 5);
    insert(&table, "aple", 99);

    insert(&table, "banaa", 10);
    insert(&table, "orane", 15);
    insert(&table, "appe", 5);
    insert(&table, "appl", 99);

    insert(&table, "banan", 10);
    insert(&table, "orang", 15);
    printf("Value for key 'apple': %d\n", get(&table, "apple"));
    printf("Value for key 'apple': %d\n", get(&table, "apple"));
    printf("Value for key 'banana': %d\n", get(&table, "banana"));
    printf("Value for key 'orange': %d\n", get(&table, "orange"));
    printf("Value for key 'grape': %d\n", get(&table, "grape")); // This should return -1 (not found)

    return 0;
}
