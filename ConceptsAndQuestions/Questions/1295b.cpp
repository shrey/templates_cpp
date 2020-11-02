

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
#define re(x) cin>>x
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

string s;
ll n,x,t;
const ll M = 2e5;
ll diff[M];
ll tot = 0;
bool ok(ll i){
    if(diff[i] == x){
        return true;
    }
    ll a = x-diff[i], b = tot;
    if((a>0 && b>0) || (a<0 && b<0)){
        a = abs(a); b = abs(b);
        if(a%b) return false;
        return true;
    }
    else{
        return false;
    }
}

void solve(){
    re(n); re(x);
    re(s);
    tot = 0;
    fo(s.length()){
        if(s[i] == '1'){
            tot--;
        }
        else{
            tot++;
        }
        diff[i] = tot;
    }
    if(tot == 0){
        fo(n){
            if(x == diff[i]){
                pr(-1);
                return;
            }
        }
        pr(0);
        return;
    }
    ll ans = 0;
    if(x == 0){
        ans++;
    }
    for(ll i = 0; i<n; i++){
        if(ok(i)) ans++;
    }
    pr(ans);
}

int32_t main(){
    KOBE;
    re(t);
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
