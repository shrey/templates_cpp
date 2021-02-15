

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
#include<array>


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
#define all(x) x.begin(),x.end()

// ll dx[] = {1,0,-1,0};
// ll dy[] = {0,1,0,-1};

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
    if(a < 0.0){
        return (ll) a - 1;
    }
    return (ll) a;
}

//code starts here

const ll M = 2e5+100;
ll n,m,x,y,w;
vp gr[M];
vl dist(M);
vl cnt(M);
vl mx(M);
vl mn(M);

void dijkstra(ll src){
    set<pll> s;
    fo(M) dist[i] = lmax;
    s.insert(mp(0,src));
    dist[src] = 0;
    cnt[src] = 1;
    while(!s.empty()){
        pll cur = *s.begin();
        s.erase(s.begin());
        ll node = cur.sec;
        ll d = cur.ff;
        for(auto x: gr[node]){
            if(x.sec + d == dist[x.ff]){
                cnt[x.ff]+=cnt[node];
                cnt[x.ff] %= mod;
                mx[x.ff] = max(mx[node]+1,mx[x.ff]);
                mn[x.ff] = min(mn[node]+1,mn[x.ff]);
            }
            if(x.sec + d < dist[x.ff]){
                auto f = s.find(mp(dist[x.ff],x.ff));
                if(f!=s.end()){
                    s.erase(f);
                }
                dist[x.ff] = x.sec + d;
                s.insert(mp(dist[x.ff],x.ff));
                cnt[x.ff] = cnt[node];
                cnt[x.ff] %= mod;
                mx[x.ff] = mx[node] + 1;
                mn[x.ff] = mn[node] + 1;
            }
        }
    }
}


void solve(){
    re n; re m;
    fo(m){
        re x; re y; re w;
        gr[x].pb(mp(y,w));
    }
    dijkstra(1);
    cout<<dist[n]<<" "<<cnt[n]<<" "<<mn[n]<<" "<<mx[n]<<"\n";
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    // re t;
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
// try to find repeating pattern in matrices
