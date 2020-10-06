

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

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define ss second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define imax INT_MAX
#define lmax LLONG_MAX
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define pr(t) cout<<t<<"\n"
#define int long long
ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll n,m;



int32_t main(){
    KOBE;
    cin>>n>>m;
    vp pos(n),lt(m);
    fo(n){
        cin>>pos[i].ff>>pos[i].ss;
    }
    fo(m) cin>>lt[i].ff>>lt[i].ss;
    vp all;
    for(auto p: pos){
        for(auto l: lt){
            if(p.ff<=l.ff && p.ss<=l.ss){
                all.pb(mp(l.ff-p.ff,l.ss-p.ss));
            }
        }
    }
    sort(all.rbegin(),all.rend());
    if(all.empty()){
        cout<<"0\n";
        return 0;
    }
    ll ans = imax;
    ll curr = -1;
    for(auto a: all){
        ans = min(ans,a.ff + 1 + curr + 1);
        curr = max(curr,a.ss);
    }
    ans = min(ans,curr+1);
    cout<<ans<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
