

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
vp gr[M];
ll n,m,x,y,w;
vl dist(M,lmax);
ll ans;
vp edges;


void dijkstra(ll src){
    set<pll> s;
    fo(M) dist[i] = lmax;
    s.insert(mp(0,src));
    for(auto e: edges){
        s.insert(mp(e.sec,e.ff));
    }
    dist[src] = 0;
    while(!s.empty()){
        pll cur = *s.begin();
        s.erase(s.begin());
        ll node = cur.sec;
        ll d = cur.ff;
        if(dist[node] > d){
            // cout<<node<<" = "<<d<<","<<dist[node]<<"()\n";
            dist[node] = d;
            ans--;
        }
        for(auto x: gr[node]){
            if(x.sec + d < dist[x.ff]){
                auto f = s.find(mp(dist[x.ff],x.ff));
                if(f!=s.end()){
                    s.erase(f);
                }
                dist[x.ff] = x.sec + d;
                s.insert(mp(dist[x.ff],x.ff));
            }
        }
    }
}

void solve(){
    ll n,m,k;
    re n; re m; re k;
    ans = k;
    fo(m){
        re x; re y; re w;
        gr[x].pb(mp(y,w));
        gr[y].pb(mp(x,w));
    }
    fo(k){
        re y; re w;
        edges.pb(mp(y,w));
        // gr[1].pb(mp(y,w));
        // gr[y].pb(mp(1,w));
    }
    dijkstra(1);
    pr(ans);
}

int32_t main(){
    // KOBE;
    ll t;
    // re t;
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
