

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
#define read(a) cin>>a;

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

ll tc;
ld h,c,t;

ld eqn(ld x){
    return (ld)(((h-c)*x)/(2*x+1));
}

ld tempCal(ld k){
    ld op = (ld) k;
    ld ans = (ld)((op+1)*h + op*c)/(2*op+1);
    return ans;
}

void solve(){
    cin>>h>>c>>t;
    ld avg = (h+c)/2;
    // if(t == c || t == h){
    //     pr(1);
    //     return;
    // }
    if(t<=avg){
        pr(2);
        return;
    }
    ld k1 = flr(((t-h)/(h+c-2*t)));
    ld k2 = k1+1;
    // cout<<k1<<"()"<<k2<<"\n";
    ld t1 = tempCal(k1);
    ld t2 = tempCal(k2);
    ll ans;
    // cout<<t2<<" "<<t1<<"\n";
    if(abs(t-t1)<abs(t-t2)){
        ans = k1;
    }
    else if(abs(t-t1)>abs(t-t2)){
        ans = k2;
    }
    else{
        ans = min(k1,k2);
    }
    cout<<2*ans+1<<"\n";
}

int32_t main(){
    KOBE;
    read(tc);
    while(tc--) solve();
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
