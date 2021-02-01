

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


const ll M = 2e5+100;
vl st;
vl lazy;
ll n,q,a[M],b[M];
char ch;



void update_range(ll v, ll tl, ll tr, ll l, ll r, ll change){
    if(lazy[v] != -1){
        st[v] = (tr-tl+1) * lazy[v];
        if(tl != tr){
            lazy[2*v] = lazy[v];
            lazy[2*v+1] = lazy[v];
        }
        lazy[v] = -1;
    }
    if(tl > r || tr < l) return;
    if((tl >= l && tr <= r) || tl == tr){
        st[v] = (tr-tl+1)*change; //change here in rmq to st[v] += change as only change is added to the max or min number
        if(tr != tl){
            lazy[2*v] = change;
            lazy[2*v+1] = change;
        }
        return;
    }
    ll tm = (tl + tr)/2;
    update_range(2*v,tl,tm,l,r,change);
    update_range(2*v+1,tm+1,tr,l,r,change);
    st[v] = st[2*v] + st[2*v+1]; //change here
}

void update(ll v, ll tl, ll tr, ll pos, ll change){
    if(tl == tr){
        st[v] += change; //change here
        return;
    }
    ll tm = (tl + tr)/2;
    if(pos <= tm) update(2*v,tl,tm,pos,change);
    else update(2*v + 1,tm+1,tr,pos,change);
    st[v] = st[2*v] + st[2*v+1]; //change here
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 0;
    if(lazy[v] != -1){
        st[v] = (tr-tl+1)*lazy[v];
        if(tl != tr){
            lazy[2*v] = lazy[v];
            lazy[2*v+1] = lazy[v];
        }
        lazy[v] = -1;
    }
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return query(2*v,tl,tm,l,r) + query(2*v+1,tm+1,tr,l,r); // change here
}

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        st[v] = a[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v] = st[2*v] + st[2*v+1]; // change here for min, max, sum query
}




void solve(){
    st.clear();
    lazy.clear();
    re n; re q;
    fo(n){
        re ch;
        b[i] = ch - '0';
    }
    fo(n){
        re ch;
        a[i] = ch - '0';
    }
    vp qry(q);
    // pr("here");
    fo(q){
        re qry[i].ff; re qry[i].sec;
    }
    st.assign(4*n+1,0);
    lazy.assign(4*n+1,-1);
    build(1,0,n-1);
    for(ll i = q-1; i>=0; i--){
        ll l = qry[i].ff, r = qry[i].sec;
        l--; r--;
        ll op = query(1,0,n-1,l,r);
        if(2 * op == (r-l+1)){
            NO;
            return;
        }
        if(2*op > r-l+1){
             update_range(1,0,n-1,l,r,1);
        }else{
            update_range(1,0,n-1,l,r,0);
        }
    }
    fo(n){
        ll cur = query(1,0,n-1,i,i);
        if(cur != b[i]){
            NO;
            return;
        }
    }
    YES;
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


//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
