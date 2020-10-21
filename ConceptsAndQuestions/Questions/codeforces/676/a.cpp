

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
#define vb vector<bool>
#define pr(t) cout<<t<<"\n"
#define int long long
#define ql queue<ll>
#define qp queue<pair<ll,ll> >
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


//code starts here

ll n,m,k;
const ll M = 80;
ll dp[71][71][36][71] = {0};
ll mat[71][71];


ll recur(ll i, ll j, ll c, ll r){
    if(i == n) return (r == 0);
    if(j == m) return recur(i+1,0,m/2,r);
    if(dp[i][j][c][r]!=-1) return dp[i][j][c][r];
    ll res = recur(i,j+1,c,r);
    if(c>0){
        ll op = recur(i,j+1,c-1,(r+mat[i][j])%k);
        res = max(res,mat[i][j]*(op!=0) + op);
    }
    return dp[i][j][c][r] = res;
}

void solve(){
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));
    forn(i,n){
        forn(j,m) cin>>mat[i][j];
    }
    cout<<recur(0,0,m/2,0)-1<<"\n";
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
/*
1 3
S10
011
00S
*/