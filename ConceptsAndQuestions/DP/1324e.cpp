

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

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
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
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define pr(t) cout<<t<<"\n"
#define int long long
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

ll n,h,l,r;
const ll M = 2000+10;

ll arr[M];
ll dp[M][M] = {0};

ll prev(ll t){
    if(t>=0) return t;
    return (t+24);
}

ll nxt(ll t){
    return (t%h);
}

bool ok(ll n){
    if(n>=l && n<=r) return true;
    return false;
}

ll recur(ll i, ll tme){
    if(i == n) return 0;
    ll a = 0;
    if(ok(tme)) a = 1;
    if(dp[i][tme]!=-1) return dp[i][tme];
    dp[i][tme] =  a + max(recur(i+1,nxt(tme+arr[i+1])),recur(i+1,nxt(tme+arr[i+1]-1)));
    return dp[i][tme];
}

int32_t main(){
    KOBE;
    cin>>n>>h>>l>>r;
    fo(n) cin>>arr[i];
    forn(i,M){
        forn(j,M){
            dp[i][j] = -1;
        }
    }
    cout<<max(recur(0,arr[0]-1),recur(0,arr[0]))<<"\n";
}
    // if(ok(arr[0])){
    //     dp[0][arr[0]] = 1;
    // }
    // if(ok(arr[0]-1)){
    //     dp[0][arr[0]-1] = 1;
    // }
    // ll ans = 0;
    // for(ll i = 1; i<n; i++){
    //     for(ll j = 0; j<=h; j++){

    //         ll t1 = prev(j-arr[i]);
    //         ll t2 = prev(j-(arr[i]-1));
    //         if(ok(j)){
    //             dp[i][j] = max(dp[i][j],dp[i-1][t1]+1);
    //         }
    //         if(ok(j)){
    //             dp[i][j] = max(dp[i][j],dp[i-1][t2]+1);
    //         }
    //         ans = max(ans,dp[i][j]);
    //     }
    // }
    // for(ll i = 0; i<n; i++){
    //     for(ll j = 0; j<=h; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<"\n";
    // }
    // cout<<ans<<"\n";


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
