#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

struct S{
    node *start; //earliset referenced node
    node *end; //latest referenced node
    int size; //size of the S
};

typedef struct S S;
typedef struct node node;

void insert(int num, S *s){
    if(s->size == 20){
        //we delete the first node as it was the earliest refrenced
        node *del = s->start;
        node *cur2 = s->start;
        node* prev2 = NULL;
        while(cur2!=NULL && num != cur2->data){
            prev2 = cur2;
            cur2 = cur2->next;
        }
        if(cur2 == NULL){
            //we delete the first pointer and then insert a new pointer at the end
            node* f = s->start;
            s->start = s->start->next; //delete first pointer
            free(f);
            s->size--;
            node * temp = new node();
            temp->data = num;
            temp->next = NULL;
            s->end->next = temp; //insert at the end
            s->end = s->end->next;
            s->size++;
        }else{
        //we encountered previously entered value
        //we push this value to the back
            s->end->next = cur2;
            cur2->next = NULL;
            s->end = s->end->next;
            prev2->next = cur2->next;
        }
        return;
    }
    node *cur = s->start;
    node *prev = NULL;
    while(cur!=NULL && num != cur->data){
        prev = cur;
        cur = cur->next;
    }
    if(cur == NULL){
        //we insert the new node at the back of the data structure
        node * temp = new node();
        temp->data = num;
        temp->next = NULL;
        s->end->next = temp;
        s->end = s->end->next;
        s->size++;
    }else{
        //we encountered previously entered value
        //we push this value to the back to update it's reference
        s->end->next = cur;
        s->end = s->end->next;
        prev->next = cur->next;
        cur->next = NULL;
    }
}