#include<iostream>

using namespace std;

struct node{
    int val;
    node *next;
};

struct headnode{
    node* start;
    node* end;
};



headnode* insert(headnode *h, int x){
    node* q = (node*)malloc(sizeof(node));
    q->val = x;
    q->next = NULL;
    if(h->start == NULL){
        h->start = q;
        h->end = q;
        return h;
    }
    else{
        h->end->next = q;
        h->end = q;
        return h;
    }
}

headnode* erase(headnode *h, int x){
    if(h->start == NULL){
        cout<<"Linked List Is Empty"<<"\n";
    }
    node* p = h->start;

    if(p->val == x){
        h->start = h->start->next;
        return h;
    }
    node* q = NULL;
    while(p->val!=x && p!=NULL){
        q = p;
        p = p->next;
    }
    if(p == NULL){
        cout<<"Node Not Found"<<"\n";
        return h;
    }
    q->next = p->next;
    // free(p);
    cout<<"Deleted"<<" "<<x<<"\n";
    return h;
}

void search(headnode *h, int x){
    if(h->start == NULL){
        cout<<"Linked List is empty"<<"\n";
    }
    node *p = h->start;
    int i = 1;
    while(p!=NULL){
        if(p->val == x){
            cout<<"Node found first at position"<<" "<<x<<"\n";
            return;
        }
        p = p->next;
    }
    cout<<"Node Not Found"<<"\n";
}

void count(headnode *h){
    node* p = h->start;
    int i = 0;
    while(p!=NULL){
        i++;
        p = p->next;
    }
    cout<<"Number of Nodes = "<<i<<"\n";
}

void display(headnode *h){
    node *p = h->start;
    while(p!=NULL){
        cout<<p->val<<" -> ";
        p = p->next;
    }cout<<"\n";
}

int main(){
    int choice,num;
    headnode h;
    h.start = NULL;
    h.end = NULL;
    // h->start = p;
    // h->end = p;
    // h->start = NULL;
    // h->end = NULL;
    do{
        cout<<"INSERT(1)"<<endl;
        cout<<"DELETE(2)"<<endl;
        cout<<"SEARCH(3)"<<endl;
        cout<<"DISPLAY(4)"<<endl;
        cout<<"COUNT(5)"<<endl;
        cout<<"EXIT(6)"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cin>>num;
            insert(&h,num);
            break;
        case 2:
            cin>>num;
            erase(&h,num);
            break;
        case 3:
            cin>>num;
            search(&h,num);
            break;
        case 4:
            display(&h);
            break;
        case 5:
            count(&h);
            break;
        case 6:
            cout<<"THANK YOU FOR INTERACTING"<<endl;
            break;
        default:
            cout<<"PLEASE ENTER A VALID QUERY"<<endl;
            break;
        }
    }while(choice!=6);
}



// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>
// struct node{
//     int data;
//     struct node* next;
// };
// typedef struct node Node;

// struct headnode{
//     Node* start;
//     Node* end;
// };
// typedef struct headnode Headnode;

// Node* insertAtBeg(Node* s,int x,Headnode* h){
//     Node* first= (Node*) malloc(sizeof(Node));
//     first->data=x;
//     if(!h->start) {
//         s=first;
//         h->start=s;
//         h->end=s;
//         return s;
//     }
//     first->next=h->start;
//     s=first;
//     h->start=s;
//     return s;
// }
// Node* insertAtEnd(Node* s,int x,Headnode* h){
//      Node* end=(Node*) malloc(sizeof(Node));
//      end->data=x;
//      end->next=NULL;
//      if(!h->end) {
//          s=end;
//          h->start=s;
//          h->end=s;
//          return s;
//      }
//      h->end->next=end;
//      h->end=end;
//      return  s;
// }
// Node* insertAfter(Node* s,int a,int x,Headnode* h){
//      Node* newNode=(Node*) malloc(sizeof(Node));
//      newNode->data=x;
//      Node* current=s;
//      while(current){
//          if(current->data==a) break;
//          if(!current->next) break;
//          current=current->next;
//      }
//      newNode->next=current->next;
//      current->next=newNode;
//      if(!current->next) h->end=current;
//      return s;
// }
// void Delete(Node* s ,int x,Headnode* h){
//     Node* current=s;
//     Node* prev=s;
//     if(current->data==x){
//         s=s->next;
//         return ;
//     }
//     current=current->next;
//     while(current){
//         if(current->data==x) break;
//         current=current->next;
//         prev=prev->next;
//     }
//     if(!current->next) h->end=current;
//     if(!current) {
//         printf("Node not fount\n");
//         return ;
//     }
//     prev->next=current->next;
//     printf("Node deleted\n");
//     free(current);
//     return ;
// }
// int countNodes(Node* s){
//     Node* current=s;
//     int count=0;
//     while(current){
//         current=current->next;
//         count++;
//     }
//     return count;
// }
// int minimum(Node* s ){
//     int mini=INT_MAX;
//     Node* current=s;
//     while(current){
//         if(current->data<mini) {
//             mini=current->data;
//         }
//         current=current->next;
//     }
//     return mini;
// }

