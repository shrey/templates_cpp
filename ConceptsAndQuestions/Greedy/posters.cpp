

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

const ll M = 1e5;

void solve(){
    ll n; re n;
    vp cur(n);
    map<ll,ll> cord;
    fo(n){
        re cur[i].ff; re cur[i].sec;
        cord[cur[i].ff]; cord[cur[i].sec];
    }
    ll crd = 1;
    for(auto x: cord){
        cord[x.ff] = crd++;
    }
    vp op;
    for(auto p: cur){
        op.pb(mp(cord[p.ff],cord[p.sec]));
    }
    map<ll,vl> oper;
    map<ll,ll> vis;
    ll ans = 0;
    ll curr = 1;
    for(auto p: op){
        // cout<<p.ff<<" , "<<p.sec<<"\n";
        oper[p.ff].pb(curr);
        oper[p.sec].pb(-1*curr);
        curr++;
    }
    set<ll,greater<ll> > s;
    for(ll i = 1; i<=M; i++){
        for(auto j: oper[i]){
            if(j>0){
                s.insert(j);
                // if(j == 8) cout<<"here = "<<i<<"\n";
            }
        }
        if(!s.empty() && !vis[*s.begin()]){
            // cout<<i<<"()"<<*s.begin()<<"\n";
            ans++;
            vis[*s.begin()] = 1;
        }
        for(auto j: oper[i]){
            if(j<0){
                s.erase(abs(j));
            }
        }
    }
    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    re t;
    // t = 1;
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
