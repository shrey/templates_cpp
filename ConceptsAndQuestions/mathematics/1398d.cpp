

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

ll R,G,B;
const ll M = 210;
ll dp[M][M][M] = {0};
ll r[M],g[M],b[M];

void solve(){
    ll ans = 0;
    for(ll i = 0; i<=R; i++){
        for(ll j = 0; j<=G; j++){
            for(ll k = 0; k<=B; k++){
                if(i<R && j<G)
                    dp[i+1][j+1][k] = max(dp[i+1][j+1][k],dp[i][j][k] + r[i]*g[j]);
                if(i<R && k<B)
                    dp[i+1][j][k+1] = max(dp[i+1][j][k+1],dp[i][j][k] + r[i]*b[k]);
                if(j<G && k<B)
                    dp[i][j+1][k+1] = max(dp[i][j+1][k+1],dp[i][j][k] + g[j]*b[k]);
                ans = max(ans,dp[i][j][k]);
            }
        }
    }
    cout<<ans<<"\n";
}


int32_t main(){
    KOBE;
    cin>>R>>G>>B;
    fo(R) cin>>r[i];
    fo(G) cin>>g[i];
    fo(B) cin>>b[i];
    sort(r,r+R,greater<int>());
    sort(g,g+G,greater<int>());
    sort(b,b+B,greater<int>());
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
