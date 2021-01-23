

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

map<ll,ll> freq;

void comp(ll num){
    for(ll i = 2; i*i <= num; i++){
        if(num % i == 0){
            ll cnt = 0;
            while(num > 0 && num % i == 0){
                cnt++;
                num/=i;
            }
            freq[i] = max(freq[i],cnt);
        }
    }
    if(num > 1) freq[num] = max(freq[num],1ll);
}

bool check(ll num){
    vp op;
    for(ll i = 2; i*i <= num; i++){
        if(num % i == 0){
            ll cnt = 0;
            while(num > 0 && num % i == 0){
                cnt++;
                num/=i;
            }
            op.pb(mp(i,cnt));
        }
    }
    if(num > 1) op.pb(mp(num,1));
    for(auto x: op){
        if(x.sec > freq[x.ff]) return false;
    }
    return true;
}

ll gcd(ll a, ll b){ return ((b == 0)? a : gcd(b,a%b)); }
ll lcm(ll a, ll b){ return (a*b / gcd(a,b));}

void solve(){
    ll n,k;
    re n; re k;
    ll cur = 1;
    fo(n){
        ll x; re x;
        cur = gcd(k,lcm(cur,x));
    }
    if(cur == k) Yes;
    else No;
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
