

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

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define ss second
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
#define pr(t) cout<<t<<"\n"
#define int long long
const ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll prod(ll a, ll b){
    ll ans = ((a*b)%mod);
    return ans;
}

ll sum(ll a, ll b){
    return (((a%mod) + (b%mod))%mod);
}


const ll M = 2e5+1;
ll dp[M][3] = {0};

int32_t main(){
    KOBE;
    ll n,l,r;
    cin>>n>>l>>r;
    ll r1 = 0,r2 = 0,r0 = 0;
    ll nl = l, nr = r;
    while(nl%3 && nl<r){
         if(nl%3 == 1) r1++;
         if(nl%3 == 2) r2++;
         nl++;
    }
    while(nr%3 && nr>l){
        if(nr%3 == 1) r1++;
        if(nr%3 == 2) r2++;
        nr--;
    }
    if(nl%3 == 1 && nl<=nr) r1++;
    if(nl%3 == 2 && nl<=nr) r2++;
    if(nr%3 == 1 && nr>nl) r1++;
    if(nr%3 == 2 && nr>nl) r2++;
    if(nl%3 == 0 && nr%3 == 0){
        r0 = (nr-nl)/3+1;
        r1+=((r0-1)>0?(r0-1):0);
        r2+=((r0-1)>0?(r0-1):0);
    }
    dp[1][0] = r0;
    dp[1][2] = r2;
    dp[1][1] = r1;
    // cout<<r0<<" "<<r1<<" "<<r2<<"\n";
    for(ll i = 2; i<=n; i++){
        dp[i][0] =  (prod(dp[i-1][0],r0) + prod(dp[i-1][1],r2) + prod(dp[i-1][2],r1))%mod;
        dp[i][1] = (prod(dp[i-1][1],r0)+prod(dp[i-1][2],r2)+prod(dp[i-1][0],r1))%mod;
        dp[i][2] = (prod(dp[i-1][0],r2)+prod(dp[i-1][1],r1)+prod(dp[i-1][2],r0))%mod;
    }
    // fo(n+1){
    //     forn(j,3) cout<<dp[i][j]<<" ";cout<<"\n";
    // }
    cout<<dp[n][0]<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
