

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

const ll M = 5e5+100;
ll n, dp[M] = {0};
vl gr[M];
ll idx[M];
vl path;

void dfs(ll cur, ll par){
    path.pb(cur);
    dp[cur] = 1;
    for(auto x: gr[cur]){
        if(x != par){
            dfs(x,cur);
            dp[cur] += dp[x];
        }
    }
}


vl st(4*M + 1,0);
vl lazy(4*M + 1,0);
ll a[M];

void update_range(ll v, ll tl, ll tr, ll l, ll r){
    if(lazy[v] != 0){
        st[v] = (tr-tl+1);
        if(tl != tr){
            lazy[2*v] = 1;
            lazy[2*v+1] = 1;
        }
        lazy[v] = 0;
    }
    if(tl > r || tr < l) return;
    if((tl >= l && tr <= r) || tl == tr){
        st[v] = (tr-tl+1); //change here in rmq to st[v] += change as only change is added to the max or min number
        if(tr != tl){
            lazy[2*v] = 1;
            lazy[2*v+1] = 1;
        }
        return;
    }
    ll tm = (tl + tr)/2;
    update_range(2*v,tl,tm,l,r);
    update_range(2*v+1,tm+1,tr,l,r);
    st[v] = st[2*v] + st[2*v+1]; //change here
}

void update(ll v, ll tl, ll tr, ll pos){
    if(tl == tr){
        st[v] = 0; //change here
        lazy[v] = 0;
        return;
    }
    ll tm = (tl + tr)/2;
    if(pos <= tm) update(2*v,tl,tm,pos);
    else update(2*v + 1,tm+1,tr,pos);
    st[v] = st[2*v] + st[2*v+1]; //change here
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 0;
    if(lazy[v]){
        st[v] = (tr-tl+1);
        if(tl != tr){
            lazy[2*v] = 1;
            lazy[2*v+1] = 1;
        }
        lazy[v] = 0;
    }
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return query(2*v,tl,tm,l,r) + query(2*v+1,tm+1,tr,l,r); // change here
}


void solve(){
    re n;
    fo(n-1){
        ll x,y; re x; re y;
        gr[x].pb(y); gr[y].pb(x);
    }
    dfs(1,0);
    // cout<<path.size()<<"()"<<n<<"\n";
    fo(path.size()) idx[path[i]] = i;
    // for(auto x: path) cout<<idx[x]<<" "; nl;
    ll m; re m;
    while(m--){
        ll t,x; re t; re x;
        if(t == 1){
            update_range(1,0,n-1,idx[x],idx[x]+dp[x]-1);
        }else if(t == 2){
            ll k = query(1,0,n-1,idx[x],idx[x]);
            if(k) update(1,0,n-1,idx[x]);
        }else{
            ll k = query(1,0,n-1,idx[x],idx[x]+dp[x]-1);
            // cout<<x<<"()"<<k<<"\n";
            if(k == dp[x]) pr(1);
            else pr(0);
        }
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

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
