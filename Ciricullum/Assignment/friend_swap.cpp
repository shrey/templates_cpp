
#include<iostream>
using namespace std;
class A
{
    int x;
    int y;
    public:
    friend void swap(A&); void setData(int a, int b){
    x = a; y = b;
    }
};
void swap(A& x) {
    cout<<"\nBefore swapping : First Number = "<<x.x<<" , Second Number = "<<x.y<<"\n"; int A::* px = &A :: x;
    int A::* py = &A :: y;
    A *pm = &x;
     int temp = x.*px;
    x.*px = pm->*py;
    pm->*py = temp;
    cout<<"\nAfter swapping : First Number = "<<x.x<<" , Second Number = "<<x.y<<"\n";
}
int main () {
    A a1;
    int a,b;
    cout<<"Enter First number \t";
    cin>>a;
    cout<<"Enter Second number \t";
    cin>>b;
    void (A::*pf)(int , int) = &A :: setData;
    (a1.*pf)(a,b); //Pointer to member function swap(a1);
    swap(a1);
    return 0;
}