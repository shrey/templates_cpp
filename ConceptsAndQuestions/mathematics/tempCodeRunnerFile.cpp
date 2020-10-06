

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

ll n;
const ll M = 2e5+100;
ll arr[M];

void solve(){
    map<ll,bool> rec;
    vl gv,tk;
    for(ll i = 1; i<=n; i++){
        rec[arr[i]] = true;
    }
    fo(n){
        if(arr[i+1] == 0){
            gv.pb(i+1);
        }
        if(!rec[i+1]){
            tk.pb(i+1);
        }
    }
    if(gv.size() == 1){
        arr[gv[0]] = tk[0];
        return;
    }
    sort(gv.begin(),gv.end());
    sort(tk.rbegin(),tk.rend());
    // fo(gv.size()) cout<<gv[i]<<" ";cout<<"\n";
    // fo(tk.size()) cout<<tk[i]<<" ";cout<<"\n";
    for(ll i = 0; i<gv.size(); i++){
        if(gv[i] == tk[i]){
            swap(tk[i],tk[(i+1)%tk.size()]);
        }
        arr[gv[i]] = tk[i];
    }

}

int32_t main(){
    KOBE;
    cin>>n;
    fo(n) cin>>arr[i+1];
    solve();
    fo(n) cout<<arr[i+1]<<" ";cout<<"\n";
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
