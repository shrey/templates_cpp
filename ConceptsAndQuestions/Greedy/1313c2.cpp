

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

const ll M = 5e5+100;
ll n,a[M];


vl st(4*M + 1);

ll query(ll v, ll tl, ll tr, ll l, ll r){
    if(tl > r || tr < l) return M-1;
    if(tl >= l && tr <= r) {
        // cout<<tl<<"()"<<tr<<"()"<<st[v]<<"\n";
        return st[v];
    }
    ll tm = (tl + tr)/2;
    ll i1 = query(2*v,tl,tm,l,r), i2 = query(2*v+1,tm+1,tr,l,r);
    ll ans = (a[i1] < a[i2]) ? i1 : i2;
    // cout<<tl<<"()"<<tr<<"()"<<i1<<"()"<<a[i2]<<"\n";
    return ans;

}

void build(ll v, ll tl, ll tr){
    if(tl == tr){
        st[v] = tl;
        return;
    }
    ll tm = (tl + tr)/2;
    build(2*v,tl,tm);
    build(2*v+1,tm+1,tr);
    st[v] = a[st[2*v]] < a[st[2*v+1]] ? st[2*v] : st[2*v+1]; // change here
}

ll recur(ll s, ll e){
    if(s > e) return 0;
    if(s == e) return a[s];
    // cout<<s<<"()"<<e<<"\n";
    ll minpos = query(1,0,n-1,s,e);

    // cout<<minpos<<"()\n";
    ll a1 = (minpos-s+1) * a[minpos] + recur(minpos + 1, e);
    ll a2 = (e-minpos+1) * a[minpos] + recur(s,minpos-1);
    // cout<<s<<"()"<<e<<" , "<<minpos<<"\n";
    if(a1 > a2){
        for(ll i = s; i<=minpos; i++) a[i] = a[minpos];
    }else{
        for(ll i = minpos; i<=e; i++) a[i] = a[minpos];
    }
    return max(a1,a2);
}


void solve(){
    re n;\
    a[M-1] = 1e15;
    fo(n) re a[i];
    build(1,0,n-1);
    (recur(0,n-1));
    fo(n) cout<<a[i]<<" ";nl;
    // pr(query(1,0,n-1,0,n-2));
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
