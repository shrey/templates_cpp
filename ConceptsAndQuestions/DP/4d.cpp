


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

struct env{
    ll h,w;
    bool operator<(const env& t) const
    {
        return (this->h<t.h);
    }
};

const ll M = 5010;
env e[M];
ll n,h,w;

bool compare(env &a, env &b){
    return (a.h<b.h);
}

bool ok(env &a){
    if(a.h>h && a.w>w) return true;
    return false;
}

bool sm(env &a, env &b){
    if(b.h>a.h && b.w>a.w) return true;
    return false;
}

map<pair<ll,ll>,ll> pos;

int32_t main(){
    KOBE;
    cin>>n>>w>>h;
    fo(n){
        cin>>e[i].w>>e[i].h;
        pos[mp(e[i].h,e[i].w)] = i;
    }
    sort(e,e+n,compare);
    // lis approach
    ll dp[M] = {0};
    ll ans = 0;
    for(ll i = 0; i<n; i++){
        if(ok(e[i])) dp[i] = 1;
        else continue;
        for(ll j = 0; j<i; j++){
            if(sm(e[j],e[i]) && ok(e[j])){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    if(ans == 0) return 0;
    vl res;
    ll ind;
    fo(n){
        if(dp[i] == ans){
            ind = i;
            break;
        }
    }
    res.pb(pos[mp(e[ind].h,e[ind].w)]);
    ans--;
    for(ll i = ind-1; i>=0 && ans>0; i--){
        if(dp[i] == ans && sm(e[i],e[ind])){
            res.pb(pos[mp(e[i].h,e[i].w)]);
            ind = i;
            ans--;
        }
        if(ans<=0) break;
    }
    reverse(res.begin(),res.end());
    fo(res.size()) cout<<res[i]+1<<" ";cout<<"\n";
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