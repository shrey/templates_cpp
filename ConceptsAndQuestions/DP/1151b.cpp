

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

ll n,m;
const ll M = 510;
ll mat[M][M];
ll dp[M][1024] = {0};
ll pos[M][1024];

int32_t main(){
    KOBE;
    cin>>n>>m;
    forn(i,n){
        forn(j,m){
            cin>>mat[i][j];
        }
    }
    for(ll i = 0; i<m; i++){
        dp[0][mat[0][i]] = 1;
        pos[0][mat[0][i]] = i;
    }
    for(ll i = 1; i<n; i++){
        for(ll j = 0; j<m; j++){
            for(ll k = 0; k<=1023; k++){
                ll tmp = mat[i][j]^k;
                if(dp[i-1][k]){
                    dp[i][tmp] = 1;
                    pos[i][tmp] = j;
                }
            }
        }
    }
    ll ans = -1;
    for(ll i = 1; i<=1023; i++){
        if(dp[n-1][i]){
            ans = i;
        }
    }
    if(ans == -1){
        cout<<"NIE\n";
        return 0;
    }else{
        cout<<"TAK\n";
        vl res;
        for(ll i = n-1; i>=0; i--){
            ll j = pos[i][ans];
            res.pb(j);
            ans^=(mat[i][j]);
        }
        for(ll i = res.size()-1; i>=0; i--){
            cout<<res[i]+1<<" ";
        }cout<<"\n";
    }
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
