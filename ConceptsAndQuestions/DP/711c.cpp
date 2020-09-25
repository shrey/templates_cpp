

//Shrey Dubey

//Contact Me at wshrey09@gmail.com



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
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to prll decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define imax ll_MAX
#define lmax LLONG_MAX
ll mod = 1e9 + 7;
const ll INF = ll(1e18);
ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }

}

ll min(ll a, ll b){
    if(a<b){
        return a;
    }return b;
}

const ll N = 105;
const ll M = 105;
ll c[M], p[M][M];
ll dp[M][M][M] = {0};
int main(){
    KOBE;
    ll n,m,k;
    forn(i,M){
        forn(j,M){
            forn(k,M){
                dp[i][j][k] = INF;
            }
        }
    }
    cin>>n>>m>>k;
    for(ll i = 0; i<n; i++){
        cin>>c[i];
    }
    forn(i,n){
        for(ll j = 1; j<=m; j++){
            cin>>p[i][j];
        }
    }
    if(c[0] == 0)
        for(ll i = 1; i<=m; i++){
            dp[0][1][i] = p[0][i];
        }
    else{
        dp[0][1][c[0]] = 0;
    }
    for(ll i = 1; i<n; i++){
        for(ll j = 1; j<=k; j++){
            ll ans = INF;
            if(c[i] == 0){
                for(ll col = 1; col<=m; col++){
                    for(ll pcol = 1; pcol<=m; pcol++){
                        if(pcol == col){
                            dp[i][j][col] = min(dp[i][j][col],dp[i-1][j][pcol]+p[i][col]);
                        }
                        else{
                            dp[i][j][col] = min(dp[i][j][col],dp[i-1][j-1][pcol]+p[i][col]);
                        }
                    }
                }
            }else{
                for(ll col = 1; col<=m; col++){
                    if(col == c[i]){
                        dp[i][j][c[i]] = min(dp[i][j][c[i]],dp[i-1][j][col]);
                    }
                    else{
                        dp[i][j][c[i]] = min(dp[i][j][c[i]],dp[i-1][j-1][col]);
                    }
                }
            }
        }
    }
    ll ans = INF;
    for(ll i = 1; i<=m; i++){
        ans = min(ans,dp[n-1][k][i]);
    }
    if(ans == INF){
        cout<<-1<<"\n";
        return 0;
    }
    // cout<<INF<<"\n";
    cout<<ans<<"\n";

}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
