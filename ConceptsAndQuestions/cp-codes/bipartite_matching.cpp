// C++ implementation of Hopcroft Karp algorithm for
// maximum matching


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
#define NIL 0
#define INF 1e18

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

	vl hopcroftKarp();
};

vl BipGraph::hopcroftKarp()
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
    vl res(n);
    fo(n) res[i] = pairU[i+1];
	return res;
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


void solve(){
    ll n; re n;
    ll a[n];
    BipGraph g(n+1,n+1);
    fo(n) re a[i];
    for(ll i = 0; i<n; i++){
        for(ll j = 0; j<n; j++){
            if(a[j]%(i+1) == 0){
                g.addEdge(i+1,j+1);
            }
        }
    }
    vl res = g.hopcroftKarp();
    fo(n){
        ll cur = a[res[i]-1]/(i+1);
        cout<<cur<<" ";
    }
    nl;
}

// Driver Program
int32_t main()
{
    KOBE;
	ll t; re t;
    while(t--) solve();
}
