

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

const ll M = 2e5+100;
ll n,m,x,k,y, c[M],d[M];
ll mark[M] = {0};
ll idx[M];

void solve(){
    re n; re m;
    re x; re k; re y;
    memset(idx,-1,sizeof(idx));
    bool flag = true;
    fo(n){
        re c[i];
        idx[c[i]] = i;
    }
    vl op;
    op.pb(-1);
    fo(m){
        re d[i];
        mark[d[i]] = 1;
        if(idx[d[i]] == -1 || (i > 0 && idx[d[i-1]] > idx[d[i]])){
            flag = false;
        }
        op.pb(idx[d[i]]);
    }
    op.pb(n);
    // pr("here");
    // for(auto x: op) cout<<x<<" "; nl;
    if(!flag){
        pr(-1);
        return;
    }
    ll i = 0;
    ll ans = 0;
    while(i < op.size() - 1){
        ll a = op[i] == -1 ? 0 : c[op[i]];
        ll b = op[i+1] == n ? 0 : c[op[i+1]];
        ll cnt = op[i+1] - op[i] - 1;
        // cout<<a<<"()"<<b<<"()"<<cnt<<"\n";
        ll mx = 0;
        for(ll j = op[i]+1; j<op[i+1]; j++){
            mx = max(c[j],mx);
        }
        if(mx > max(a,b) && cnt < k){
            pr(-1);
            return;
        }
        if(mx > max(a,b)){
            ans += x;
            cnt-=k;
        }
        if(x <= k*y){
            ans += (cnt/k)*x + (cnt%k)*y;
        }else{
            ans += cnt*y;
        }
        i++;
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
