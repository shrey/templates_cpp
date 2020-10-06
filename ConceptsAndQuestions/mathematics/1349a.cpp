

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
const ll M = 2e5+10;
ll arr[M];

ll gcd(ll a, ll b){

    return (b == 0)? a : gcd(b,a%b);
}


int32_t main(){
    KOBE;
    cin>>n;
    fo(n) cin>>arr[i];
    ll pre[n],suff[n];
    pre[0] = arr[0];
    suff[n-1] = arr[n-1];
    for(ll i = 1; i<n; i++){
        pre[i] = gcd(arr[i],pre[i-1]);
    }
    for(ll i = n-2; i>=0; i--){
        suff[i] = gcd(arr[i],suff[i+1]);
    }

    ll ans = 1;
    for(ll i = 0; i<n; i++){
        if(i == 0){
            ans = suff[i+1];
        }
        else if(i == n-1){
            ans = ans*pre[i-1]/(gcd(ans,pre[i-1]));
        }
        else{
            ll curr = gcd(pre[i-1],suff[i+1]);
            ans = ans*curr/(gcd(ans,curr));
        }
    }
    cout<<ans<<"\n";

}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
