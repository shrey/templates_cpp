

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

ll m = 998244353;

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

ll n;
const ll M = 3e5+100;
ll fac[M] = {0};

void comp(){
    fac[0] = 1;
    for(ll i = 1; i<M; i++){
        fac[i] = fac[i-1] * i;
        fac[i] %= m;
    }
}

bool compare(pll &a, pll &b){
    if(a.sec == b.sec){
        return a.ff < b.ff;
    }
    return a.sec < b.sec;
}

void disp(vp &p){
    fo(n) cout<<p[i].ff<<" , "<<p[i].sec<<"\n";
}

void solve(){
    re n;
    vp p(n);
    fo(n){
        re p[i].ff; re p[i].sec;
    }
    sort(p.begin(),p.end());
    ll a = 1, b = 0, c = 0;
    ll cur = 0;
    bool flag = true;
    for(ll i = 0; i<n; i++){
        if(i == 0){
            cur++; continue;
        }
        if(p[i].ff == p[i-1].ff){
            cur++;
        }else{
            a *= fac[cur];
            a %= m;
            cur = 1;
        }
        if(p[i-1].sec > p[i].sec) flag = false;
    }
    a*=fac[cur]; a%=m;
    if(flag){
        b = 1; cur = 0;
        for(ll i = 0; i<n; i++){
            if(i == 0){
                cur++; continue;
            }
            if(p[i].sec == p[i-1].sec && p[i].ff == p[i-1].ff) cur++;
            else{
                b *= fac[cur]; b%=m;
                cur = 1;
            }
        }
        b*=fac[cur]; b%=m;
    }
    sort(p.begin(),p.end(),compare);
    cur = 0;
    c = 1;
    for(ll i = 0; i<n; i++){
        if(i == 0){
            cur++; continue;
        }
        if(p[i].sec == p[i-1].sec) cur++;
        else{
            c *= fac[cur]; c%=m;
            cur = 1;
        }
    }
    c*=fac[cur]; c%=m;
    // disp(p);
    // cout<<a<<"()"<<b<<"()"<<c<<"\n";
    ll op = (a + c - b + m)%m;
    ll ans = (fac[n] - op + m)%m;
    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    // re t;
    comp();
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
