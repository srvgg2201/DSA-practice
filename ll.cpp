#include<iostream>
using namespace std;

struct node{
    int key;
    struct node* next;
};

struct node *head = NULL;


//function to insert node at the beginning
void insert(int data) {
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->key = data;
    new_node->next = head;
    // if(head == NULL) {      
    //     start = new_node;   //inserting starting node
    // }
    head = new_node;
}

//function to insert node at end        O(n) : can be optimized to O(1) if a tail pointer is used.
void append(int data) {       
    if(head == NULL) {      //list is empty
        insert(data);
    }
    else {                  //list contains at least one element
        struct node* s;
        for(s = head; s->next != NULL; s = s->next);  //traverse till last filled node
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->key = data;
        new_node->next = NULL;
        s->next = new_node;
    }
}

void delete_val(int val) {
    struct node* s = head;
    struct node* prev;
    //value to be deleted is held at the head
    if(s != NULL && s->key == val) {
        head = s->next;
        free(s);
        return;
    }

    //traverse to the value to be deleted keeping track of previous node
    for(s = head; s->key != val && s != NULL ; s=s->next) {
        prev = s;       
    }
    if(s == NULL) cout << "Value not found\n";
    else {
        prev->next = s->next; 
        free(s);
    }
}

void print_list() {
    for(struct node* s = head; s!= NULL; s=s->next) {
        if(s->next == NULL) cout << s->key << "->NULL\n";
        else cout << s->key << "->";
    }
}

void reverse() {
    struct node *prev = NULL, *next = NULL, *curr = head; //using three pointers, prev as NULL,next as NULL, current as head
    while(curr != NULL) {
        next = curr->next;  // store next node of current node in next
        curr->next = prev;  // change the next of current node to previous node
        prev = curr;        // store current node in prev
        curr = next;        // change current node pointer to next
    }
    head = prev;            // prev shall point to the last node after loop completes. Make last node the new head.
}



int main() {
   
    append(0);
    append(1);
    append(2);
    append(3);
    append(4);
    print_list();
    reverse();
    print_list();
    return 0;
}