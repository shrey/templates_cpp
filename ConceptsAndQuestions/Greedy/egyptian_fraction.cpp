
// Every positive fraction can be represented as sum of unique unit fractions.
// A fraction is unit fraction if numerator is 1 and denominator is a positive integer,
// for example 1/3 is a unit fraction. Such a representation is called Egyptian Fraction as it was used
// by ancient Egyptians.



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


void printEgyptianFraction(int n, int d){
    if(n == 0 || d == 0){
        return;
    }
    if(n%d == 0){
        cout<<n/d;
        return;
    }
    else if(d%n == 0){
        cout<<"1/"<<d/n;
        return;
    }
    else if(n>d){
        cout<<n/d<<" + ";
        printEgyptianFraction(n%d,d);
        return;
    }
    int k = d/n+1;
    cout<<"1/"<<k<<" + ";
    printEgyptianFraction(n*k-d,d*k);

}

int main(){
    int n,d;
    cin>>n>>d;
    printEgyptianFraction(n,d);
    cout<<endl;
}