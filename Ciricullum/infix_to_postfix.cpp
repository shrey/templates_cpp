#include <iostream>
#define size 20
struct Stack{
    char A[size];
    int top;
};
typedef struct Stack myStack;

void push(myStack *s,char x){
    if(s->top==size-1){
        printf("Stack is full\n");
        return ;
    }
    s->top=s->top+1;
    s->A[s->top]=x;
    return;
}
char pop(myStack* s){
    char x;
    if(s->top==-1) {
        printf("Stack is empty\n");
        return '.';
    }
    x=s->A[s->top];
    s->top=s->top-1;
    return x;
}

int icp(char a){
    if(a=='^') return 0;
    else if(a=='*' || a=='/') return 1;
    else if(a=='+' || a== '-') return 2;
    else if (a=='(') return 3;
    return -1;
}
bool isOperator(char a){
    if(a=='*' ||a=='^' ||a=='+' || a=='-' || a=='/' ){
        return true;
    }
    return false;
}

int main() {
    myStack s;
    s.top=-1;
    char infix[30],postfix[30];
    int l=0;
    do{
        scanf("%c", &infix[l]);
        l++;
    }while(infix[l-1]!=' ');
    infix[l-1]='\0';
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(infix[i]>='a' && infix[i]<='z'){
                if(infix[i+1]!='\0' && infix[i+1]>='a' && infix[i+1]<='z'){
                printf("There should not be characters immediately after another character.");
                return 0;
            }
             if(infix[i+1]!='\0' && (infix[i+1]=='(')){
                printf("Parenthesis without prior operator.");
                return 0;
                }
            postfix[j++]=infix[i];
        }
        else if(infix[i]==')'){
            if(infix[i+1]!='\0' && infix[i+1]>='a' && infix[i+1]<='z'){
                printf("There should not be characters immediately after parenthesis.");
                return 0;
            }
            while(s.A[s.top]!='('){
                if(s.top==-1){
                    printf("Parenthesis are not balanced");
                    return 0;
                  }
                postfix[j++]=pop(&s);
            }
            pop(&s);
        }
        else if(infix[i]=='('){
             if(infix[i+1]=='\0') {
                printf("No operand after operator.");
                return 0;
             }
             else if(isOperator(infix[i+1])){
                 printf("Operator immediately after operator.Try Again.");
                 return 0;
             }
            push(&s,infix[i]);
        }
        else if(isOperator(infix[i]) ){
             if(infix[i+1]=='\0') {
                printf("No operand after operator.");
                return 0;
             }
             else if(isOperator(infix[i+1])){
                 printf("Operator immediately after operator.Try Again.");
                 return 0;
             }
             while(s.top!=-1 && icp(infix[i])>=icp(s.A[s.top])){
                postfix[j++]=pop(&s);
            }
             push(&s,infix[i]);
        }
        else{
            printf("Wrong Character input .Try again!");
            return 0;
        }
        i++;
    }
    while(s.top!=-1){
        if(s.A[s.top]=='('){
           printf("closing parenthesis not found.");
           return 0;
        }
        postfix[j++]=pop(&s);
    }

    postfix[j]='\0';
    int k=0;
    while( postfix[k] != '\0' ){
        printf("%c ",postfix[k]);
        k++;
    }
    return 0;
}