// int maximum(Node* s ){
//     int maxi=INT_MIN;
//     Node* current=s;
//     while(current){
//         if(current->data>maxi) {
//             maxi=current->data;
//         }
//         current=current->next;
//     }
//     return maxi;
// }
// void search(Node* s,int x){
//     Node* current=s;
//     int index=-1;
//     while(current){
//         index++;
//         if(current->data==x) break;
//         current=current->next;
//     }
//     if(!current) {
//         printf("Node not fount\n");
//         return;
//     }
//     printf("Node is present at index %d (starting from 0)\n",index);
//     return ;
// }

// void displayList(Node* s,Headnode* h){
//     printf("List: ");
//     Node* current=s;
//     while(current!=h->end->next){
//         printf("%d ",current->data);
//         current=current->next;
//     }
//     printf("\n");
//     return ;
// }
// int main() {
//     int choice;int x;int y;
//     Node* s=NULL;
//     Headnode h;
//     h.start=NULL;
//     h.end=NULL;
//     printf("Menu\n1.Insert at beggining\n2.Insert At end\n3.InsertAfter\n4.Delete a Node\n5.Count Nodes\n6.Find Minimum\n7.Find Maximum\n8.Search a value.\n9.Display the list\n10. Exit\n");
//     label:
//     printf("Enter your choice: ");
//     scanf("%d",&choice);
//     switch(choice){
//         case 1:
//             printf("Enter the no.to be inserted at beginning: \n");
//             scanf("%d",&x);
//             s=insertAtBeg(s,x,&h);
//             printf("Inserted.\n");
//             displayList(s,&h);
//             goto label;
//         case 2:
//             printf("Enter the no.to be inserted at end: \n");
//             scanf("%d",&x);
//             s=insertAtEnd(s,x,&h);
//             printf("Inserted.\n");
//             displayList(s,&h);
//             goto label;
//         case 3:
//             printf("Enter the no.to be inserted : \n");
//             scanf("%d",&x);
//             printf("Enter the no.to be inserted after: \n");
//             scanf("%d",&y);
//             insertAfter(s,y,x,&h);
//             printf("Inserted.\n");
//             displayList(s,&h);
//             goto label;
//         case 4:
//             printf("Enter the node to be deleted: \n");
//             scanf("%d",&x);
//             Delete(s,x,&h);
//             displayList(s,&h);
//             goto label;
//         case 5:
//             x= countNodes(s);
//             printf("There are %d in this linked list\n",x);
//             displayList(s,&h);
//             goto label;
//         case 6:
//             x=minimum(s);
//             printf("Minimum node value : %d \n",x);
//             goto label;
//         case 7:
//             x= maximum(s);
//             printf("Maximum node value : %d \n",x);
//             goto label;
//         case 8:
//             printf("Enter the no.to be searched: \n");
//             scanf("%d",&x);
//             search(s,x);
//             displayList(s,&h);
//             goto label;
//         case 9:
//             displayList(s,&h);
//             goto label;
//         case 10:
//             break;
//     }
//     return 0;

// }