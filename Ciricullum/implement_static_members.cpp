#include <iostream>
using namespace std;

class demo{
    public:
        static int var;// the declaration
        demo(){}
};

int demo::var = 2; //the definition of static member
int main(){
    demo d1,d2;
    cout<<d1.var<<" "<<d2.var<<endl;
    d1.var+=10;
    cout<<d1.var<<" "<<d2.var<<endl;
}