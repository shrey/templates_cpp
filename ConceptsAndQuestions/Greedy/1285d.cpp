

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

const ll M = 1e5+100;
ll a[M],n;

ll comp(ll num){
    ll cur = 0;
    while(num > 0){
        num = num >> 1;
        cur++;
    }
    return cur-1;
}

ll recur(ll s, ll e){

    if(s>e) return 0;
    if(s == e) return 0;
    // cout<<s<<"()"<<e<<"\n";
    ll hb = comp(a[e]);
    ll mask = 1<<hb;
    ll m = s-1;
    if(a[e] == 0) return 0;
    for(ll i = s; i<=e; i++){
        if(a[i]>=mask){
            m = i-1;
            break;
        }
    }
    for(ll i = m+1; i<= e; i++){
        a[i] -= mask;
    }
    if(m == s-1){
        ll ans = recur(s,e);
        return ans;
    }
    ll ans = mask + min(recur(s,m),recur(m+1,e));
    // cout<<s<<"()"<<e<<" = "<<ans<<"\n";
    // for(ll i = s; i<=e; i++) cout<<a[i]<<" ";nl;
    return ans;
}

void solve(){
    re n; fo(n) re a[i];
    sort(a,a+n);
    pr(recur(0,n-1));
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
