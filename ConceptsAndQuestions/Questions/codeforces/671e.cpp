

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

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}

bool con(ll a, ll b){
    if(gcd(a,b) == 1) return true;
    return false;
}

int main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> factors;
        for(ll i = 2; (i*i)<=n; i++){
            if(n%i == 0){
                factors.pb(i);
                factors.pb(n/i);
            }
        }
        sort(factors.begin(), factors.end());
        ll arr[factors.size()];
        ll m = factors.size();
        ll j = 0;
        for(ll i = 0; i<m; i+=2){
            arr[i] = factors[j];
            j++;
        }
        for(ll i = 1; i<m; i+=2){
            arr[i] = factors[j];
            j++;
        }
        ll ans = 0;
        if((con(arr[0],arr[m-1]))) ans++;
        for(int i = 1; i<n; i++){
            if(con(arr[i],arr[i-1])) ans++;
        }
        fo(m) cout<<arr[i]<<" ";cout<<"\n";
        cout<<ans<<"\n";
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
