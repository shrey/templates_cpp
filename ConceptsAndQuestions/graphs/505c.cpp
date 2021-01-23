

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
#define all(x) x.begin(),x.end()

// ll dx[] = {1,0,-1,0};
// ll dy[] = {0,1,0,-1};

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
    if(a < 0.0){
        return (ll) a - 1;
    }
    return (ll) a;
}

//code starts here

ll n,d,x;
const ll M = 3e4+2;
ll dp1[M][310];
ll dp2[M][310];
ll gems[M] = {0};

ll recur(ll i, ll j){
    if(i >= M) return 0;
    // cout<<i<<"()"<<j<<"\n";
    ll ans;
    if(j < 0){
        if(dp2[i][abs(j)] != -1) return dp2[i][abs(j)];
        ans = recur(i+d+j+1,j+1);
        if(i + d + j > 0) ans = max(ans,recur(i + d + j,j));
        if(d + j - 1 > 0) ans = max(ans,recur(i+d+j-1,j-1));
        ans += gems[i];
        return dp2[i][abs(j)] = ans;
    }else{
        if(dp1[i][j] != -1) return dp1[i][j];
        ans = recur(i+d+j+1,j+1);
        if(i + d + j > 0) ans = max(ans,recur(i + d + j,j));
        if(d + j - 1 > 0) ans = max(ans,recur(i+d+j-1,j-1));
        ans += gems[i];
        return dp1[i][j] = ans;
    }
}

void solve(){
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    re n; re d;
    fo(n){
        re x;
        gems[x]++;
    }
    // pr(gems[24]);
    pr(recur(d,0));
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    // re t;
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
// try to find repeating pattern in matrices
