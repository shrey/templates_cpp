

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

const ll M = 2e5+1;
ll arr[M];
ll pre[M] = {0};
ll subs[M];
ll n,m,k;

int main(){
    KOBE;
    cin>>n>>m>>k;
    ll curr = 0;
    fo(n){
        cin>>arr[i];
        curr+=arr[i];
        pre[i]+=curr;
    }
    subs[0] = pre[m-1];
    for(int i = 1; i<=(n-m); i++){
        subs[i] = pre[i+m-1] - pre[i-1];
    }
    ll t = n-m+1;
    ll dp[n][k+1];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=k; j++){
            dp[i][j] = 0;
        }
    }
    // fo(t) cout<<subs[i]<<" ";cout<<endl;
    for(ll i = 0; i<m; i++){
        dp[i][1] = i == 0? subs[i] : max(subs[i],dp[i-1][1]);
    }
    for(ll i = m; i<t; i++){
        for(ll j = 1; j<=k; j++){
            dp[i][j] = max(subs[i]+dp[i-m][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[t-1][k]<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
