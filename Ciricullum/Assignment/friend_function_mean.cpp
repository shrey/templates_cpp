#include <iostream>

using namespace std;

class B;

class A{
    float x;
    friend float mean(A&, B&);
    public:
        A(float val){
            x = val;
        }
};

class B{
    float x;
    friend float mean(A&,B&);
    public:
        B(float val){
            x = val;
        }
};

float mean(A &a, B &b){
    return (a.x+b.x)/2;
}

int main(){
    float x,y;
    cout<<"Enter the 2 numbers: ";cin>>x>>y;
    A a(x);
    B b(y);
    cout<<"The mean of the 2 numbers is: "<<mean(a,b)<<"\n";
}
