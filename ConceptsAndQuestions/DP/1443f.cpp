

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

ll mod = 998244353;

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
ll n,k;
ll a[M], b[M];

void solve(){
    re(n); re(k);
    fo(n) re(a[i]);
    fo(k) re(b[i]);
    umap<ll,ll> pos;
    umap<ll,bool> mark;
    for(ll i = 0; i<n; i++){
        pos[a[i]] = i;
    }
    vl posarr;
    ll ans = 1;
    fo(k){
        posarr.pb(pos[b[i]]);
        mark[pos[b[i]]] = true;
    }
    for(ll i = 0; i<k; i++){
        ll cur = 0;
        if(posarr[i]>0 && !mark[posarr[i]-1]){
            cur++;
            mark[posarr[i]] = false;
        }
        if(posarr[i]<n-1 && !mark[posarr[i]+1]){
            cur++;
            mark[posarr[i]] = false;
        }
        ans = (ans*cur)%mod;
    }
    // sort(posarr.begin(),posarr.end());

    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    re(t);
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
