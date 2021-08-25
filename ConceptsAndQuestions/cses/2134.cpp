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



const int N = 2e5+5;
const int D = 19;
const int S = (1<<D);

int n, q, v[N];
vector<int> gr[N];

int sz[N], p[N][D], dep[N];
int st[S], id[N], tp[N];

void update(int idx, int val, int i=1, int l=1, int r=n) {
	if(l == r) { st[i] = val; return; }
	int m = (l+r)/2;
	if(idx <= m) update(idx, val, i*2, l, m);
	else update(idx,  val, i*2+1, m+1, r);
	st[i] = max(st[i*2], st[i*2+1]);
}
int query(int lo, int hi, int i=1, int l=1, int r=n) {
	if(lo > r || hi < l) return 0;
	if(lo <= l && r <= hi) return st[i];
	int m = (l+r)/2;
	return max(query(lo, hi, i*2, l, m),
			query(lo, hi, i*2+1, m+1, r));
}

int dfs_sz(int cur, int par) {
	sz[cur] = 1;
	for(int chi : gr[cur]) {
		if(chi == par) continue;
		dep[chi] = dep[cur] + 1;
		p[chi][0] = cur;
		sz[cur] += dfs_sz(chi, cur);
	}
	return sz[cur];
}
void init_lca() {
	for(int d=1; d<18; d++)
	for(int i=1; i<=n; i++)
		p[i][d] = p[p[i][d-1]][d-1];
}
int ct = 1;
void dfs_hld(int cur, int par, int top) {
	id[cur] = ct++;
	tp[cur] = top;
	update(id[cur], v[cur]);
	int h_chi = -1, h_sz = -1;
	for(int chi : gr[cur]) {
		if(chi == par) continue;
		if(sz[chi] > h_sz) {
			h_sz = sz[chi];
			h_chi = chi;
		}
	}
	if(h_chi == -1) return;
	dfs_hld(h_chi, cur, top);
	for(int chi : gr[cur]) {
		if(chi == par || chi == h_chi) continue;
		dfs_hld(chi, cur, chi);
	}
}
int lca(int a, int b) {
	if(dep[a] < dep[b]) swap(a, b);
	for(int d=D-1; d>=0; d--) {
		if(dep[a] - (1<<d) >= dep[b]) {
			a = p[a][d];
		}
	}
	for(int d=D-1; d>=0; d--) {
		if(p[a][d] != p[b][d]) {
			a = p[a][d];
			b = p[b][d];
		}
	}
	if(a != b) {
		a = p[a][0];
		b = p[b][0];
	}
	return a;
}
int path(int chi, int par) {
	int ret = 0;
	while(chi != par) {
		if(tp[chi] == chi) {
			ret = max(ret, v[chi]);
			chi = p[chi][0];
		} else if(dep[tp[chi]] > dep[par]) {
			ret = max(ret, query(id[tp[chi]], id[chi]));
			chi = p[tp[chi]][0];
		} else {
			ret = max(ret, query(id[par]+1, id[chi]));
			break;
		}
	}
	return ret;
}

void solve(){
    KOBE;
    re n; re q;
	for(int i=1; i<=n; i++) re v[i];
	for(int i=2; i<=n; i++) {
		int a, b;
		re a; re b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs_sz(1, 1);
	init_lca();
	memset(st, 0, sizeof st);
	dfs_hld(1, 1, 1);
	while(q--) {
		int t;
        re t;
		if(t == 1) {
			int s, x;
            re s; re x;
			v[s] = x;
			update(id[s], v[s]);
		} else {
			int a, b;
            re a; re b;
			int c = lca(a, b);
			int res = max(max(path(a,c), path(b,c)), v[c]);
            cout<<res<<" ";
		}
	}
    nl;
}

int32_t main() {
    KOBE;
    ll t;
    t = 1;
    re t;
    while(t--) solve();
}