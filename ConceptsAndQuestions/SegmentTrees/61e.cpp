

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

const ll M = 1e6+100;

vl st1(4*M+1,0);
vl st2(4*M+1,0);

void update(vl &st, ll v, ll tl, ll tr, ll pos, ll change){
    if(tl == tr){
        st[v] += change;
        // cout<<tl<<"()"<<st[v]<<"\n";
        return;
    }
    ll tm = (tl + tr)/2;
    if(pos <= tm){
        update(st,2*v,tl,tm,pos,change);
    }else{
        update(st,2*v+1,tm+1,tr,pos,change);
    }
    st[v] = st[2*v] + st[2*v+1];
}

ll query(vl &st, ll v, ll tl, ll tr, ll l, ll r){
    if(tr < l || tl > r) return 0;
    if(tl >= l && tr <= r) {
        // cout<<tl<<"()"<<tr<<" = "<<st[v]<<"\n";
        return st[v];
    }
    ll tm = (tl + tr)/2;
    return (query(st,2*v,tl,tm,l,r) + query(st,2*v+1,tm+1,tr,l,r));
}

void solve(){
    ll n; re n;
    ll a[n];
    map<ll,ll> cord;
    fo(n){
        re a[i];
        cord[a[i]];
    }
    ll cur = 1;
    for(auto x: cord){
        cord[x.ff] = cur++;
    }
    fo(n) a[i] = cord[a[i]];
    ll ans = 0;
    update(st1,1,0,M-1,a[0],1);
    for(ll i = 2; i<n; i++){
        update(st2,1,0,M-1,a[i],1);
    }
    // pr(query(st1,1,0,M-1,0,4));
    for(ll i = 1; i<n-1; i++){
        ll n1 = query(st1,1,0,M-1,a[i],M-1);
        ll n2 = query(st2,1,0,M-1,0,a[i]);
        // cout<<n1<<"()"<<n2<<"\n";
        ans += (n1 * n2);
        update(st1,1,0,M-1,a[i],1);
        update(st2,1,0,M-1,a[i+1],-1);
    }
    pr(ans);
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
