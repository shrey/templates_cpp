

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

ll n,m;
const ll M = 2e5+100;
ll x;
vl a1;
vl a2;
vl b1;
vl b2;

ll bin(vl &a, ll num){
    ll s = 0, e = a.size()-1;
    ll ans = -1;
    while(s <= e){
        ll mid = (s+e)/2;
        if(num >= a[mid]){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    return ans;
}


ll comp(vl &a, vl &b){
    if(b.empty() || a.empty()) return 0;
    ll dp[b.size()];
    ll m = b.size();
    ll ans = 0;
    dp[0] = 1;
    map<ll,ll> f;
    fo(a.size()) f[a[i]]++;
    ll cnt[m+1];
    cnt[m] = 0;
    for(ll i = 1; i<m; i++){
        dp[i] = 1;
        if(b[i-1] == b[i]-1) dp[i] += dp[i-1];
    }
    for(ll i = m-1; i>=0; i--){
        if(f[b[i]]) cnt[i] = 1;
        else cnt[i] = 0;
        if(i != m-1) cnt[i] += cnt[i+1];
    }
    for(ll i = 0; i<m; i++){
        ll cur = bin(a,b[i]);
        ans = max(ans,min(dp[i],cur+1) + cnt[i+1]);
    }
    return ans;
}

void solve(){
    re n; re m;
    fo(n){
        re x;
        if(x > 0) a1.pb(x);
        else a2.pb(-1*x);
    }
    fo(m){
        re x;
        // x *= -1;
        if(x > 0) b1.pb(x);
        else b2.pb(-1*x);
    }
    reverse(all(a2)); reverse(all(b2));
    // for(auto x: a2) cout<<x<<" "; nl;
    // for(auto x: b2) cout<<x<<" "; nl;
    ll ans = 0;
    ans += comp(a1,b1) + comp(a2,b2);
    pr(ans);
    a1.clear(); a2.clear(); b1.clear(); b2.clear();
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
