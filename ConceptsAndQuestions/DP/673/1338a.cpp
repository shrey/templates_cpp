

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

ll pow(ll n, ll k){
    if(k == 0){
        return 1;
    }
    ll a = (pow(n,k/2));
    if(k%2){
        return ((((a*a)%mod)*(n%mod))%mod);
    }
    return ((a*a)%mod);
}

ll comp(ll a, ll b){
    ll t = 1;
    ll curr = 1;
    a+=curr;
    while(a<b){
        t++;
        curr*=2;
        a+=curr;
    }
    return t;
}

ll val(ll a, ll t, ll b){
    ll curr = 1<<(t-1);
    while(a<b){
        a+=curr;
        curr/=2;
    }
    return a;
}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        fo(n) cin>>arr[i];
        ll time = 0;
        for(ll i = 1; i<n; i++){
            if(arr[i]<arr[i-1]){
                ll diff = arr[i-1]-arr[i];
                time = max(comp(arr[i],arr[i-1]),time);
                arr[i] = arr[i-1];
            }
        }
        // fo(n) cout<<arr[i]<<" ";cout<<"\n";
        cout<<time<<"\n";
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
