

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
#include<bitset>
#include<cstring>

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
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
#define imin INT_MIN
#define lmin LLONG_MIN
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define vb vector<bool>
#define pr(t) cout<<t<<"\n"
#define int long long
#define ql queue<ll>
#define qp queue<pair<ll,ll> >
#define endl "\n"

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


//code starts here


const ll M = 3e5;
vl gr[M];
ll a[M];

ll ans = imin;

void dfs(ll src){
    cout<<src<<"()"<<a[src]<<"\n";
    if(gr[src].size() == 0){
        ans = max(ans,a[src]);
        return;
    }
    ll sum = 0;
    for(auto x: gr[src]){
        sum+=a[x];
    }
    sum+=a[src];
    ll avg = sum/gr[src].size();
    for(auto x: gr[src]){
        if(a[x]<avg){
            ll d = min((avg - a[x]),a[src]);
            a[src]-=d;
            a[x]+=d;
        }
    }

    for(auto x: gr[src]){
        dfs(x);
    }
}

void solve(){
    ll n;
    cin>>n;
    for(ll i = 2; i<=n; i++){
        ll x;
        cin>>x;
        gr[x].pb(i);
    }
    for(ll i = 1; i<=n; i++){
        cin>>a[i];
    }
    // cout<<"HERE";
    dfs(1);
    pr(ans);
}

int32_t main(){
    KOBE;
    solve();
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
