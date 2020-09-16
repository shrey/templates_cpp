#include <iostream>

using namespace std;

inline int add(int a, int b){
    return (a+b);
}

inline int multiply(int a, int b){
    return (a*b);
}

inline int divide(int a, int b){
    if(b == 0){
        cout<<"Denominator can't be zero"<<"\n";
        return 0;
    }
    return (a/b);
}

inline int exp(int n, int k){
    if(k == 0){
        return 1;
    }
    int a = exp(n,k/2);
    a = a*a;
    if(k%2){
        a*=n;
    }
    return a;
}

inline int substract(int a, int b){
    return (a-b);
}

int main(){
    int inp;
    do{
        cout<<"ADD(1)"<<endl;
        cout<<"SUBSTRACT(2)"<<endl;
        cout<<"MULTIPLY(3)"<<endl;
        cout<<"DIVIDE(4)"<<endl;
        cout<<"EXPONENT(5)"<<endl;
        cout<<"EXIT(6)"<<endl;
        cin>>inp;
        int a,b;
        if(inp!=6) cin>>a>>b;
        switch(inp){
            case 1:
                cout<<add(a,b)<<"\n";
                break;
            case 2:
                cout<<substract(a,b)<<"\n";
                break;
            case 3:
                cout<<multiply(a,b)<<"\n";
                break;
            case 4:
                cout<<divide(a,b)<<"\n";
                break;
            case 5:
                cout<<exp(a,b)<<"\n";
                break;
            case 6:
                cout<<"THANK YOU FOR INTERACTING"<<"\n";
                break;
            default:
                cout<<"ENTER A VALID OPTION"<<"\n";
        }
    }while(inp!=6);
}