

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

const ll M = 2e5+100;
ll n,k;
vector<pair<pll,ll> > pr[M];
ll a[M] = {0};
ll nw[M] = {0};


vl st(4*M + 1);
vl lazy(4*M + 1,0);

void update_range(ll v, ll tl, ll tr, ll l, ll r, ll change){
    if(lazy[v] != 0){
        st[v] += lazy[v];
        if(tl != tr){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if(tl > r || tr < l) return;
    if((tl >= l && tr <= r) || tl == tr){
        st[v] += change; //change here in rmq to st[v] += change as only change is added to the max or min number
        if(tr != tl){
            lazy[2*v] += change;
            lazy[2*v+1] += change;
        }
        return;
    }
    ll tm = (tl + tr)/2;
    update_range(2*v,tl,tm,l,r,change);
    update_range(2*v+1,tm+1,tr,l,r,change);
    st[v] = max(st[2*v], st[2*v+1]); //change here
}

// void update(ll v, ll tl, ll tr, ll pos, ll change){
//     if(tl == tr){
//         st[v] += change; //change here
//         return;
//     }
//     ll tm = (tl + tr)/2;
//     if(pos <= tm) update(2*v,tl,tm,pos,change);
//     else update(2*v + 1,tm+1,tr,pos,change);
//     st[v] = st[2*v] + st[2*v+1]; //change here
// }

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return -1e18;
    if(lazy[v] != 0){
        st[v] += lazy[v];
        if(tl != tr){
            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return max(query(2*v,tl,tm,l,r) , query(2*v+1,tm+1,tr,l,r)); // change here
}

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        st[v] = a[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v] = max(st[2*v] , st[2*v+1]); // change here for min, max, sum query
}


void solve(){
    re n; re k;
    fo(M) a[i] = -1*k;
    a[0] = 0;
    ll mx = 0;
    fo(n){
        ll l,r,p;
        re l; re r; re p;
        pr[l].pb(mp(mp(r,p),i+1));
        a[r] += p;
        mx = max(r,mx);
    }
    for(ll i = 1; i<=mx; i++){
        a[i] += a[i-1];
    }
    // if(k == 23274806583) for(ll i = 1; i<=mx; i++) cout<<a[i]<<" "; nl;
    fo(4*M+1) st[i] = -1e18;
    build(1,1,mx);
    ll l;
    ll res = 0;
    for(ll i = 1; i<=mx; i++){
        ll cur = query(1,1,mx,i,mx);
        // cout<<i<<"()"<<cur<<"\n";
        cur += (i-1)*k;
        if(cur > res){
            // if(k == 23274806583) cout<<cur<<"()\n";
            res = cur;
            l = i;
        }
        // if(i == 7) pr(query(1,1,mx,mx,mx));
        for(auto p: pr[i]){
            update_range(1,1,mx,p.ff.ff,mx,-1*p.ff.sec);
        }
    }
    if(res){
        ll r,tot = -1e18;
        // for(ll i = 1; i<=mx; i++) nw[i] -= i*k;
        for(ll i = l; i<=mx; i++){
            for(auto p: pr[i]){
                nw[p.ff.ff] += p.ff.sec;
            }
        }
        for(ll i = 1; i<=mx; i++){
            nw[i] += nw[i-1];
        }
        for(ll i = 1; i<=mx; i++) nw[i] -= i*k;
        for(ll i = l; i<=mx; i++){
            if(nw[i] > tot){
                tot = nw[i];
                r = i;
            }
        }
        if(tot + (l-1)*k != res){
            pr(0);
            return;
        }
        vl ans;
        for(ll i = l; i<=r; i++){
            for(auto p: pr[i]){
                if(p.ff.ff <= r) ans.pb(p.sec);
            }
        }
        cout<<res<<" "<<l<<" "<<r<<" "<<ans.size()<<"\n";
        for(auto x: ans) cout<<x<<" "; nl;
    }else{
        pr(res);
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
