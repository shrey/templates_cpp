

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

ll n,m,t,a,b;

vp inc; vp decr;
ll val[1010];

bool ok(ll s, ll e){
    for(ll i = s+1; i<=e; i++){
        if(val[i-1]>val[i]) return false;
    }
    return true;
}

void solve(){
    re n; re m;
    fo(m){
        re t; re a; re b;
        if(t == 1) inc.pb(mp(a,b));
        else decr.pb(mp(a,b));
    }
    ll arr[1010];
    fo(1010) arr[i] = -1;
    ll cur = 1;
    fo(inc.size()){
        ll grp = -1;
        ll s = inc[i].ff, e = inc[i].sec;
        for(ll j = s; j<=e; j++){
            if(arr[j] != -1){
                grp = arr[j];
                break;
            }
        }
        if(grp == -1){
            grp = cur;
            cur++;
        }
        else{
            while(s>0 && arr[s-1] == arr[s] && arr[s]!=-1){
                s--;
            }
            while(e<n-1 && arr[e] == arr[e+1] && arr[e] != -1){
                e++;
            }
        }
        for(ll j = s; j<=e; j++){
            arr[j] = grp;
        }
    }
    fo(n+1) val[i] = 1000;
    sort(decr.begin(),decr.end());
    fo(decr.size()){
        ll s = decr[i].ff, e = decr[i].sec;
        if(!ok(s,e)) continue;
        bool flag = false;
        for(ll i = s+1; i<=e; i++){
            if(arr[i] != arr[i-1] || arr[i] == -1){
                val[i] = val[i-1]-1;
                flag = true;
                break;
            }
        }
        if(!flag){
            NO;
            return;
        }
    }
    // for(ll i = 1; i<=n; i++){
    //     cout<<arr[i]<<" ";
    // }nl;
    YES;
    for(ll i = 1; i<=n; i++){
        cout<<val[i]<<" ";
    }nl;
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
