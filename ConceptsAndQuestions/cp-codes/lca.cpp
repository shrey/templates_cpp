

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
vl euler,first(M),st(4*M+1),height(M);
vb visited(M,false);
vl gr[M];
ll inf = 1e15;
ll n,m,x;

void dfs(ll cur, ll ht){
    // cout<<"()"<<cur<<"\n";
    visited[cur] = true;
    height[cur] = ht;
    first[cur] = euler.size();
    euler.pb(cur);
    for(auto x: gr[cur]){
        if(!visited[x]){
            dfs(x,ht+1);
            euler.pb(cur);
        }
    }
}

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        st[v] = euler[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    ll l = st[2*v], r = st[2*v+1];
    st[v] = height[l]<height[r]? l : r;
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return -1;
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    ll left = query(2*v,tl,tm,l,r);
    ll right = query(2*v+1,tm+1,tr,l,r);
    if(left == -1) return right;
    if(right == -1) return left;
    return height[left]<height[right]? left : right;
}

void solve(){
    fo(M) gr[i].clear();
    fo(M) visited[i] = false;
    euler.clear();
    re n;
    // cout<<"()"<<n;nl;
    for(ll i = 1; i<=n; i++){
        re m;
        for(ll j = 0; j<m; j++){
            re x;
            gr[i].pb(x);
        }
    }
    dfs(1,0);
    // pr("here");
    // fo(euler.size()) cout<<euler[i]<<" ";nl;
    ll sz = euler.size();
    build(1,0,sz-1);
    // pr("here");
    re m;
    // pr("now");
    fo(m){
        ll l,r;
        re l; re r;
        l = first[l]; r = first[r];
        if(l > r) swap(l,r);
        pr(query(1,0,sz-1,l,r));
    }
    // for(ll i = 1; i<=n; i++){
    //     cout<<i<<" = "<<height[i]<<"\n";
    // }
}

int32_t main(){
    KOBE;
    ll t;
    re t;
    // t = 1;
    fo(t){
        cout<<"Case "<<i+1<<":\n";
        solve();
    }
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
/*

1
7
3 2 3 4
0
3 5 6 7
0
0
0
0
2
4 2
7 5
*/