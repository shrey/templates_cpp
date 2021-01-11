

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

const ll M = 2e6+100;

vl st(4*M + 1);
ll a[M];

void update(ll v, ll tl, ll tr, ll pos, ll change){
    if(tl == tr){
        st[v] += change; //change here
        return;
    }
    ll tm = (tl + tr)/2;
    if(pos <= tm) update(2*v,tl,tm,pos,change);
    else update(2*v + 1,tm+1,tr,pos,change);
    st[v] = st[2*v] + st[2*v+1]; //change here
}

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return 0;
    if(tl >= l && tr <= r) return st[v];
    ll tm = (tl + tr)/2;
    return query(2*v,tl,tm,l,r) + query(2*v+1,tm+1,tr,l,r); // change here
}

// void build(ll v, ll tl, ll tr){
//     if(tl == tr){
//         st[v] = a[tl];
//         return;
//     }
//     ll tm = (tl + tr)/2;
//     build(2*v,tl,tm);
//     build(2*v+1,tm+1,tr);
//     st[v] = st[2*v] + st[2*v+1]; // change here
// }

vector<int> z_function(string &s) {   // replace vector<ll> by string to get string
    int n = (int) s.size();
    vector<int> z(2*n+1);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve(){
    string s; re s;
    vl zs = z_function(s);
    ll ans = 0;
    ll n = s.length();
    vl z = z_function(s);
    for(ll i = 1; i<n; i++){
        update(1,0,n,z[i],1);
    }
    for(ll i = n-1; i>1; i--){
        if(z[i] != n-i) continue;
        ll p1 = query(1,0,n,0,n);
        ll p2 = query(1,0,n,0,z[i]-1);
        if(p1 - p2 >= 2){
            ans = max(ans,z[i]);
        }
        update(1,0,n,z[i],-1);
    }
    if(!ans){
        pr("Just a legend"); return;
    }
    pr(s.substr(0,ans));
}

int32_t main(){
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
// try to find repeating pattern in matrices
