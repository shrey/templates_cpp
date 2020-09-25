

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
#define F first
#define S second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define imax INT_MAX
#define lmax LLONG_MAX
ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }

}

bool norep(ll arr[], ll n){
    for(int i = 1; i<n; i++){
        if(arr[i] == arr[i-1]) return false;
    }
    return true;
}

int main(){
    KOBE;
    ll n;
    cin>>n;
    ll arr[n];
    fo(n) cin>>arr[i];
    sort(arr,arr+n);
    if(norep(arr,n)){
        for(int i = 1; i<n; i++){
            swap(arr[i-1],arr[i]);
            i++;
        }
        ll ans = 0;
        for(int i = 1; i<n-1; i++){
            if(arr[i]<arr[i-1] && arr[i]<arr[i+1]) ans++;
        }
        cout<<ans<<"\n";
        fo(n) cout<<arr[i]<<" ";cout<<"\n";
        return 0;
    }

    vector<ll> sm;
    vector<ll> lg;
    for(int i = 0; i<n/2; i++){
        sm.pb(arr[i]);
    }
    for(int i = n/2; i<n; i++){
        lg.pb(arr[i]);
    }
    ll ans[n];
    ll j = 0;
    for(int i = 0; i<n; i+=2){
        ans[i] = lg[j];
        j++;
    }
    j = 0;
    for(int i = 1; i<n; i+=2){
        ans[i] = sm[j];
        j++;
    }
    ll res = 0;
    for(int i = 1; i<n-1; i++){
        if(ans[i]<ans[i-1] && ans[i]<ans[i+1]) res++;
    }
    cout<<res<<"\n";
    fo(n) cout<<ans[i]<<" ";cout<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
