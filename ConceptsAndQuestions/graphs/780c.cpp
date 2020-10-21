

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
ll n,x,y;
vl gr[M];
ll ncol = imin;
ll col[M] = {0};

void dfs(ll src, ll par){
    ll curcol = 1;
    // cout<<src<<"()"<<par<<"\n";
    for(auto x: gr[src]){
        if(x!=par){
            while(curcol == col[par] || curcol == col[src]) curcol++;
            col[x] = curcol;
            dfs(x,src);
            curcol++;
        }
    }
}

void solve(){
    for(ll i = 1; i<=n; i++){
        ncol = max(ncol,(ll)gr[i].size());
    }
    ncol++;
    col[0] = 0;
    col[1] = 1;
    cout<<ncol<<"\n";
    dfs(1,0);
    for(ll i = 1; i<=n; i++){
        cout<<col[i]<<" ";
    }cout<<"\n";
}

int32_t main(){
    KOBE;
    cin>>n;
    fo(n-1){
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
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
