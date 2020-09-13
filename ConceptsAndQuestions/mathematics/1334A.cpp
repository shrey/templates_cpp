

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

bool solve(ll p[], ll c[], ll n){
    if(p[0]<c[0]) return false;
    for(int i = 1; i<n; i++){
        if(p[i]<p[i-1] || c[i]<c[i-1] || p[i]<c[i]) return false;
        if(c[i]>c[i-1]){
            if(p[i]-p[i-1]<c[i]-c[i-1]) return false;
        }
    }
    return true;
}

int main(){
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll p[n], c[n];
        fo(n){
            cin>>p[i]>>c[i];
        }
        if(solve(p,c,n)){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }

    }
}