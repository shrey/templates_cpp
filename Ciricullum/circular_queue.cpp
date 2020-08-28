

//Shrey Dubey

//Contact Me at wshrey09@gmail.com



#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
#include<set>
#include<list>
#include<iomanip>
#include<queue>
#include<stack>
#include <math.h>

#define size 5
using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

struct Queue{
    int A[size];
    int front;
    int rear;
};

int isFull(Queue *q){
    if((q->rear+1)%size == q->front){
        return 1;
    }
    return 0;
}

int isEmpty(Queue *q){
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}

void insert(Queue *q, int x){
    if(isFull(q)){
        cout<<"Queue is Full"<<endl;
        return;
    }
    q->A[q->rear] = x;
    q->rear = (q->rear+1)%size;
}
int deleteq(Queue *q){
    if(q->rear == q->front){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    int x = q->A[q->front];
    q->front = (q->front+1)%size;
    return x;
}



void display(Queue *q){
    if(isEmpty(q)){
        cout<<"Queue is Empty"<<endl;
        return;
    }
    for(int i = q->front; i!=q->rear; i = (i+1)%size){
        cout<<q->A[i]<<" ";
    }cout<<endl;
}

int main(){
    Queue q;
    q.front = 0;
    q.rear = 0;
    int choice;
     do{
        cout<<"Insert(1)"<<endl;
        cout<<"Delete(2)"<<endl;
        cout<<"Display(3)"<<endl;
        cout<<"Exit(4)"<<endl;
        cin>>choice;
        switch (choice)
        {
            case 1: {
                        int num;
                        cout<<"Enter the number: ";
                        cin>>num;
                        insert(&q,num);
                        break;
                    }
            case 2: {
                        int t = deleteq(&q);
                        if(t!=-1){
                            cout<<t<<" was Deleted"<<endl;
                        }
                        break;
                    }
            case 3: {
                        display(&q);
                        break;
                    }
            case 4: {
                        cout<<"Thank You For Interacting"<<endl;
                        break;
                    }
            default:
                    {
                        cout<<"Please Enter Valid Key"<<endl;
                    }

        }
    }while(choice!=4);
}