

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
#define fo2(x,y) for(int i = x; i<y; i++)
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

int x,y,GCD;

void extendedEuclidMethod(int a, int b){
    if(b == 0){
        x = 1;
        y = 0;
        GCD = a;
        return;
    }
    extendedEuclidMethod(b,a%b);
    int cX = y;
    int cY = x-(a/b)*y;
    x = cX;
    y = cY;
}

int main(){
    extendedEuclidMethod(18,30); //18x + 30y = 6
    cout<<x<<" "<<y<<endl;
}