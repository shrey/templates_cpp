

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

//code starts here

ll n;

ll qry(ll i, ll j,ll t){
    ll ans;
    if(t == 1){
        cout<<"AND ";
    }else if(t == 2){
        cout<<"OR ";
    }else{
        cout<<"XOR ";
    }
    cout<<i<<" "<<j<<"\n";
    cout.flush();
    re ans;
    cout.flush();
    return ans;
}

ll comp(ll val, ll x){
    ll ans = 0;
    for(ll i = 0; i<=16; i++){
        if(((1<<i) & x) == 0){
            if((1<<i) & val) ans |= (1<<i);
        }else{
            if(((1<<i) & val) == 0) ans |= (1<<i);
        }
    }
    return ans;
}

void solve(){
    ll n; re n;
    ll a1 = qry(1,2,1);
    ll a2 = qry(2,3,1);
    ll a3 = qry(1,3,1);
    ll x1 = qry(1,2,3);
    ll x2 = qry(2,3,3);
    ll x3 = x1 ^ x2;
    vl res(n+1);
    ll s1 = x1 + 2*a1;
    ll s2 = x2 + 2*a2;
    ll s3 = x3 + 2*a3;
    res[2] = (s1 + s2 - s3)/2;
    res[1] = comp(res[2],x1);
    res[3] = comp(res[2],x2);
    for(ll i = 4; i<=n; i++){
        ll x = qry(1,i,3);
        res[i] = comp(res[1],x);
    }
    cout<<"! "; for(ll i = 1; i<=n; i++) cout<<res[i]<<" "; nl;
    cout.flush();
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
