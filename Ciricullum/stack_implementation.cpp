

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



#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map
#define mp make_pair

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define size 20

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

struct Stack{
    int top;
    int A[size];
};

void push(Stack *s, int val){
    if(s->top == size-1){
        cout<<"Stack Is Full"<<endl;
        return;
    }
    s->top = s->top+1;
    s->A[s->top] = val;
    return;
}

int pop(Stack *s){
    int x;
    if(s->top == -1){
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    x = s->A[s->top];
    s->top = s->top-1;
    return x;
}
void display(Stack *s){
    int i = s->top;
    cout<<"The stack contents are as follows: "<<endl;
    while(i>=0){
        cout<<s->A[i]<<" ";
        i--;
    }cout<<endl;
}


int main(){
    Stack s;
    int choice;
    int n = 0;
    s.top = -1;
    do{
        cout<<"Push(1)"<<endl;
        cout<<"Pop(2)"<<endl;
        cout<<"Display(3)"<<endl;
        cout<<"Exit(4)"<<endl;
        cin>>choice;
        switch (choice)
        {
            case 1: {
                        int num;
                        cout<<"Enter the number: ";
                        cin>>num;
                        push(&s,num);
                        break;
                    }
            case 2: {
                        int t = pop(&s);
                        if(t!=-1){
                            cout<<t<<" was popped"<<endl;
                        }
                        break;
                    }
            case 3: {
                        display(&s);
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