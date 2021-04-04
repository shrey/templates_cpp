

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

//code starts here

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

const ll M = 1e5+100;
ll n, a[M];

vl st(4*M + 1);
vl st2(4*M + 1);


ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 1e15;
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return min(query(2*v,tl,tm,l,r),query(2*v+1,tm+1,tr,l,r)); // change here
}

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        st[v] = a[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v] = min(st[2*v] , st[2*v+1]); // change here
}

ll query2(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 0;
    if(tl >= l && tr <= r) return st2[v];
    ll tm = (tl + tr)/2;
    return gcd(query2(2*v,tl,tm,l,r),query2(2*v+1,tm+1,tr,l,r)); // change here
}

void build2(ll v, ll tl, ll tr){
    if(tl == tr){
        st2[v] = a[tl];
        return;
    }
    ll tm = (tl + tr)/2;
    build2(2*v,tl,tm);
    build2(2*v+1,tm+1,tr);
    st2[v] = gcd(st2[2*v] , st2[2*v+1]); // change here
}



void solve(){
    re n; fo(n) re a[i];
    ll t; re t;
    build(1,0,n-1);
    build2(1,0,n-1);
    map<ll,vl> f;
    fo(n) f[a[i]].pb(i);
    while(t--){
        ll l,r; re l; re r;
        l--; r--;
        ll g = query2(1,0,n-1,l,r);
        ll m = query(1,0,n-1,l,r);
        // cout<<g<<"()"<<m<<"\n";
        if(g == m){
            auto it1 = upper_bound(f[m].begin(),f[m].end(),r);
            auto it2 = lower_bound(all(f[m]),l);
            ll op = it1-it2;
            // if(f[m][it2-f[m].begin()] >= l) op++;
            // cout<<op<<"()()\n";
            ll ans = r-l+1-op;
            pr(ans);
        }else{
            pr(r-l+1);
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

/*
5
1 3 2 4 2
4
3 5
*/