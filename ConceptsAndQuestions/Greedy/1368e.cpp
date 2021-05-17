

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

ll mod = 998244353;

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

ll n,m;
const ll M = 2e5+100;
ll a[M],b[M];
ll pw[M];

// void comp(){
//     pw[0] = 1;
//     for(ll i = 1; i<M; i++){
//         pw[i] = (pw[i-1]*2)%mod;
//     }
// }

void solve(){
    re n; re m;
    fo(n) re a[i]; fo(m) re b[i];
    ll ans = 1;
    ll j = m-1;
    ll i = n-1;
    while(i >= 0 && a[i] != b[j]){
        if(a[i] < b[j]){
            pr(0);
            return;
        }
        i--;
    }
    if(i < 0){
        pr(0);
        return;
    }
    ll s = 0;
    while(s < n && a[s] != b[0]){
        if(a[s] < b[0]){
            pr(0);
            return;
        }
        s++;
    }
    if(s == n){
        pr(0);
        return;
    }
    while(j >= 0){
        bool flag = false;
        if(a[i] < b[j]){
            ans = 0;
            break;
        }
        ll idx = -1;
        while(i >= 0 && a[i] >= b[j]){
            if(a[i] == b[j]){
                flag = true;
                idx = max(idx,i);
            }
            i--;
        }
        ll cnt = idx-i;
        if(!flag){
            ans = 0;
            break;
        }
        // cout<<i<<"()"<<j<<"()"<<cnt<<"\n";
        if(j != 0) ans *= cnt;
        ans %= mod;
        j--;
    }
    if(i > s){
        pr(0);
        return;
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
// always check for n = 1 condition
// check loop starting and end points :(

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
