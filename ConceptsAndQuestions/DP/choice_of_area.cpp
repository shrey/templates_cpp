

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


#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

class area{
    public:
        int a, b;
        area(int A,int B){
            a = A;
            b = B;
        }
};

int maxNo(int a, int b, int c){
    return max(a,max(b,c));
}

int compute(int A, int B, area x, area y, area z, int curr){
    if(A <=0 || B<=0){
        return 0;
    }
    if(curr == 0){
        return 1 +maxNo(compute(A+x.a,B+x.b,x,y,z,1), compute(A+y.a, B+y.b,x,y,z,2), compute(A+z.a, B+z.b,x,y,z,3));
    }
    else if(curr == 1){
        return 1 + max(compute(A+y.a,B+y.b,x,y,z,2),compute(A+z.a,B+z.b,x,y,z,3));
    }
    else if(curr == 2){
        return 1 + max(compute(A+x.a,B+x.b,x,y,z,1),compute(A+z.a,B+z.b,x,y,z,3));
    }
    else{
        return 1 + max(compute(A+y.a,B+y.b,x,y,z,2),compute(A+x.a,B+x.b,x,y,z,1));
    }

}

int main(){
    int A,B;
    A = 20;
    B = 8;
    area x(3,2), y(-5,-10), z(-20,5);
    cout<<compute(A,B,x,y,z,0)<<endl;

}