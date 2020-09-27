

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

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define ss second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define imax INT_MAX
#define lmax LLONG_MAX
#define vi vector<int>
#define vl vector<ll>
#define pr(t) cout<<t<<"\n"
#define int long long
ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}


ll is_1(ll n, ll curr){
    if(n&curr) return 1;
    return 0;
}

ll pow_of_2(ll n){
    ll i = 0;
    ll curr = 1;
    while(curr<=n){
        i++;
        curr*=2;
    }
    i--;
    return i;
}

int32_t main(){
    KOBE;
    ll l,r;
    cin>>l>>r;
    ll curr = 1;
    ll ans = 0;
    ll i = 0;
    ll diff = r-l;
    while(curr <= diff){
        ans+=curr;
        curr*=2;
        i++;
    }
    while(curr<=r){
        if(is_1(l,curr) != is_1(r,curr)){
            ans+=curr;
        }
        curr*=2;
    }
    cout<<ans<<"\n";

}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
// left shift operators take extra time
