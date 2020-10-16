

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
#define imin INT_MIN
#define lmin LLONG_MIN
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define pr(t) cout<<t<<"\n"
#define int long long
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

const ll M = 2e5+10;
vl gr[M];
ll n,k;
umap<ll,ll> dist;
umap<ll,ll> visited;
umap<ll,ll> child;
vl det;

bool compare(pair<ll,ll> &a, pair<ll,ll> &b){
    // cout<<a.sec<<" "<<b.sec<<"rr\n";
    if(a.sec == b.sec){
        return (child[a.ff]>child[b.ff]);
    }
    return(a.sec>b.sec);
}

void dfs(ll cur, ll par){
    visited[cur] = true;
    dist[cur] = dist[par]+1;
    child[cur] = 1;
    for(auto x: gr[cur]){
        if(!visited[x]){
            dfs(x,cur);
            child[cur]+=child[x];
        }
    } det.pb(child[cur]-dist[cur]);

}

ll ans = 0;

void solve(){
    dfs(1,0);
    sort(det.rbegin(),det.rend());
    for(ll i = 0; i<n-k; i++){
        ans+=det[i];
    }
    cout<<ans<<"\n";
}

int32_t main(){
    KOBE;
    cin>>n>>k;
    fo(n-1){
        ll x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    dist[0] = 0;
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
