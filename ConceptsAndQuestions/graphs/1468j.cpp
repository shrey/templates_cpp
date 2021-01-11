

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
    return (ll) a;
}



//code starts here

struct edges{
    ll x,y,w;
};

const ll M = 2e5+100;

vector<edges> e;

// edges e[M];

ll n,m,k;

vl gr[M];
bool visited[M] = {false};
vector<int> parent(M); vl rnk(M);

void dfs(ll cur){
    visited[cur] = true;
    for(auto x: gr[cur]){
        if(!visited[x]) dfs(x);
    }
}


void make_set(ll v) {
    parent[v] = v;
    rnk[v] = 0;
}

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        rnk[a] += rnk[b];
    }
}

bool compare(edges &a, edges &b){
    return (a.w < b.w);
}

ll kruskal(){
    for (int i = 0; i <= n; i++)
        make_set(i);
    sort(e.begin(),e.end(),compare);
    ll res = 0;
    for(auto x: e){
        // cout<<x.x<<"()"<<x.y<<"\n";
        if(find_set(x.x) != find_set(x.y)){
            res += max(0ll,x.w - k);
            union_sets(x.x,x.y);
        }
    }
    return res;
}

void solve(){
    e.clear();
    re n; re m; re k;
    for(ll i = 0; i<=n; i++) {
        gr[i].clear();
        visited[i] = false;
        make_set(i);
    }
    fo(m){
        edges cur;
        re cur.x; re cur.y; re cur.w;
        e.pb(cur);
    }
    ll res = 1e15;
    fo(m){
        if(e[i].w <= k){
            gr[e[i].x].pb(e[i].y);
            gr[e[i].y].pb(e[i].x);
        }
        res = min(res,abs(k - e[i].w));
    }
    dfs(1);
    bool flag = true;
    for(ll i = 1; i<=n; i++){
        if(!visited[i]){
            flag = false;
            res = 1e15;
            break;
        }
    }
    if(flag){
        pr(res);
        return;
    }

    ll ans = kruskal();
    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    re t;
    // t = 1;
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
