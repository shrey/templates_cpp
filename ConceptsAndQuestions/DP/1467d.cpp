

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

ll n,k,q;
const ll M = 5010;
ll a[M];
ll dp[M][M];

ll recur(ll mv, ll ind){
    if(mv == 0){
        return dp[mv][ind] = 1;
    }
    if(dp[mv][ind] != -1) return dp[mv][ind];
    ll ans = 0;
    if(ind > 0) ans += recur(mv - 1, ind -1);
    ans %= mod;
    if(ind < n-1) ans += recur(mv - 1, ind + 1);
    ans %= mod;
    return dp[mv][ind] = ans % mod;
}

void solve(){
    re n; re k; re q;
    fo(n) re a[i];
    memset(dp,-1,sizeof(dp));
    fo(n) recur(k,i);
    ll cnt[n];
    ll ans = 0;
    fo(n){
        ll cur = 0;
        forn(j,k+1){
            if(dp[j][i] != -1) cur+=(dp[j][i] * dp[k - j][i])%mod;
            cur %= mod;
        }
        cout<<i<<" , "<<cur<<"\n";
        cnt[i] = cur;
        ans += cur * a[i];
        ans %= mod;
    }
    fo(q){
        ll ind, val;
        re ind; re val;
        ind--;
        ans += (cnt[ind] * (val - a[ind]))%mod;
        ans = (ans + mod) % mod;
        a[ind] = val;
        pr(ans);
    }

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


// //Shrey Dubey


// #include<iostream>
// #include<string>
// #include<algorithm>
// #include<map>
// #include<unordered_map>
// #include<vector>
// #include<set>
// #include<list>
// #include<iomanip>
// #include<queue>
// #include<stack>
// #include <math.h>
// #include<climits>
// #include<bitset>
// #include<cstring>
// #include<numeric>
// #include<array>


// using namespace std;
// typedef long long ll;
// typedef long double ld;

// #define YES cout<<"YES\n"
// #define Yes cout<<"Yes\n"
// #define NO cout<<"NO\n"
// #define No cout<<"No\n"
// #define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
// #define pb push_back
// #define ff first
// #define sec second
// #define umap unordered_map
// #define mp make_pair
// #define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// #define fo(n) for(ll i = 0; i<n; i++)
// #define fnd(stl, data) find(stl.begin(), stl.end(), data)
// #define forn(x,n) for(ll x = 0; x<n; x++)
// #define imax INT_MAX
// #define lmax LLONG_MAX
// #define imin INT_MIN
// #define lmin LLONG_MIN
// #define vi vector<int>
// #define vl vector<ll>
// #define vp vector<pair<ll,ll> >
// #define vb vector<bool>
// #define pr(t) cout<<t<<"\n"
// #define int long long
// #define ql queue<ll>
// #define qp queue<pair<ll,ll> >
// #define endl "\n"
// #define nl cout<<"\n"
// #define re cin >>
// #define pll pair<ll,ll>
// #define FOR(a,b) for(ll i = a; i<=b; i++)
// #define all(x) x.begin(),x.end()

// // ll dx[] = {1,0,-1,0};
// // ll dy[] = {0,1,0,-1};

// ll mod = 1e9 + 7;

// ll cl(ld a){
//     if(a>(ll) a){
//         return (ll)a+1;
//     }
//     else{
//         return (ll)a;
//     }
// }

// ll flr(ld a){
//     return (ll) a;
// }



// //code starts here

// ll n,k,q;
// const ll M = 5010;
// ll a[M];
// ll dp[M][M] = {0};

// // ll recur(ll mv, ll ind){
// //     if(mv == 0){
// //         return dp[mv][ind] = 1;
// //     }
// //     if(dp[mv][ind] != -1) return dp[mv][ind];
// //     ll ans = 0;
// //     if(ind > 0) ans += recur(mv - 1, ind -1);
// //     ans %= mod;
// //     if(ind < n-1) ans += recur(mv - 1, ind + 1);
// //     ans %= mod;
// //     return dp[mv][ind] = ans % mod;
// // }

// void solve(){
//     re n; re k; re q;
//     fo(n) re a[i];
//     // fo(n) recur(k,i);
//     fo(n) dp[0][i] = 1;
//     for(ll mv = 1; mv <= k; mv ++){
//         for(ll i = 1; i<n-1; i++){
//             dp[mv][i] = (dp[mv-1][i-1] + dp[mv-1][i+1])%mod;
//         }
//         dp[mv][0] = dp[mv-1][1], dp[mv][n-1] = dp[mv-1][n-2];
//     }
//     ll ans = 0;
//     ll cnt[n];
//     fo(n){
//         ll cur = 0;
//         forn(j,k+1){
//             if(dp[j][i] != -1) cur+=dp[j][i];
//         }
//         cout<<i<<" , "<<cur<<"\n";
//         cnt[i] = cur;
//         ans += cur * a[i];
//     }
//     fo(q){
//         ll ind, val;
//         re ind; re val;
//         ind--;
//         ans += cnt[ind] * (val - a[ind]);
//         a[ind] = val;
//         pr(ans);
//     }

// }

// int32_t main(){
//     KOBE;
//     ll t;
//     t = 1;
//     // re t;
//     while(t--) solve();
// }


// //common errors
// // row - n, col - m always and loop var
// // see the freq of numbers carefully
// // see if there's array overflow
// // use map for large inputs


// //problem ideas
// //check piegonhole wherever possible
// //there might be many instances of limited answers like 0,1,2 only
// // see suffix and prefix
// //don't be obsessed with binary search
// // try to find repeating pattern in matrices
