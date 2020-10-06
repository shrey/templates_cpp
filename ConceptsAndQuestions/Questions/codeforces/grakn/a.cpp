

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
ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n], b[n], c[n];
        fo(n) cin>>a[i];
        fo(n) cin>>b[i];
        fo(n) cin>>c[i];
        vector<ll> ans;
        ans.pb(a[0]);
        for(ll i = 1; i<n-1; i++){
            if(a[i] == ans[i-1]){
                ans.pb(b[i]);
            }
            else{
                ans.pb(a[i]);
            }
        }
        if(a[n-1] == ans[n-2] || a[n-1] == ans[0]){
            if(b[n-1] == ans[n-2] || b[n-1] == ans[0]){
                ans.pb(c[n-1]);
            }
            else{
                ans.pb(b[n-1]);
            }
        }
        else{
            ans.pb(a[n-1]);
        }
        fo(n) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
