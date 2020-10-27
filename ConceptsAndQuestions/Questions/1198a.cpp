

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
#include<bitset>
#include<cstring>
#include<numeric>

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
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
#define vb vector<bool>
#define pr(t) cout<<t<<"\n"
#define int long long
#define ql queue<ll>
#define qp queue<pair<ll,ll> >
#define endl "\n"
#define nl cout<"\n"

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


//code starts here

ll n, I;
const ll M = 5e5;
ll arr[M];

ll comp(ll d){
    ll k = 0;
    while(1<<k < d){
        k++;
    }
    return k;
}

int32_t main(){
    KOBE;
    cin>>n>>I;
    ll allow = 8*I/n;
    fo(n) cin>>arr[i];
    map<ll,ll> freq;
    ll d = 0;
    fo(n){
        if(freq[arr[i]] == 0) d++;
        freq[arr[i]]++;
    }
    ll ans = 0;
    vl op;
    for(auto x: freq){
        op.pb(x.sec);
    }
    ll tot = op.size();
    ll distinct = 1;
    fo(allow){
        distinct*=2;
        if(distinct>=tot){
            pr(0);
            return 0;
        }
    }
    ll a[tot+1];
    a[0] = 0;
    for(ll i = 0; i<tot; i++){
        a[i+1] = op[i];
    }
    for(ll i= 1; i<=tot; i++){
        a[i] += a[i-1];
    }
    for(ll i = distinct; i<=tot; i++){
        ans = max(ans,a[i]-a[i-distinct]);
    }
    pr(n-ans);
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
