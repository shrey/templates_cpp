

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
#define LG 20

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
const ll M = 1e5+100;
ll n,a,b,p[M];
map<ll,ll> f;
map<ll,set<ll> > gr;
map<ll,ll> sz;

void solve(){
    re n; re a; re b;
    fo(n) re p[i];
    fo(n) f[p[i]]++;
    multiset<pair<ll,ll > > m;
    fo(n){
        if(f[a-p[i]]) gr[p[i]].insert(a-p[i]);
        if(f[b-p[i]]) gr[p[i]].insert(b-p[i]);
        if(gr[p[i]].size() == 0){
            NO;
            return;
        }
        sz[p[i]] = gr[p[i]].size();
        m.insert(mp(sz[p[i]],p[i]));
    }
    map<ll,ll> res;
    while(!m.empty()){
        auto cur = *m.begin();
        m.erase(m.begin());
        if(gr[cur.sec].empty()){
            NO;
            return;
        }
        if(gr[cur.sec].size() == 1){
            ll op = *gr[cur.sec].begin();
            if(op == a-cur.sec) res[cur.sec] = 0, res[op] = 0;
            else res[cur.sec] = 1, res[op] = 1;
            m.erase(m.find(mp(sz[op],op)));
            auto it = m.find(mp(a-op,sz[a-op]));
            if(it != m.end()){
                m.erase(it);
                sz[a-op]--;
                gr[a-op].erase(op);
                m.insert(mp(sz[a-op],a-op));
            }
            auto it2 = m.find(mp(b-op,sz[b-op]));
            if(it2 != m.end()){
                m.erase(it2);
                sz[b-op]--;
                gr[b-op].erase(op);
                m.insert(mp(sz[b-op],b-op));
            }
        }else{
            ll op = a - cur.sec;
            res[cur.sec] = 0, res[op] = 0;
            m.erase(m.find(mp(sz[op],op)));
            auto it2 = m.find(mp(b-op,sz[b-op]));
            if(it2 != m.end()){
                m.erase(it2);
                sz[b-op]--;
                gr[b-op].erase(op);
                m.insert(mp(sz[b-op],b-op));
            }
            auto it = m.find(mp(a-op,sz[a-op]));
            if(it != m.end()){
                m.erase(it);
                sz[a-op]--;
                gr[a-op].erase(op);
                m.insert(mp(sz[a-op],a-op));
            }
        }
    }
    YES;
    fo(n) cout<<res[p[i]]<<" "; nl;
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
