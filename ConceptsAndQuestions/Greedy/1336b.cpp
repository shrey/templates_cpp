

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

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
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
#define pr(t) cout<<t<<"\n"
#define int long long
#define endl "\n"

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

ll ng,nr,nb;
const ll M = 2e5;


ll lwr(vl &v, ll num){
    if(num<v[0]) return v[0];
    if(num>v[v.size()-1]) return v[v.size()-1];
    ll ind = lower_bound(v.begin(),v.end(),num) - v.begin();
    if(v[ind] == num || ind == 0) return v[ind];
    else return v[ind-1];
}

ll upr(vl &v, ll num){
    if(num<v[0]) return v[0];
    if(num>v[v.size()-1]) return v[v.size()-1];
    ll ind = upper_bound(v.begin(),v.end(),num) - v.begin();
    if(ind>v.size()-1) ind = v.size()-1;
    return v[ind];
}

ll comp(ll x, ll y, ll z){
    ll ans = (x-y)*(x-y) + (z-y)*(z-y) + (x-z)*(x-z);
    return ans;
}



int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        cin>>nr>>ng>>nb;
        vl r(nr), b(nb), g(ng);
        fo(nr) cin>>r[i]; fo(ng) cin>>g[i]; fo(nb) cin>>b[i];
        sort(r.begin(),r.end());
        sort(g.begin(),g.end());
        sort(b.begin(),b.end());
        ll ans = lmax;
        for(ll i = 0; i<nr; i++){
            // cout<<r[i]<<" "<<lwr(g,r[i])<<" "<<upr(g,r[i])<<" "<<"()"<<lwr(b,r[i])<<" "<<upr(b,r[i])<<"\n";
            ll c1 = comp(r[i],lwr(b,r[i]),lwr(g,r[i]));
            ll c2 = comp(r[i],upr(b,r[i]),lwr(g,r[i]));
            ll c3 = comp(r[i],upr(b,r[i]),upr(g,r[i]));
            ll c4 = comp(r[i],lwr(b,r[i]),upr(g,r[i]));
            ans = min(ans,min(c1,min(c2,min(c3,c4))));
        }
        for(ll i = 0; i<ng; i++){
            // cout<<r[i]<<" "<<lwr(g,r[i])<<" "<<upr(g,r[i])<<" "<<"()"<<lwr(b,r[i])<<" "<<upr(b,r[i])<<"\n";
            ll c1 = comp(g[i],lwr(b,g[i]),lwr(r,g[i]));
            ll c2 = comp(g[i],upr(b,g[i]),lwr(r,g[i]));
            ll c3 = comp(g[i],upr(b,g[i]),upr(r,g[i]));
            ll c4 = comp(g[i],lwr(b,g[i]),upr(r,g[i]));
            ans = min(ans,min(c1,min(c2,min(c3,c4))));
        }
        for(ll i = 0; i<nb; i++){
            // cout<<r[i]<<" "<<lwr(g,r[i])<<" "<<upr(g,r[i])<<" "<<"()"<<lwr(b,r[i])<<" "<<upr(b,r[i])<<"\n";
            ll c1 = comp(b[i],lwr(r,b[i]),lwr(g,b[i]));
            ll c2 = comp(b[i],upr(r,b[i]),lwr(g,b[i]));
            ll c3 = comp(b[i],upr(r,b[i]),upr(g,b[i]));
            ll c4 = comp(b[i],lwr(r,b[i]),upr(g,b[i]));
            ans = min(ans,min(c1,min(c2,min(c3,c4))));
        }
        cout<<ans<<"\n";
    }
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
