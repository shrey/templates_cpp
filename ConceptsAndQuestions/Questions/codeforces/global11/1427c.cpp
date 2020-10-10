

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
#define imin INT_MIN
#define lmin LLONG_MIN
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define pr(t) cout<<t<<"\n"
#define int long long
#define endl "\n"

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

struct pos{
    ll x;
    ll y;
    ll time;
};



ll r,n;
const ll M = 1e6+1;
pos p[M];

ll dp[M] = {0};


ll calc(ll x1,ll y1, ll x2, ll y2){
    return (abs(x1-x2) + abs(y1-y2));
}

bool ok(pos &p1, pos &p2){
    ll t = calc(p1.x,p1.y,p2.x,p2.y);
    if((p2.time-p1.time)>=t) return true;
    return false;
}


void solve(){
    ll ans = 0;
    ll pmx = imin;
    pos in;

    for(ll i = 1; i<=n; i++){
        ll mx = imin;
        if(ok(p[0],p[i])) dp[i] = 1;
        if(i<2*r){
            for(ll j = 0; j<i; j++){
                if(ok(p[j],p[i]) && dp[j]) mx = max(dp[j],mx);
            }
            dp[i] = max(mx+1,dp[i]);
        }
        else{
            for(ll j = i-2*r; j<i; j++){
                if(ok(p[j],p[i]) && dp[j]) mx = max(dp[j],mx);
            }
            dp[i] = max(dp[i],max(mx+1,pmx+1));
            if(dp[i-2*r]) pmx = max(pmx,dp[i-2*r]);
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans<<"\n";
}


int32_t main(){
    KOBE;
    cin>>r>>n;
    p[0].x = 1; p[0].y = 1; p[0].time = 0;
    fo(n){
        cin>>p[i+1].time>>p[i+1].x>>p[i+1].y;
    }
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
