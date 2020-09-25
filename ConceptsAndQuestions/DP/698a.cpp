

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

ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll m3(ll a,ll b, ll c){
    return min(a,min(b,c));
}

const ll M = 105;
ll dp[M][3];

int main(){
    KOBE;
    ll n;
    cin>>n;
    ll arr[n];
    fo(n) cin>>arr[i];
    fo(M){
        dp[i][0] = imax;
        dp[i][1] = imax;
        dp[i][2] = imax;
    }
    dp[0][1] = 0;
    dp[0][0] = 0;
    dp[0][2] = 0;
    //c-1 g-2

    for(ll i = 1; i<=n; i++){
        dp[i][0] = m3(dp[i-1][0],dp[i-1][1],dp[i-1][2])+1;

        if(arr[i-1] == 1){ // g-c, c-o
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
        }else if(arr[i-1] == 2){ //g-o c-c
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
        }else if(arr[i-1] == 3){ //g-o c-o
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
        }
    }
    cout<<m3(dp[n][0],dp[n][1],dp[n][2])<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
