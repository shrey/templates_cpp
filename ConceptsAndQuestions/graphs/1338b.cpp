

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
#include<numeric>

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
#define nl cout<<"\n"
#define re cin >>
#define pll pair<ll,ll>
#define FOR(a,b) for(ll i = a; i<=b; i++)

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

const ll M = 1e5+100;
vl gr[M];
ll n,x,y;
vl deg(M,0);
vl visited(M,0);
bool flag = false;
ll ans;

ll dfs(ll src, ll dist){
    visited[src] = 1;
    if(deg[src] == 1){
        if(dist%2){
            flag = true;
        }
    }
    ll cnt = 0;
    for(auto x: gr[src]){
        if(!visited[x]){
            dfs(x,dist+1);
        }
        if(deg[x] == 1){
            cnt++;
        }
    }
    // cout<<src<<"()"<<cnt<<"\n";
    if(cnt) ans -= (cnt-1);
}

void solve(){
    re n;
    ans = n-1;
    fo(n-1){
        re x; re y;
        gr[x].pb(y);
        gr[y].pb(x);
        deg[x]++;
        deg[y]++;
    }
    for(ll i = 1; i<=n; i++){
        if(!visited[i] && deg[i] == 1){
            dfs(i,0);
            break;
        }
    }
    if(flag) cout<<3<<" ";
    else cout<<1<<" ";
    cout<<ans<<"\n";
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    while(t--) solve();
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
