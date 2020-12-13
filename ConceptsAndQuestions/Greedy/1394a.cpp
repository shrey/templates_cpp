

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

void solve(){
    ll n,d,m;
    re n; re d; re m;
    ll a[n]; fo(n) re a[i];
    vl x,y;
    fo(n){
        if(a[i]>m) x.pb(a[i]);
        else y.pb(a[i]);
    }
    sort(x.rbegin(),x.rend());
    sort(y.rbegin(),y.rend());
    // fo(x.size()) cout<<x[i]<<" ";nl;
    // fo(y.size()) cout<<y[i]<<" ";nl;
    ll px[n+1];
    ll py[n+1];
    py[0] = 0; px[0] = 0;
    if(x.size()){
        px[1] = x[0];
        for(ll i = 2; i<=x.size(); i++){
            px[i] = (px[i-1] + x[i-1]);
        }
    }
    ll ans = 0;
    if(y.size()){
        py[1] = y[0];
        for(ll i = 2; i<=y.size(); i++){
            py[i] = py[i-1] + y[i-1];
        }
    }
    // fo(x.size()+1) cout<<px[i]<<" ";nl;
    // fo(y.size()+1) cout<<py[i]<<" ";nl;
    for(ll cnt = 0; cnt<=x.size(); cnt++){
        ll cur = px[cnt];
        ll rem = (cnt>0) ? n-(d+1)*(cnt-1)-1 : n;
        if(rem<0) break;
        cur += (rem<=y.size()) ? py[rem] : py[y.size()];
        // cout<<cnt<<"()"<<cur<<"\n";
        ans = max(cur,ans);
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
