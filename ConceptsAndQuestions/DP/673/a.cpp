

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

ll a,b,k;

ll num(string s){
    ll ans = 0;
    reverse(all(s));
    for(ll i = 0; i<s.length(); i++){
        ans += (1<<i) * (s[i] == '1');
    }
    return ans;
}

void bin(ll num){
    string s = "";
    ll cur =1 ;
    while(cur <= num){
        if(num & cur) s += '1';
        else s += '0';
        cur *= 2;
    }
    reverse(all(s));
    pr(s);
    return;
}

void solve(){
    re a; re b; re k;
    string x = "",y = "";
    if((a == 0 || b == 1) || k == 0){
        if(k){
            No;
            return;
        }
        while(b) x += '1', b--, y += '1';
        while(a) y += '0', a--, x += '0';
        Yes;
        pr(x); pr(y);
        return;
    }
    if(a + b < k+2){
        No;
        return;
    }
    // pr("here");
    ll ta = a, tb = b;
    while(b) x += '1', b--, y += '1';
    while(a) x += '0', a--, y += '0';
    a = ta, b = tb;
    // pr("here");
    // fo(a+b) y += '0';
    // y[0] = '1';
    // b--;
    y[b-1] = '0';
    ll idx = a+b-1-(a-min(a,k));
    // pr(idx);
    y[a+b-1-(a - min(a,k))] = '1';
    k -= min(a,k);
    if(k){
        y[b-k-1] = '0';
        y[b-1] = '1';
    }
    Yes;
    pr(x);
    pr(y);
    // bin(num(x) - num(y));

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
