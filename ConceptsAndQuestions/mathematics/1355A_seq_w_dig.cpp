

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

ll calcNext(ll a){
    int maxdig = INT_MIN, mindig = INT_MAX;
    ll temp = a;
    while(temp>0){
        int dig = temp%10;
        maxdig = max(dig,maxdig);
        mindig = min(dig,mindig);
        temp/=10;
    }
    return (a+maxdig*mindig);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a1,k;
        cin>>a1>>k;
        ll curr = a1;
        k--;
        while(k--){
            ll temp = calcNext(curr);
            if(temp == curr){
                break;
            }
            curr = temp;
        }
        cout<<curr<<"\n";
    }
}