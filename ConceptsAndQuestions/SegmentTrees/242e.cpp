

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
    if(a < 0.0){
        return (ll) a - 1;
    }
    return (ll) a;
}

//code starts here
const ll M = 1e5+100;


vector< vl >  st(4*M + 1, vl(21,0));
vector< vl >  lazy(4*M + 1,vl(21,0));
ll a[M];
ll b[M][21], n, m,l,r,x, t;

void update_range(ll v, ll tl, ll tr, ll l, ll r, ll idx){
    if(lazy[v][idx] != 0){
        st[v][idx] = (tr-tl+1) - st[v][idx];
        if(tl != tr){
            lazy[2*v][idx] = 1 - lazy[2*v][idx];
            lazy[2*v+1][idx] = 1 - lazy[2*v+1][idx];
        }
        lazy[v][idx] = 0;
    }
    if(tl > r || tr < l) return;
    if((tl >= l && tr <= r) || tl == tr){
        st[v][idx] = (tr-tl+1) - st[v][idx]; //change here in rmq to st[v] += change as only change is added to the max or min number
        if(tr != tl){
            lazy[2*v][idx] = 1 - lazy[2*v][idx];
            lazy[2*v+1][idx] = 1 - lazy[2*v+1][idx];
        }
        return;
    }
    ll tm = (tl + tr)/2;
    update_range(2*v,tl,tm,l,r,idx);
    update_range(2*v+1,tm+1,tr,l,r,idx);
    st[v][idx] = st[2*v][idx] + st[2*v+1][idx]; //change here
}


ll query(ll v, ll tl, ll tr, ll l, ll r, ll idx){
    if(tl > r || tr < l) return 0;
    if(lazy[v][idx]){
        st[v][idx] = (tr-tl+1) - st[v][idx];
        if(tl != tr){
            lazy[2*v][idx] = 1 - lazy[2*v][idx];
            lazy[2*v+1][idx] = 1 - lazy[2*v+1][idx];
        }
        lazy[v][idx] = 0;
    }
    if(tl >= l && tr <= r) return st[v][idx];
    ll tm = (tl + tr)/2;
    return query(2*v,tl,tm,l,r,idx) + query(2*v+1,tm+1,tr,l,r,idx); // change here
}

void build(ll v, ll tl, ll tr, ll idx){
    if(tl == tr){
        st[v][idx] = b[tl][idx];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm,idx);
    build(2*v+1,tm+1,tr,idx);
    st[v][idx] = st[2*v][idx] + st[2*v+1][idx]; // change here for min, max, sum query
}



void solve(){
    re n; fo(n) re a[i];
    fo(n){
        forn(j,21){
            b[i][j] = (a[i]&(1<<j))? 1 : 0;
        }
    }
    // fo(n){
    //     forn(j,4) cout<<b[i][j]<<" "; nl;
    // }
    re m;
    fo(21){
        build(1,0,n-1,i);
    }
    forn(k,m){
        re t;
        if(t == 1){
            re l; re r;
            ll ans = 0;
            l--, r--;
            fo(21){
                ll cur = query(1,0,n-1,l,r,i);
                ans += cur*(1<<i);
            }
            pr(ans);
            continue;
        }
        re l; re r; re x;
        l--; r--;
        fo(21){
            if(x&(1<<i)){
                // cout<<i<<"()\n";
                update_range(1,0,n-1,l,r,i);
            }
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


//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
