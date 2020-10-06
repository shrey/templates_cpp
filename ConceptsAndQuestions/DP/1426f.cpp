

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
#define pr(t) cout<<t<<"\n"
#define int long long
ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll n;
const ll M = 2e5+1;
const ll K = 4;
string s;
ll dp[M][K][K] = {0};
ll pow3[M];

ll add(ll a, ll b){
    return ((a%mod) + (b%mod))%mod;
}

ll mult(ll a, ll b){
    return ((a%mod) * (b%mod))%mod;
}


int32_t main(){
    KOBE;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    //dp[i][j][k] is number of str w last jth char till i with k qn marks
    ll cnt = 0;
    fo(s.length()){
        if(s[i] == '?') cnt++;
    }
    pow3[0] = 1;
    for(ll i = 1; i<M; i++){
        pow3[i] = mult(pow3[i-1],3);
    }
    dp[0][0][0] = 1;
    for(ll i =0 ; i<n; i++){
        for(ll j = 0; j<=3; j++){
            for(ll k = 0; k<=3; k++){
                if(dp[i][j][k] == 0) continue;
                dp[i+1][j][k] = add(dp[i+1][j][k],dp[i][j][k]);
                if(j<3 && (s[i]-'a' == j || s[i] == '?')){
                    ll nk = (s[i] == '?')? k+1 : k;
                    dp[i+1][j+1][nk] = add(dp[i+1][j+1][nk],dp[i][j][k]);
                }
            }
        }
    }
    ll ans = 0;
    for(ll i = 0; i<=3; i++){
        if(cnt>=i){
            ans = add(ans,mult(dp[n][3][i],pow3[cnt-i]));
        }
    }
    cout<<ans<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
