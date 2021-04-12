

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

const ll M = 1e5+100;
ll n,a,rt,m,h[M];

ll comp(ll num){
    ll res = 0;
    ll ex = 0, ls = 0;
    // cout<<num<<"(())\n";
    fo(n){
        if(h[i] > num){
            ex += (h[i]-num);
        }else{
            ls += (num - h[i]);
        }
    }
    if(a + rt < m){
        res += min(ex,ls) * (a+rt);
    }else{
        res += min(ex,ls) * m;
    }
    if(ls < ex){
        ex -= ls;
        ls = 0;
    }else{
        ls -= ex;
        ex = 0;
    }
    if(ex){
        res += rt*ex;
    }else if(ls){
        res += a*ls;
    }
    return res;
}


void solve(){
    re n; re a; re rt; re m;
    fo(n) re h[i];
    sort(h,h+n);
    ll m = 500;
    ld l,r;
    l = h[0];
    r = h[n-1];      //set the cnt here
    while (m--) {
        // cout<<l<<"()"<<r<<"\n";
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l) / 3;
        ld f1 = comp(m1);      //evaluates the function at m1
        ld f2 = comp(m2);      //evaluates the function at m2
        // cout<<m1<<" = "<<f1<<" "<<m2<<" = "<<f2<<"\n";
        //this is for finding minimum, for finding max, just make f1 > f2
        if (f1 < f2)
            r = m2;
        else
            l = m1;
    }
    // cout<<comp(l)<<"()"<<comp(r)<<"\n";
    // cout<<l<<"()"<<r<<"\n";
    pr(min(comp(l),comp(r)));
    // pr(comp(8));
    // cout<<l<<"()\n";
    // prDouble(l);nl;
    // pr(comp((ll)l));
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
// always check for n = 1 condition
// check loop starting and end points :(

//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
// try to find repeating pattern in matrices
