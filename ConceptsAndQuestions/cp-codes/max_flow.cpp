

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
#include<deque>
#include <cstdlib>
#include <cstdio>
#include<stdlib.h>
#include <cerrno>
#include <ctime>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <random>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>


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
#define bct(x) __builtin_popcountll(x)
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
#define vi vector<ll>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define vs vector<string>
#define vb vector<bool>
#define pr(t) cout<<t<<"\n"
#define ll long long
#define ql queue<ll>
#define qp queue<pair<ll,ll> >
#define endl "\n"
#define nl cout<<"\n"
#define re cin >>
#define pll pair<ll,ll>
#define FOR(a,b) for(ll i = a; i<=b; i++)
#define all(x) x.begin(),x.end()
#define LG 20
#define INF 1e18

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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

ll pw(ll n, ll k){
    if(k == 0) return 1;
    ll t = pw(n,k/2);
    ll ans = (t*t)%mod;
    if(k % 2) return (ans*n)%mod;
    else return ans;
}

//code starts here

int n, m;
ll adj[501][501] = {0}, oadj[501][501];

ll flow[501] = {0};
bool V[501] = {false};
int pa[501] = {0};
bool ed[501][501];

bool reachable() {
	memset(V, false, sizeof(V));
	queue<int> Q; Q.push(1); V[1]=1;
	while(!Q.empty()) {
		int i=Q.front(); Q.pop();
		for(ll j = 1; j<=n; j++) if (adj[i][j] && !V[j])
			V[j]=1, pa[j]=i, Q.push(j);
	}
	return V[n];
}

void solve() {
	cin >> n >> m;
    vp op;
	fo(m) {
		ll a,b,c; cin >> a >> b;
        c = 1;
        op.pb(mp(a,b));
		adj[a][b] += c;
        adj[b][a] += c;
        ed[a][b] = true;
        ed[b][a] = true;
	}
	int v, u;
	ll maxflow = 0;
	while(reachable()) {
		ll flow = 1e18;
		for (v=n; v!=1; v=pa[v]) {
			u = pa[v];
			flow = min(flow, adj[u][v]);
		}
		maxflow += flow;
		for (v=n; v!=1; v=pa[v]) {
			u = pa[v];
			adj[u][v] -= flow;
			adj[v][u] += flow;
		}
	}
    reachable();
    vp res;
    for(ll i = 1; i<=n; i++){
        for(ll j = 1; j<=n; j++){
            if(V[i]&& !V[j] && ed[i][j]){
                res.pb(mp(i,j));
            }
        }
    }
    pr(res.size());
    for(auto e: res){
        cout<<e.ff<<" "<<e.sec<<"\n";
    }
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
// always check for n = 1 condition
// check loop starting and end points :(
//when dividing with mod, use mod inverse

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
