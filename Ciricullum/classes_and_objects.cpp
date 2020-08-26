

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

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

class Demo{
    int priv1, priv2;
    string s;
    public:
        Demo(int a, int b, string S){
            priv1 = a;
            priv2 = b;
            s = S;
            cout<<"Constructor is Called"<<endl;
        }
        void func1(){
            cout<<"This is the function 1 : ("<<priv1<<")("<<priv2<<")"<<endl;
        }
        void printname();

};

void Demo::printname(){
    cout<<"Name is: "<<s<<endl;
}

int main() {
    int a, b;
    string s;
    cin>>a>>b;
    cin>>s;
    Demo d(a,b,s);
    d.func1();
    d.printname();
}
