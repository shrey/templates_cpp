

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


#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
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

ll arr[99999] = {0};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin>>n;
    ll x[n], h[n];
    fo(n){
        cin>>x[i]>>h[i];
    }
    ll ans = 0;
    if(n>=1) ans = 1;
    if(n>=2) ans = 2;
    ll curr = x[0];
    for(ll i = 1; i<n-1; i++){
        if((x[i]-h[i])>(curr)){
            ans++;
            curr = x[i];
        }
        else if(x[i]+h[i]<x[i+1]){
            ans++;
            curr = x[i]+h[i];
        }
    }
    cout<<ans<<"\n";
}
