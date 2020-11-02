

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
#define re(x) cin>>x
#define pll pair<ll,ll>
#define FOR(a,b) for(ll i = a; i<=b; i++)

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

ll n,m;
const ll M = 3e5;
ll a[M],b[M];
void solve(){
    ll n;
    re(n);
    fo(n) re(a[i]);
    ll m;
    re(m);
    fo(m) re(b[i]);
    vp dist;
    fo(n){
        dist.pb(mp(a[i],1));
    }
    fo(m){
        dist.pb(mp(b[i],2));
    }
    sort(dist.begin(),dist.end());
    ll ans = 2*(n-m);
    ll acnt = 0, bcnt = 0;
    ll sa = 2*n, sb = 2*m;
    for(ll i = dist.size()-1; i>=0; i--){
        if(dist[i].sec == 1){
            acnt++;
        }
        else{
            bcnt++;
        }
        ll val = 3*acnt-3*bcnt + 2*((n-acnt) - (m-bcnt));
        if(val>=ans){
            ans = val;
            sa = 3*acnt + 2*(n-acnt);
            sb = 3*bcnt + 2*(m-bcnt);
        }
    }
    cout<<sa<<":"<<sb<<"\n";

}

int32_t main(){
    KOBE;
    solve();
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
