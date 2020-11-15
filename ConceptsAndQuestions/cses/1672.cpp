

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
// #define int long long
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

ll n,m,q,x,y,w;
const ll M = 510;
ll gr[M][M];
const ll inf = ;


void solve(){
    forn(i,M)
        forn(j,M)
            gr[i][j] = inf;

    re n; re m; re q;

    // pr("here");
    fo(m){
        re x; re y; re w;
        gr[x][y] = min(gr[x][y],w);
        gr[y][x] = min(gr[y][x],w);
    }
    fo(M){
        gr[i][i] = 0;
    }
    for(ll k = 1; k<=n; k++){
        for(ll i = 1; i<=n; i++){
            for(ll j = 1; j<=n; j++){
                gr[i][j] = min(gr[i][j],gr[i][k] + gr[k][j]);
            }
        }
    }
    // pr("here");
    vl ans;
    while(q--){
        re x; re y;
        if(gr[x][y] == inf){
            ans.pb(-1);
        }
        else ans.pb(gr[x][y]);
    }
    fo(ans.size()) pr(ans[i]);
}

int main(){
    KOBE;
    ll t;
    // re t;
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
