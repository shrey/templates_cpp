

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
#include<array>

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
#define nl cout<<"\n"
#define re cin >>
#define pll pair<ll,ll>
#define FOR(a,b) for(ll i = a; i<=b; i++)

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

const ll M  = 110;
const ll inf = 1e9;
ll n, arr[M];

ll dp[M][M][M][2];


ll recur(ll i, ll ec, ll oc, ll op){
    if(i == n) return 0;
    // cout<<i<<"()"<<ec<<"()"<<oc<<"()"<<op<<"\n";
    if(dp[i][ec][oc][op] != -1) return dp[i][ec][oc][op];
    ll a = inf, b = inf;
    if(arr[i] == 0){
        if(op == 0){
            if(ec) a = recur(i+1,ec-1,oc,0);
            if(oc) b = 1 + recur(i+1,ec,oc-1,1);
        }else{
            if(ec) a = 1 + recur(i+1,ec-1,oc,0);
            if(oc) b = recur(i+1,ec,oc-1,1);
        }
        return dp[i][ec][oc][op] = min(a,b);
    }else{
        ll k = 0;
        if(arr[i]%2 != op) k++;
        k += recur(i+1,ec,oc,arr[i]%2);
        return dp[i][ec][oc][op] = k;
    }
}

void solve(){
    re n;
    memset(dp,-1,sizeof(dp));
    ll e = 0, o = 0;
    vl present(n+1,0);
    fo(n){
        re arr[i];
        present[arr[i]] = 1;
    }
    for(ll i = 1; i<=n; i++){
        if(!present[i]){
            if(i%2) o++;
            else e++;
        }
    }
    ll ans = min(recur(0,e,o,1),recur(0,e,o,0));
    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    while(t--) solve();
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
