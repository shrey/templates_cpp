

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

const ll M = 4e5+100;
ll d[2*M],n,x,b[2*M],c[2*M];

ll sm(ll num){
    return (num*(num+1)/2);
}

void solve(){
    re n; re x;
    fo(n){
        re d[i];
        d[n+i] = d[i];
    }
    b[0] = (d[0]*(d[0]+1))/2; //hugs
    c[0] = d[0]; //days passed
    n*=2;
    fo(n){
        b[i] = d[i]*(d[i]+1)/2;
    }
    for(ll i = 1; i<n; i++){
        b[i] += b[i-1];
        c[i] = c[i-1] + d[i];
    }
    ll s = 0, e = 0;
    while(e<n && c[e]<x) e++;
    ll ans = 0;
    while(1){
        if(e == n) break;
        ll hugs = b[e] - b[s];
        ll days = x - (c[e]-c[s]);
        if(days<0){
            s++;
            continue;
        }
        hugs += (sm(d[s]) - sm(d[s]-days));
        ans = max(ans,hugs);
        e++;
        if(c[e]-c[s]>=x){
            s++;
        }
    }
    pr(ans);
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
