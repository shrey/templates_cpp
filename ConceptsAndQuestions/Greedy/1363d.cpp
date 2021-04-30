

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

vector<vl> op(1009);
ll idx[1010];

ll qry(vl &cur){
    cout<<"? "<<cur.size()<<" "; for(auto x: cur) cout<<x<<" "; nl;
    cout.flush();
    ll x; re x;
    cout.flush();
    return x;
}

ll solve(){
    ll n,k;
    re n; re k;
    fo(k+1) op[i].clear();
    fo(k){
        ll x; re x;
        op[i].resize(x);
        forn(j,x){
            re op[i][j];
            idx[op[i][j]] = i;
        }
    }
    vl cur;
    fo(n) cur.pb(i+1);
    ll mx = qry(cur);
    if(mx == -1) return 0;
    // pr("here");
    cur.clear();
    vl res(k+10);
    ll s = 0, e = n-1;
    while(s < e){
        // cout<<s<<"()"<<e<<"\n";
        ll mid = (s+e)/2;
        vl cur;
        for(ll i = s; i<=mid; i++) cur.pb(i+1);
        ll m = qry(cur);
        if(m == -1) return 0;
        if(m == mx){
            e = mid;
        }else{
            // cout<<m<<"()()\n";
            s = mid+1;
        }
    }
    s++;
    for(ll i = 0; i<k; i++){
        if(i != idx[s]) res[i] = mx;
    }
    cur.clear();
    set<ll> st;
    fo(n) st.insert(i+1);
    for(auto x: op[idx[s]]) st.erase(x);
    for(auto x: st) cur.pb(x);
    res[idx[s]] = qry(cur);
    if(res[idx[s]] == -1) return 0;
    cout<<"! "; fo(k) cout<<res[i]<<" "; nl;
    cout.flush();
    string verd;
    re verd;
    cout.flush();
    if(verd == "Incorrect"){
        return 0;
    }
    cout.flush();
    return 1;
}

int32_t main(){
    // KOBE;
    ll t;
    t = 1;
    re t;
    while(t--){
        ll k = solve();
        if(!k) return 0;
    }
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
