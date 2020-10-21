

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
#define fo(n) for(ll i = 1; i<=n; i++)
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

const ll M = 2e5;
ll n,m,x,y;
ll pers[M];
ll happ[M];
vl gr[M];
ll pp[M] = {0};
ll g[M] = {0};
umap<ll,bool> visited;
bool possible = true;

void dfs(ll src){
    visited[src] = true;
    pp[src] += pers[src];
    ll sum_g = 0;
    for(auto x: gr[src]){
        if(!visited[x]){
            dfs(x);
            sum_g+=(g[x]);
            pp[src]+=pp[x];
        }
    }

    g[src] = (happ[src]+pp[src])/2;
    if(g[src]<sum_g){
        // cout<<src<<"()"<<sum_g<<"\n";
        possible = false;
        return;
    }
}

bool solve(){
    dfs(1);
    if(!possible) return false;
    fo(n){
        if((happ[i]+pp[i])%2) return false;
        if(abs(happ[i])>abs(pp[i])) return false;
        if(g[i]<0 || g[i]>pp[i]) return false;
    }
    return true;
}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        fo(n) cin>>pers[i];
        fo(n) cin>>happ[i];
        fo(n-1){
            cin>>x>>y;
            gr[x].pb(y);
            gr[y].pb(x);
        }
        if(solve()) YES;
        else NO;
        fo(n+1){
            gr[i].clear();
            pp[i] = 0;
            g[i] = 0;
        }
        visited.clear();
        possible = true;
    }

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
