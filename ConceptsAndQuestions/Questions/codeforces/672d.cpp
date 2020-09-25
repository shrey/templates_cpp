

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
#define lmin LLONG_MIN
#define vi vector<int>
#define vl vector<ll>
#define pr(t) cout<<t<<"\n"

const ll mod = 998244353;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll c(ll n, ll k){
    if(k>n) return 0;
    k = min(k,n-k);
    if(k == 0){
        return 1;
    }
    return c(n-1,k) + c(n-1,k-1);
}

ll n,k;
const ll M = 3e5+10;
ll l[M], r[M];
vector<pair<ll,ll> > tme;
ll dp[M][2] = {0};

ll total = 0;

ll recur(ll i, ll l, ll r){
    if(i == n){
        return 0;
    }
    ll ans = 0;

    if(tme[i].ff<=r && tme[i].ss>=l){
        ans += recur(i+1,max(l,tme[i].ff),min(r,tme[i].ss))+1;
    }
    ans += recur(i+1,l,r);
    if(ans>=k){
        total+=c(ans,k);
    }
    return ans;
}

int main(){
    KOBE;
    cin>>n>>k;
    fo(n){
        ll l,r;
        cin>>l>>r;
        tme.pb(mp(l,r));
    }
    sort(tme.begin(),tme.end());
    recur(0,lmin,lmax);
    cout<<total<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
