

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

const ll M = 3e5+100;
ll n,m,a[M][10];

ll i1 = 1, i2 = 1;
bool check(ll num){
    map<ll,ll> freq;
    for(ll i = 0; i<n; i++){
        ll cur = 0;
        for(ll j = 0; j<m; j++){
            if(a[i][j] >= num) cur |= (1<<j);
        }
        freq[cur] = i+1;
    }
    ll mx = (1<<m);
    // pr(mx);
    for(ll i = 0; i<=mx; i++){
        if(freq[i]){
            if(i == mx-1) return true;
            for(ll j = 0; j<=mx; j++){
                if((i | j) == mx-1 && i != j && freq[j]){
                    i1 = freq[i], i2 = freq[j];
                    return true;
                }
            }
        }
    }
    return false;
}

void solve(){
    re n; re m;
    forn(i,n){
        forn(j,m) re a[i][j];
    }
    ll s = 0, e = 1e9;
    ll ans = 0;
    while(s <= e){
        ll mid = (s+e)>>1;
        // cout<<s<<"()"<<e<<"\n";
        if(check(mid)){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    cout<<i1<<" "<<i2<<"\n";
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
