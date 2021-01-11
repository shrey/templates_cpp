

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
    return (ll) a;
}



//code starts here

string s;
ll n,k;
vp st[26];
const ll M = 101;
ll dp[M][27][M];
char a,b;
ll x;
ll mat[27][27] = {0}, inf = -1e15;

ll recur(ll i, ll ch, ll k){
    if(i == s.length()) return 0;
    if(dp[i][ch][k] != -1) return dp[i][ch][k];
    ll ans = inf;
    ans = mat[ch][s[i]-'a'] + recur(i+1,s[i]-'a',k);
    if(k){
        forn(j, 26){
            if(j != s[i]-'a'){
                ll cur = mat[ch][j] + recur(i+1,j,k-1);
                ans = max(ans,cur);
            }
        }
    }
    return dp[i][ch][k] = ans;
}

void solve(){
    memset(dp,inf,sizeof(dp));
    re s; re k;
    re n;
    fo(n){
        re a; re b; re x;
        mat[a-'a'][b-'a'] = x;
    }
    dp[0][26][k] = 0;
    for(ll i = 0; i<s.length(); i++){
        for(ll j = 0; j<=k; j++){
            for(ll l = 0; l<=26; l++){
                ll ch = s[i] - 'a';
                if(dp[i][l][j] == inf) continue;
                dp[i+1][ch][j] = max(dp[i+1][ch][j], dp[i][l][j] + mat[l][ch]);
                if(j != 0){
                    forn(p,26){
                        dp[i+1][p][j-1] = max(dp[i+1][p][j-1],dp[i][l][j] + mat[l][p]);
                    }
                }
            }
        }
    }
    ll ans = inf;
    n = s.length();
    forn(i,26){
        forn(j,k+1) ans = max(ans,dp[n+1][i][j]);
    }
    pr(ans);
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
