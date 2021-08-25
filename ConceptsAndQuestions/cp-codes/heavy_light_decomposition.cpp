

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

//code starts here


const int N = 1e5+5;

int n, tim=0;
int a[N], level[N], tin[N], tout[N], rtin[N], nxt[N], subtree[N], parent[LG][N];
vector<int> gr[N];

//Heavy Light Decomposition

void dfs(int u, int par, int lvl)
{
	parent[0][u] = par;
	level[u] = lvl;
	for(auto &it:gr[u])
	{
		if(it==par)
			continue;
		dfs(it, u, lvl+1);
	}
}

void dfs1(int u, int par)
{
	subtree[u] = 1;
	for(auto &it:gr[u])
	{
		if(it==par)
			continue;
		dfs1(it, u);
		subtree[u] += subtree[it];
		if(subtree[it] > subtree[gr[u][0]])
			swap(it, gr[u][0]);
	}
}

void dfs_hld(int u, int par)
{
	tin[u] = ++tim;
	rtin[tim] = u;
	for(auto &v:gr[u])
	{
		if(v==par)
			continue;
		nxt[v] = (v==gr[u][0] ? nxt[u]:v);
		dfs_hld(v, u);
	}
	tout[u] = tim;
}

//LCA

int walk(int u, int h)
{
	for(int i=LG-1;i>=0;i--)
	{
		if((h>>i) & 1)
			u = parent[i][u];
	}
	return u;
}

void precompute()
{
	for(int i=1;i<LG;i++)
		for(int j=1;j<=n;j++)
			if(parent[i-1][j])
				parent[i][j]=parent[i-1][parent[i-1][j]];
}

int LCA(int u, int v)
{
	if(level[u]<level[v])
		swap(u,v);
	int diff=level[u]-level[v];
	for(int i=LG-1;i>=0;i--)
	{
		if((1<<i) & diff)
		{
			u=parent[i][u];
		}
	}
	if(u==v)
		return u;
	for(int i=LG-1;i>=0;i--)
	{
		if(parent[i][u] && parent[i][u]!=parent[i][v])
		{
			u=parent[i][u];
			v=parent[i][v];
		}
	}
	return parent[0][u];
}

int dist(int u, int v)
{
	return level[u] + level[v] - 2 * level[LCA(u, v)];
}

//Segment Tree

int st[4*N], lazy[4*N];

void build(int node, int L, int R)
{
	if(L==R)
	{
		st[node]=a[rtin[L]];
		return;
	}
	int M=(L+R)/2;
	build(node*2, L, M);
	build(node*2+1, M+1, R);
	st[node]=min(st[node*2], st[node*2+1]);
}

void propagate(int node, int L, int R)
{
	if(L!=R)
	{
		lazy[node*2]+=lazy[node];
		lazy[node*2+1]+=lazy[node];
	}
	st[node]+=lazy[node];
	lazy[node]=0;
}

int query(int node, int L, int R, int i, int j)
{
	if(lazy[node])
		propagate(node, L, R);
	if(j<L || i>R)
		return 1e9;
	if(i<=L && R<=j)
		return st[node];
	int M=(L+R)/2;
	int left=query(node*2, L, M, i, j);
	int right=query(node*2 + 1, M+1, R, i, j);
	return min(left, right);
}

void update(int node, int L, int R, int i, int j, int val)
{
	if(lazy[node])
		propagate(node, L, R);
	if(j<L || i>R)
		return;
	if(i<=L && R<=j)
	{
		lazy[node]+=val;
		propagate(node, L, R);
		return;
	}
	int M=(L+R)/2;
	update(node*2, L, M, i, j, val);
	update(node*2 + 1, M+1, R, i, j, val);
	st[node]=min(st[node*2], st[node*2 + 1]);
}

void upd(int l, int r, int val)
{
	update(1, 1, n, l, r, val);
}

int get(int l, int r)
{
	return query(1, 1, n, l, r);
}
//Utility Functions

int query_up(int x, int y) //Assuming Y is an ancestor of X
{
	int res = 0;
	while(nxt[x] != nxt[y])
	{
		res += get(tin[nxt[x]], tin[x]);
		x = parent[0][nxt[x]];
	}
	res += get(tin[y] + 1, tin[x]); //use tin[y] to include Y
	return res;
}

int query_hld(int x, int y)
{
	int lca = LCA(x, y);
	int res = query_up(x, lca) + query_up(y, lca);
	return res;
}

void update_up(int x, int y, int val) //Assuming Y is an ancestor of X
{
	while(nxt[x] != nxt[y])
	{
		upd(tin[nxt[x]], tin[x], val);
		x = parent[0][nxt[x]];
	}
	upd(tin[y] + 1, tin[x], val); //use tin[y] to include Y
}

void update_hld(int x, int y, int val)
{
	int lca = LCA(x, y);
	update_up(x, lca, val);
	update_up(y, lca, val);
}

void hld()
{
	dfs(1, 0, 1);
	dfs1(1, 0);
	dfs_hld(1, 0);
	precompute();
	build(1, 1, n);
}

void solve(){

}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    re t;
    while(t--) solve();
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
// always check for n = 1 condition
// check loop starting and end points :(

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
