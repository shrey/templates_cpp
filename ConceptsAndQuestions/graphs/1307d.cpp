

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

const ll M = 2e5+100;
ll n,m,k,a[M],x,y;
vl gr[M];

vl dist(ll src){
    bool visited[M] = {false};
    vl dist(n+1,0);
    queue<ll> q;
    visited[src] = true;
    q.push(src);
    while(!q.empty()){
        ll cur = q.front(); q.pop();
        for(auto x: gr[cur]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                dist[x] = dist[cur] + 1;
            }
        }
    }
    return dist;
}

void solve(){
    re n; re m; re k;
    fo(k) re a[i];
    fo(m){
        re x; re y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    vl d1 = dist(1);
    vl dn = dist(n);
    vector<pair<pll,ll> > op;
    // pr(d1[1]);
    fo(k){
        op.pb(mp(mp(d1[a[i]],dn[a[i]]),a[i]));
    }
    sort(op.begin(),op.end());
    // for(auto p: op){
    //     cout<<p.ff.ff<<" , "<<p.ff.sec<<" , "<<p.sec<<"\n";
    // }
    ll mx[op.size()];
    mx[k-1] = op[k-1].ff.sec;
    for(ll i = k-2; i>=0; i--){
        mx[i] = max(mx[i+1],op[i].ff.sec);
    }
    ll res = 0;
    for(ll i = 0; i<k-1; i++){
        ll y1 = op[i].ff.sec;
        ll y2 = mx[i+1];
        // cout<<op[i].sec<<" , "<< min(y1,y2) + 1<<"\n";
        res = max(res,op[i].ff.ff + min(y1,y2) + 1);
    }
    // pr(d1[n]);
    // pr(res);
    res = min(res,d1[n]);
    pr(res);
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
