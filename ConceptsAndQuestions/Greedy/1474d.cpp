

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

ll n;

bool check(vl &a){
    ll n = a.size();
    for(ll i = 0; i<n-1; i++){
        if(a[i] < 0) return false;
        a[i+1] -= a[i];
    }
    if(a[n-1] == 0) return true;
    else return false;
}

void solve(){
    re n;
    vl a(n);
    fo(n) re a[i];
    vl pref(n),suff(n);
    vl b = a;
    if(check(b)){
        YES;
        return;
    }
    b = a;
    swap(b[0],b[1]);
    if(check(b)){
        YES;
        return;
    }
    b = a;
    swap(b[n-1],b[n-2]);
    if(check(b)){
        YES;
        return;
    }
    b = a;
    pref[0] = a[0];
    for(ll i = 1; i<n; i++){
        if(b[i] < b[i-1] || pref[i-1] == -1){
            pref[i] = -1;
        }else{
            b[i] -= b[i-1];
            b[i-1] = 0;
            pref[i] = b[i];
        }
    }
    b = a;
    suff[n-1] = b[n-1];
    for(ll i = n-2; i>=0; i--){
        if(b[i] < b[i+1] || suff[i+1] == -1){
            suff[i] = -1;
        }else{
            b[i] -= b[i+1];
            b[i+1] = 0;
            suff[i] = b[i];
        }
    }
    for(ll i = 1; i<n-2; i++){
        vl v;
        v.pb(pref[i-1]); v.pb(a[i]); v.pb(a[i+1]); v.pb(suff[i+2]);
        swap(v[1],v[2]);
        if(check(v)){
            YES;
            return;
        }
    }
    NO;
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
