#include<iostream>
#include<stack>

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

node *insertBegin(node *s, int x){
    node *q = (node*)malloc(sizeof(node));
    q->val = x;
    if(s==NULL){
        s = q;
        s->next = NULL;
        return s;
    }
    node *p = s;
    q->next = s;
    s = q;
    return s;
}

node *insertAfter(node *s, int x,int num){
    node *q = (node*)malloc(sizeof(node));
    q->val = x;
    if(s == NULL){
        s = q;
        s->next = NULL;
        return s;
    }
    node *p = s;
    while(p!=NULL && p->val!=num){
        p = p->next;
    }
    if(p!=NULL){
        node *nxt = p->next;
        p->next = q;
        q->next = nxt;
    }
    return s;
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
            cout<<"Node found first at position"<<" "<<i<<"\n";
            return;
        }
        p = p->next;
        i++;
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

void reverse(node *s){
    node *prev = NULL;
    node *cur = s;
    while(cur != NULL){
        node *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
}

void cycle_detection(node *s){
    node *slow = s, *fast = s;
    while(slow != NULL && fast != NULL){
        if(slow == fast){
            cout<<"Cyclic Linked list\n";
            return;
        }
        fast = fast->next;
        slow = slow->next;
        if(fast){
            fast = fast->next;
        }
    }
    cout<<"Not cyclic\n";
}

int main(){
    int choice,num,x;
    node *s;
    int n = 0;
    do{
        cout<<"INSERT(1)"<<endl;
        cout<<"DELETE(2)"<<endl;
        cout<<"SEARCH(3)"<<endl;
        cout<<"DISPLAY(4)"<<endl;
        cout<<"COUNT(5)"<<endl;
        cout<<"INSERT START(6)"<<endl;
        cout<<"INSERT AFTER(7)"<<endl;
        cout<<"EXIT(8)"<<endl;
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
            cin>>num;
            s = insertBegin(s,num);
            break;
        case 7:
            cin>>num>>x;
            s = insertAfter(s,x,num);
            break;
        case 8:
            cout<<"THANK YOU FOR INTERACTING"<<endl;
            break;
        default:
            cout<<"PLEASE ENTER A VALID QUERY"<<endl;
            break;
        }
    }while(choice!=8);
}