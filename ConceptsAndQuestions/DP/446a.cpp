

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
#define imin INT_MIN
#define lmin LLONG_MIN
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

ll n;
const ll M = 2e5+1;
ll arr[M];
ll l[M] = {0}, r[M] = {0};

ll solve(){
    if(n == 1) return 1;
    ll len = 1;
    l[0] =  1;
    for(ll i = 1; i<n; i++){
        l[i] = 1;
        if(arr[i]>arr[i-1]){
            l[i] = l[i-1]+1;
        }
    }
    r[n-1] = 1;
    for(ll i = n-2; i>=0; i--){
        r[i] = 1;
        if(arr[i]<arr[i+1]){
            r[i] = r[i+1]+1;
        }
    }
    // s
    ll ans = 2;
    for(ll i = 0; i<n; i++){
        if(i == 0){
            ans = max(ans,r[i+1]+1);
        }
        else if(i == n-1){
            ans = max(ans,l[i-1]+1);
        }
        else if(arr[i-1]+1<arr[i+1]){
            ans = max(ans,l[i-1]+r[i+1]+1);
        }
        else{
            ans = max(ans,l[i-1]+1);
            ans = max(ans,r[i+1]+1);
        }
    }
    return ans;
}

int main(){
    KOBE;
    cin>>n;
    fo(n){
        cin>>arr[i];
    }

    cout<<solve()<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
