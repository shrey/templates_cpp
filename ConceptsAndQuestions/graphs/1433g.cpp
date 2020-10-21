

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

const ll M = 1010;
vector<pair<ll,ll> > g[M];
vector<ll> d[M];
vector<pair<ll,ll> > r;
ll n,m,k,x,y,w;


void dijkstra(ll s, vector<ll> &d){
    d = vl(n+1,imax);
    d[s] = 0;
    set<pair<ll,ll> > st;
    st.insert(mp(d[s],s));
    while(!st.empty()){
        ll cur = st.begin()->second;
        st.erase(st.begin());
        for(auto nbr:g[cur]){
            ll to = nbr.first;
            ll wt = nbr.second;
            if(d[to]>d[cur]+wt){
                auto it = st.find(mp(d[to],to));
                if(it!=st.end()) st.erase(it);
                d[to] = d[cur]+wt;
                st.insert(mp(d[to],to));
            }
        }
    }
}

int32_t main(){
    KOBE;
    cin>>n>>m>>k;
    fo(m){
        cin>>x>>y>>w;
        g[x].pb(mp(y,w));
        g[y].pb(mp(x,w));
    }
    fo(k){
        cin>>x>>y;
        r.pb(mp(x,y));
    }
    for(ll i = 1; i<=n; i++){
        dijkstra(i,d[i]);
    }
    ll ans = imax;
    for(ll i = 1; i<=n; i++){
        for(auto c: g[i]){
            ll j = c.first;
            ll cur = 0;
            for(auto rd: r){
                ll a = rd.ff, b = rd.sec;
                cur+=(min(d[a][b],min(d[a][i]+d[b][j],d[a][j]+d[b][i])));
            }
            ans = min(ans,cur);
        }
    }
    pr(ans);
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
