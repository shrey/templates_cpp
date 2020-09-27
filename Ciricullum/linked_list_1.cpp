#include<iostream>

using namespace std;

struct node{
    int val;
    node *next;
};

node* insert(node *s, int x){
    node* q = (node*)malloc(sizeof(node));
    q->val = x;
    if(s == NULL){
        s = q;
        s->next = NULL;
        return s;
    }
    else{
        node *p = s;
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = q;
        q->next = NULL;
        return s;
    }
}

node* erase(node *s, int x){
    if(s == NULL){
        cout<<"Linked List Is Empty"<<"\n";
    }
    node* p = s;
    node* q = NULL;
    while(p->val!=x && p!=NULL){
        q = p;
        p = p->next;
    }
    if(p == NULL){
        cout<<"Node Not Found"<<"\n";
        return s;
    }
    q->next = p->next;
    // free(p);
    cout<<"Deleted"<<" "<<x<<"\n";
    return s;
}

void search(node *s, int x){
    if(s == NULL){
        cout<<"Linked List is empty"<<"\n";
    }
    node *p = s;
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

void count(node *s){
    node* p = s;
    int i = 0;
    while(p!=NULL){
        i++;
        p = p->next;
    }
    cout<<"Number of Nodes = "<<i<<"\n";
}

void display(node *s){
    node *p = s;
    while(p!=NULL){
        cout<<p->val<<" -> ";
        p = p->next;
    }cout<<"\n";
}

int main(){
    int choice,num;
    node *s;
    int n = 0;
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
            s = insert(s,num);
            break;
        case 2:
            cin>>num;
            s = erase(s,num);
            break;
        case 3:
            cin>>num;
            search(s,num);
            break;
        case 4:
            display(s);
            break;
        case 5:
            count(s);
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