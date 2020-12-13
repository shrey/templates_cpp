

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

const ll M = 1e5+100;
vl st(4*M+1,0);
ll a[M],n,m;
vl store[M];
struct node{
    ll l, r, idx;
};

node queries[M];

bool compare(node &a, node &b){
    if(a.r != b.r){
        return a.r < b.r;
    }
    return a.l < b.l;
}


void update(ll v, ll tl, ll tr, ll pos, ll change){
    // cout<<tl<<" "<<tr<<"\n";
    if(tl == tr){
        st[v] += change;
        return;
    }
    ll tm = (tl + tr)/2;
    if(pos <= tm) update(2*v,tl,tm,pos,change);
    else update(2*v + 1,tm+1,tr,pos,change);
    st[v] = st[2*v] + st[2*v+1];
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 0;
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return query(2*v,tl,tm,l,r) + query(2*v+1,tm+1,tr,l,r);
}

void solve(){
    re n; re m;
    fo(n){
        re a[i];
        if(a[i] > 1e5) a[i] = 0;
    }
    fo(m){
        re queries[i].l; re queries[i].r;
        queries[i].l--; queries[i].r--;
        queries[i].idx = i;
    }
    ll j = 0;
    ll ans[m+1];
    sort(queries,queries+m,compare);
    // pr("here");
    for(ll i = 0; i<n; i++){
        ll x = a[i];
        if(x){
            ll sz = store[x].size();
            if(sz > x){
                update(1,0,n-1,store[x][sz-x-1],1);
            }
            if(sz >= x) update(1,0,n-1,store[x][sz-x],-2);
            store[x].pb(i);
            sz++;
            if(store[x].size()>=x){
                update(1,0,n-1,store[x][sz-x],1);
            }
        }
        while(j<m && queries[j].r == i){
            ans[queries[j].idx] = query(1,0,n-1,queries[j].l,queries[j].r);
            j++;
        }
    }
    fo(m) cout<<ans[i]<<"\n";
}

int32_t main(){
    KOBE;
    ll t;
    // re t;
    t = 1;
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
