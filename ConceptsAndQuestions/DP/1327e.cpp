

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

const ll mod = 998244353;

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

const ll M = 1e6+10;
ll p[M] = {0};

void pcom(){
    p[0] = 1;
    for(ll i = 1; i<M; i++){
        p[i] = (p[i-1]*10)%mod;
    }
}
ll n;

ll comp(ll i){
    ll ans = ((10*9*2*p[n-i-1])%mod + ((n-i-1)*10*p[n-i-2]*9*9)%mod)%mod;
    return ans;
}

int32_t main(){
    KOBE;
    pcom();
    cin>>n;
    vl ans;
    for(ll i = 1; i<=n; i++){
        if(i == n){
            ans.pb(10);
        }else{
            ans.pb(comp(i));
        }
    }
    fo(ans.size())cout<<ans[i]<<" ";  cout<<"\n";
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
