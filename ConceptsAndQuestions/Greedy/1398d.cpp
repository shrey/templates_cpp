

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
#define vs vector<string>
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

ll n,k;
ll l1,r1,l2,r2;

void solve(){
    re n; re k;
    re l1; re r1; re l2; re r2;
    ll ans = 0;
    ll mv = 0;
    ll tot = 0;
    ll cur = 0;
    if(l2 > r1 || l1 > r2){
        if(l1 > r2){
            swap(l1,l2); swap(r1,r2);
        }
        mv = l2-r1;
        r1 = l2;
    }
    else{
        ll op = min(r2-l2,min(r1-l1,min(r1-l2,r2-l1)));
        tot += n*op;
        cur = op;
    }
    // cout<<tot<<"()"<<cur<<"\n";
    // cout<<l1<<"()"<<r1<<"\n";
    // cout<<l2<<"()"<<r2<<"\n";
    // cout<<mv<<"()\n";
    ans += mv;
    if(tot < k){
        ll d = min(k-tot,(max(r2,r1)-min(l1,l2))-cur);
        ll inc = (max(r2,r1)-min(l1,l2))-cur;
        ans += d;
        tot += d;
        // cout<<ans<<"()"<<tot<<"\n";
        bool f = false;
        if(n == 1) f = true;
        if(tot < k){
            for(ll i = 2; i<=n; i++){

                if(tot + inc <= k && 2*inc > mv+inc){
                    // cout<<i<<"()"<<inc<<"()"<<tot<<"\n";
                    tot += inc;
                    ans += mv+inc;
                    if(i == n) f = true;
                }else{
                    break;
                }
            }
            // cout<<tot<<"()"<<ans<<"\n";
            if(tot < k){
                if(f || (2*(k-tot) <= mv + (k-tot)) || inc < (k-tot)){
                    ans += 2*(k-tot);
                    tot = k;
                }else{
                    ans += mv+(k-tot);
                    tot = k;
                }
            }
        }
    }
    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    t = 1;
    re t;
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
