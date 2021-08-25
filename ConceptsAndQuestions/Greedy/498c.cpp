

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
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define vs vector<string>
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
#define INF 1e18
#define NIL 0

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



class BipGraph
{
	int m, n;
	list<int> *adj;
	int *pairU, *pairV, *dist;

public:
	BipGraph(int m, int n);
	void addEdge(int u, int v);
	bool bfs();
	bool dfs(int u);

	ll hopcroftKarp();
};

ll BipGraph::hopcroftKarp()
{
	pairU = new int[m+1];

	pairV = new int[n+1];
	dist = new int[m+1];

	for (int u=0; u<=m; u++)
		pairU[u] = NIL;
	for (int v=0; v<=n; v++)
		pairV[v] = NIL;

	int result = 0;

	while (bfs())
	{
		for (int u=1; u<=m; u++)

			if (pairU[u]==NIL && dfs(u))
				result++;
	}
    return result;
}

bool BipGraph::bfs()
{
	queue<int> Q;

	for (int u=1; u<=m; u++)
	{
		if (pairU[u]==NIL)
		{
			dist[u] = 0;
			Q.push(u);
		}
		else dist[u] = INF;
	}

	dist[NIL] = INF;

	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();

		if (dist[u] < dist[NIL])
		{
			list<int>::iterator i;
			for (i=adj[u].begin(); i!=adj[u].end(); ++i)
			{
				int v = *i;

				if (dist[pairV[v]] == INF)
				{
					dist[pairV[v]] = dist[u] + 1;
					Q.push(pairV[v]);
				}
			}
		}
	}

	return (dist[NIL] != INF);
}

bool BipGraph::dfs(int u)
{
	if (u != NIL)
	{
		list<int>::iterator i;
		for (i=adj[u].begin(); i!=adj[u].end(); ++i)
		{
			int v = *i;

			if (dist[pairV[v]] == dist[u]+1)
			{
				if (dfs(pairV[v]) == true)
				{
					pairV[v] = u;
					pairU[u] = v;
					return true;
				}
			}
		}

		dist[u] = INF;
		return false;
	}
	return true;
}

// Constructor
BipGraph::BipGraph(int m, int n)
{
	this->m = m;
	this->n = n;
	adj = new list<int>[m+1];
}

void BipGraph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

ll n,m;
const ll M = 110;
const ll mx = 1e6+100;
vl gr[M];
ll a[M];
vector<vl> f;
ll val1[mx], val2[mx];
vector<ll> nw[M];

vl comp(ll num){
    vl f;
    for(ll i = 2; i*i <= num; i++){
        if(num % i == 0){
            while(num && num%i == 0) f.pb(i),num/=i;
        }
    }
    if(num > 1) f.pb(num);
    return f;
}

void solve(){
    re n; re m;
    fo(n) re a[i];
    f.resize(n);
    fo(n) f[i] = comp(a[i]);
    // fo(n){
    //     for(auto x: f[i]) cout<<x<<" "; nl;
    // }
    ll c1 = 1, c2 = 1;
    BipGraph g(mx,mx);
    fo(n){
        for(auto x: f[i]){
            if(i % 2 == 0){
                nw[i].pb(c1);
                val1[c1] = x;
                c1++;
            }
            else{
                nw[i].pb(c2);
                val2[c2] = x;
                c2++;
            }
        }
    }
    forn(k,m){
        ll x,y; re x; re y;
        x--; y--;
        if(x % 2) swap(x,y);
        for(ll i = 0; i<nw[x].size(); i++){
            for(ll j = 0; j<nw[y].size(); j++){
                if(val1[nw[x][i]] == val2[nw[y][j]]){
                    ll u = nw[x][i], v = nw[y][j];
                    // cout<<u<<"()"<<v<<"\n";
                    g.addEdge(nw[x][i],nw[y][j]);
                }
            }
        }
    }
    ll ans = g.hopcroftKarp();
    pr(ans);
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
