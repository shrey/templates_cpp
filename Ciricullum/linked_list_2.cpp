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
    headnode *h;
    node *p = NULL;
    h->start = p;
    h->end = p;
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
            h = insert(h,num);
            break;
        case 2:
            cin>>num;
            h = erase(h,num);
            break;
        case 3:
            cin>>num;
            search(h,num);
            break;
        case 4:
            display(h);
            break;
        case 5:
            count(h);
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