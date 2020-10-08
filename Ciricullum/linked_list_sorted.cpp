#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node Node;


Node* insertAfter(Node* s,int x){
     Node* newNode=(Node*) malloc(sizeof(Node));
     newNode->data=x;
     Node* current=s?s->next:NULL;
     Node* prev=s;
     if(!s){
         return newNode;
     }
     if(prev->data>x){
         newNode->next=prev;
         return newNode;
     }
     while(current){
         if(current->data > x) break;
         prev=current;
         current=current->next;

     }
     prev->next=newNode;
     newNode->next=current;
     return s;
}

Node* Delete(Node* s ,int x){
    Node* current=s;
    Node* prev=s;
    if(! s){
        printf("Node not fount\n");
        return s;
    }
    if(current->data==x){
        s=s->next;
        return s;
    }
    current=current->next;
    while(current){
        if(current->data==x) break;
        if(current->data>x){
            printf("Node not fount\n");
            return s;
        }
        current=current->next;
        prev=prev->next;
    }
    if(!current) {
        printf("Node not fount\n");
        return s ;
    }
    prev->next=current->next;
    printf("Node deleted\n");
    free(current);
    return s;
}
int countNodes(Node* s){
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
    printf("Minimum node value : %d \n",s->data);
    return 0;
}

int maximum(Node* s ){
    if(!s){
        printf("List is Empty! try again\n");
        return 0;
    }
    Node* current=s;
    while(current->next){
        current=current->next;
    }
    printf("Maximum node value : %d \n",current->data);
    return 0;
}

void search(Node* s,int x){
    Node* current=s;
    int index=-1;
    while(current){
        index++;
        if(current->data==x) break;
        if(current->data>x){
            current=NULL;
            break;
        }
        current=current->next;
    }
    if(!current) {
        printf("Node not fount\n");
        return;
    }
    printf("Node is present at index %d (starting from 0)\n",index);
    return ;
}

void displayList(Node* s){
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
    printf("Menu\n1.Insert\n2.Delete a Node\n3.Count Nodes\n4.Find Minimum\n5.Find Maximum\nSe6.arch a value.\n7.Display the list\n8 Exit\n");
    label:
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the no.to be inserted : \n");
            scanf("%d",&x);
            s=insertAfter(s,x);
            printf("Inserted.\n");
            displayList(s);
            goto label;
        case 2:
            printf("Enter the node to be deleted: \n");
            scanf("%d",&x);
            s=Delete(s,x);
            displayList(s);
            goto label;
        case 3:
            x= countNodes(s);
            printf("There are %d in this linked list\n",x);
            displayList(s);
            goto label;
        case 4:
            x=minimum(s);
            goto label;
        case 5:
            x= maximum(s);
            goto label;
        case 6:
            printf("Enter the no.to be searched: \n");
            scanf("%d",&x);
            search(s,x);
            displayList(s);
            goto label;
        case 7:
            displayList(s);
            goto label;
        case 8:
            break;
    }
    return 0;
}