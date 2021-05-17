

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

deque<pll> dq;

bool inter(pair<int,int> l1,pair<int,int> l2,pair<int,int> l3){
    return (double)(l2.sec-l1.sec)*(double)(l1.ff-l3.ff) <= (double)(l3.sec-l1.sec)*(double)(l1.ff-l2.ff);
}


pair<int,int> retop(){
    return dq.front();
}

pair<int,int> sectop(){
    pair<int,int> one = dq.front();
    dq.pop_front();
    pair<int,int> two = dq.front();
    dq.push_front(one);
    return two;
}

pair<int,int> reback(){
    return dq.back();
}

pair<int,int> secback(){
    if(dq.size() == 1)return mp(1e15,1e15);
    pair<int,int> one = dq.back();
    dq.pop_back();
    pair<int,int> two = dq.back();
    dq.push_back(one);
    return two;
}

void solve(){
    ll n; re n;
    ll a[n],b[n];
    fo(n) re a[i]; fo(n) re b[i];
    ll dp[n];
    dp[0] = 0;
    dq.push_back(mp(b[0],0));
    for(ll i = 1; i<n; i++){
        while(dq.size() > 1){
            pll one = reback();
            pll two = secback();
            if(one.ff*a[i]+one.sec >= two.ff*a[i]+two.sec){
                dq.pop_back();
            }else break;
        }
        pll one = reback();
        dp[i] = one.ff*a[i]+one.sec;
        pll cur = mp(b[i],dp[i]);
        while(dq.size() > 1 && inter(cur,retop(),sectop())){
            dq.pop_front();
        }
        dq.push_front(cur);
    }
    //min convex hull
    pr(dp[n-1]);
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


/*
4
1 10 30 40
7 6 5 4
*/