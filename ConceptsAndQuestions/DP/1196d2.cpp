

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
#define imin INT_MIN
#define lmin LLONG_MIN
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define pr(t) cout<<t<<"\n"
#define int long long
#define endl "\n"

ll mod = 1e9 + 7;

ll cl(ld a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll flr(ld a){
    return (ll) a;
}
const ll M = 2e5+10;

void solve(){
    ll n,k;
    string s;
    cin>>n>>k>>s;
    string t = "RGB";
    ll ans = lmax;
    for(ll gp = 0; gp<3; gp++){
        ll curr = 0;
        vl res(n);
        for(ll i = 0; i<n; i++){
            res[i] = (s[i] != t[(i+gp)%3]);
            curr+=res[i];
            if(i>=k){
                curr-=res[i-k];
            }
            if(i>=(k-1)){
                ans = min(ans,curr);
            }
        }
    }
    cout<<ans<<"\n";
}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs


//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
