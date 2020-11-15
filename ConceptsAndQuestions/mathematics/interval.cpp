

//Shrey Dubey

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
#include<climits>

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define sec second
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
#define vp vector<pair<ll,ll> >
#define pr(t) cout<<t<<"\n"
#define int long long
ll mod = 1e9 + 7;

ll cl(ld a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll flr(ld a){
    return (ll) a;
}


void solve(ll arr[], ll exit[], ll n){
    ll s = 0, e = 1;
    sort(arr,arr+n);
    sort(exit,exit+n);
    fo(n) cout<<arr[i]<<" ";cout<<"\n";
    fo(n) cout<<exit[i]<<" ";cout<<"\n";
    ll currNum = 1;
    ll ans = 1;
    ll tme = arr[0];
    while(s<n && e<n){
        cout<<s<<" "<<e<<"\n";
        if(arr[e]<=exit[s]){
            currNum++;
            if(currNum>ans){
                ans = currNum;
                tme = arr[e];
            }
            e++;
        }else{
            s++;
            currNum--;
        }
    }
    cout<<ans<<" "<<tme<<"\n";
}

int32_t main(){
    KOBE;
    ll arr[] = {1, 2, 10, 5, 5};
    ll exit[] = {4, 5, 12, 9, 12};
    ll n = sizeof(arr)/sizeof(ll);
    solve(arr,exit,n);

}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs


//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search


