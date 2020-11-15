

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
const ll M = 4002;
ll n,arr[M];
vl lst;
ll dp[M][M];

ll recur(ll i, ll sm){
    if(sm == n){
        return 1;
    }
    if(i == lst.size()){
        return 0;
    }
    if(dp[i][sm]!=-1) return dp[i][sm];
    ll ans = recur(i+1,sm);
    if(sm+lst[i]<=n){
        ans |= recur(i+1,sm+lst[i]);
    }
    dp[i][sm] = ans;
    return ans;
}

void solve(){
    re n;
    fo(2*n) re arr[i];
    lst.clear();
    ll cnt = 1;
    ll mx = arr[0];
    bool flag = true;
    // for(ll i = 1; i<2*n; i++){
    //     if(arr[i]<arr[i-1]) flag = false;
    // }
    // if(flag){
    //     YES;
    //     return;
    // }
    for(ll i = 1; i<2*n; i++){
        if(arr[i]>mx){
            mx = arr[i];
            lst.pb(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
    }
    lst.pb(cnt);
    // fo(lst.size()) cout<<lst[i]<<" ";nl;
    for(ll i = 0; i<=lst.size(); i++){
        for(ll j = 0; j<=n; j++){
            dp[i][j] = -1;
        }
    }
    if(recur(0,0)){
        YES;
    }else{
        NO;
    }
}

int32_t main(){
    KOBE;
    ll t;
    re t;
    // t = 1;
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
