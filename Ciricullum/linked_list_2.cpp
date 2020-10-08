#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
};
typedef struct node Node;

struct headnode{
    Node* start;
    Node* end;
};
typedef struct headnode Headnode;

Node* insertAtBeg(int x,Headnode* h){
    Node* s=h->start;
    Node* first= (Node*) malloc(sizeof(Node));
    first->data=x;
    if(!h->start) {
        h->start=first;
        h->end=first;
        return h->start;
    }
    first->next=h->start;
    h->start=first;
    return h->start;
}
Node* insertAtEnd(int x,Headnode* h){
     Node* nend=(Node*) malloc(sizeof(Node));
     nend->data=x;
     nend->next=NULL;
     if(!h->end) {
         h->start=nend;
         h->end=nend;
         return h->start;
     }
     h->end->next=nend;
     h->end=nend;

     return  h->start;
}
Node* insertAfter(int a,int x,Headnode* h){
     Node* newNode=(Node*) malloc(sizeof(Node));
     newNode->data=x;
     newNode->next=NULL;
     Node* current=h->start;
     if(!h->start){
         h->end=newNode;
         h->start=newNode;
         return h->start;
     }
     while(current){
         if(current->data==a) break;
         if(!current->next) break;
         current=current->next;
     }
     newNode->next=current->next;
     current->next=newNode;
     if(!current->next) h->end=newNode;
     return h->start;
}
Node* Delete(int x,Headnode* h){
    Node* current=h->start;
    Node* prev=h->start;
    if(! current){
        printf("Node not fount\n");
        return h->start;
    }
    if(current->data==x){
        current=current->next;
        h->start=current;
        return h->start ;
    }
    current=current->next;
    while(current){
        if(current->data==x) break;
        current=current->next;
        prev=prev->next;
    }
    if(!prev->next) {
        prev->next=NULL;
        h->end=current;
    }
    if(!current) {
        printf("Node not fount\n");
        return h->start ;
    }
    prev->next=current->next;
    printf("Node deleted\n");
    free(current);
    return h->start;
}
int countNodes(Node* s){
    if(!s) return 0;
    Node* current=s;
    int count=0;
    while(current){
        current=current->next;
        count++;
    }
    return count;
}
int minimum(Node* s ){
    if(!s){
        printf("List is empty! try again\n");
        return 0;
    }
    int mini=INT_MAX;
    Node* current=s;
    while(current){
        if(current->data<mini) {
            mini=current->data;
        }
        current=current->next;
    }
    printf("Minimum node value : %d \n",mini);
    return mini;
}

int maximum(Node* s ){
    if(!s){
        printf("List is Empty! try again\n");
        return 0;
    }
    int maxi=INT_MIN;
    Node* current=s;
    while(current){
        if(current->data>maxi) {
            maxi=current->data;
        }
        current=current->next;
    }
    printf("Maximum node value : %d \n",maxi);
    return maxi;
}
void search(Node* s,int x){
    Node* current=s;
    int index=-1;
    while(current){
        index++;
        if(current->data==x) break;
        current=current->next;
    }
    if(!current) {
        printf("Node not fount\n");
        return;
    }
    printf("Node is present at index %d (starting from 0)\n",index);
    return ;
}

void displayList(Node* s,Headnode* h){
    printf("List: ");
    Node* current=s;
    while(current){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
    return ;
}
int main() {
    int choice;int x;int y;
    Node* s=NULL;
    Headnode h;
    h.start=NULL;
    h.end=NULL;
    printf("Menu\n1.Insert at beggining\n2.Insert At end\n3.InsertAfter\n4.Delete a Node\n5.Count Nodes\n6.Find Minimum\n7.Find Maximum\n8.Search a value.\n9.Display the list\n10. Exit\n");
    label:
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the no.to be inserted at beginning: \n");
            scanf("%d",&x);
            s=insertAtBeg(x,&h);
            // cout<<s->data<<"()\n";
            printf("Inserted.\n");
            displayList(s,&h);
            goto label;
        case 2:
            printf("Enter the no.to be inserted at end: \n");
            scanf("%d",&x);
            s=insertAtEnd(x,&h);
            printf("Inserted.\n");
            displayList(s,&h);
            goto label;
        case 3:
            printf("Enter the no.to be inserted : \n");
            scanf("%d",&x);
            printf("Enter the no.to be inserted after: \n");
            scanf("%d",&y);
            s=insertAfter(y,x,&h);
            printf("Inserted.\n");
            displayList(s,&h);
            goto label;
        case 4:
            printf("Enter the node to be deleted: \n");
            scanf("%d",&x);
            s=Delete(x,&h);
            displayList(s,&h);
            goto label;
        case 5:
            x= countNodes(s);
            printf("There are %d in this linked list\n",x);
            displayList(s,&h);
            goto label;
        case 6:
            minimum(s);
            goto label;
        case 7:
            maximum(s);
            goto label;
        case 8:
            printf("Enter the no.to be searched: \n");
            scanf("%d",&x);
            search(s,x);
            displayList(s,&h);
            goto label;
        case 9:
            displayList(s,&h);
            goto label;
        case 10:
            break;
    }
    return 0;

}