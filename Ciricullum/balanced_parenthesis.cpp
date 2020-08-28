#include<iostream>

using namespace std;
#define size 100

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

int isEmpty(Stack *s){
    if(s->top == -1){
        return 1;
    } return 0;
}

int isBalanced(char input[]){
    Stack s;
    s.top = -1;
    int i = 0;
    while(input[i]!='\0'){
        if(input[i] == '('){
            push(&s,input[i]);
        }
        else if(input[i] == ')'){
            if(isEmpty(&s)){
                return 0;
            }
            pop(&s);
        }
        i++;
    }
    if(!isEmpty(&s)){
        return 0;
    }
    return 1;
}

int main(){
    char input[100];
    cin>>input;
    if(isBalanced(input)){
        cout<<"Balanced"<<endl;
    }else{
        cout<<"Not Balanced"<<endl;
    }
}