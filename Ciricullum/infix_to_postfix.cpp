

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
#define size 1000


#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

struct Stack{
    int top;
    char A[size];
};

void push(Stack *s, char val){
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


void infixToPostfix(){
    Stack s;
    push(&s,'a');
    push(&s,'b');
    display(&s);
    pop(&s);
    display(&s);
}

int main(){
    infixToPostfix();
}