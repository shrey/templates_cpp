

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
ll n,m;
vl gr[2010];
vl side(2010,-1);

bool bpcheck(ll src){
    queue<ll> q;
    q.push(src);
    side[src] = 0;
    while(!q.empty()){
        ll par = q.front();
        q.pop();
        for(auto x: gr[par]){
            if(side[x] == -1){
                side[x] = side[par] ^ 1;
                q.push(x);
            }else{
                if(side[x] == side[par]){
                    return false;
                }
            }
        }
    }
    return true;
}

bool solve(){
    cin>>n>>m;
    fo(m){
        ll x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    for(ll i = 1; i<n; i++){
        if(side[i] == -1){
            if(!bpcheck(i)){
                return false;
            }
        }
    }
    return true;
}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    FOR(1,t){
        cout<<"Scenario #"<<i<<":\n";
        if(solve()){
            pr("No Suspicious bugs found!");
        }
        else{
            pr("Suspicious bugs found!");
        }
        for(ll i = 1; i<=n; i++){
            side[i] = -1;
            gr[i].clear();
        }
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
