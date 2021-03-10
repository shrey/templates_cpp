

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

const ll M = 3e5+100;

// ll gcd(ll a, ll b){ return (b == 0)? a : gcd(b,a%b);}

ll n,a[M];

const ll k = 18;
ll g[M][k+1] = {0};

ll gcd(ll a, ll b){ return (b == 0)? a : gcd(b,a%b);}

void precompute(){
    for(ll i = 0; i<n; i++){
        g[i][0] = a[i];
    }
    // pr("here");
    for(ll j = 1; j<=k; j++){
        for(ll i = 0; i+(1<<j) <= n; i++){
            // cout<<i<<"()"<<j<<"()"<<g[i][j]<<"\n";
            // cout<<g[i][j-1]<<" , "<<g[i+(1<<(j-1))][j-1]<<"\n";
            g[i][j] = gcd(g[i][j-1], g[i+(1<<(j-1))][j-1]);
        }
    }
}

ll qry(ll l, ll r){
    ll res = 0;
    for(ll j = k; j>=0; j--){
        if((1<<j) <= (r-l+1)){
            res = gcd(res,g[l][j]);
            l += (1<<j);
        }
    }
    return res;
}

ll b1(ll s, ll e, ll val){
    ll ans = e;
    ll idx = e;
    while(s <= e){
        ll mid = (s+e)/2;
        if(qry(mid,idx) == val){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}

ll b2(ll s, ll e, ll val){
    ll ans = s;
    ll idx = s;
    while(s <= e){
        ll mid = (s+e)/2;
        if(qry(idx,mid) == val){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    return ans;
}

set<ll> res[M];

void solve(){
    re n; fo(n) re a[i];
    precompute();
    ll ans = 0;
    for(ll i = 0; i<n; i++){
        ll l = b1(0,i,a[i]);
        ll r = b2(i,n-1,a[i]);
        if(r-l+1 > ans){
            // cout<<a[i]<<"\n";
            ans = r-l+1;
            res[r-l+1].insert(l+1);
        }else if(r-l+1 == ans){
            res[r-l+1].insert(l+1);
        }
    }
    cout<<res[ans].size()<<" "<<ans-1<<"\n";
    for(auto x: res[ans]) cout<<x<<" "; nl;

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
