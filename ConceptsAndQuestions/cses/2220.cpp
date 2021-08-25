

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
#include<deque>


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
#define vs vector<string>
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
#define LG 20

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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

//code starts here

ll a,b;
ll dp[25][20][2][2] = {0};
string s;
ll n;

// void precomp(){
//     for(ll i = 1; i<=19; i++){
//         for(ll j = 0; j<=9; j++){
//             if(i == 1){
//                 dp[i][j] = 1;
//                 continue;
//             }
//             for(ll k = 0; k<=9; k++){
//                 if(k != j) dp[i][j] += dp[i-1][k];
//                 // ext[i] += dp[i-1][k];
//             }
//         }
//     }
//     // for(ll i = 1; i<=5; i++){
//     //     for(ll j = 0; j<=9; j++) cout<<dp[i][j]<<" "; nl;
//     // }
// }

ll recur(ll i, ll dig, ll flag, ll lead){
    if(i == n) return 1;
    if(dig != -1 && dp[i][dig][flag][lead] != -1) return dp[i][dig][flag][lead];
    // cout<<i<<"()"<<dig<<"()"<<flag<<"\n";
    ll ans = 0;
    ll cur;
    if(flag) cur = s[i]-'0';
    else cur = 10;
    for(ll j = 0; j<cur; j++){
        if(j == dig && lead == 0) continue;
        ans += recur(i+1,j,0,(j == 0) & lead);
    }
    if(flag && (cur != dig || lead)) ans += recur(i+1,(s[i]-'0'),1,lead & (cur == 0));
    return dp[i][dig][flag][lead] = ans;
}

ll comp(ll num){
    if(num < 0) return 0;
    if(num == 0) return 1;
    memset(dp,-1,sizeof(dp));
    s.clear();
    s = to_string(num);
    // cout<<s<<"()\n";
    n = s.length();
    ll ans = recur(0,0,1,1);
    return ans;
}

void solve(){
    re a; re b;
    ll x = comp(a-1);
    ll y = comp(b);
    // cout<<x<<"()"<<y<<"\n";
    pr(y-x);
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
// always check for n = 1 condition
// check loop starting and end points :(

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
