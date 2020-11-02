

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
#define re(x) cin>>x

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


const ll M = 1010;
ll c[M],d[M],dp[20][M][M],n,m,a[M],b[M];


ll recur(ll i, ll cnt, ll gms){
    if(gms==0 || i > m){
        return 0;
    }
    // cout<<i<<"()"<<cnt<<"()"<<gms<<"\n";
    if(dp[i][cnt][gms]!=-1){
        return dp[i][cnt][gms];
    }
    ll a1 = 0, a2 = 0, a3 = 0;
    if(a[i]>=(cnt+1)*b[i] && gms>=c[i]){
        a1 = d[i] + recur(i,cnt+1,gms-c[i]);
    }
    a3 = recur(i+1,0,gms);
    dp[i][cnt][gms] = max(a1,a3);
    return dp[i][cnt][gms];
}

void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>c[0]>>d[0];
    a[0] = 0; b [0] = 0;
    for(ll i = 1; i<=m; i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    pr(recur(0,0,n));
}

int32_t main(){
    KOBE;
    solve();
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
