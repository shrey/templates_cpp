

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

const ll M = 1e5+100;
ll a[M],n;
vl bt[65];

void comp(ll num, ll ind){
    ll pos = 0;
    ll mask = 1;
    while(mask <= num && pos < 64){
        if((num & (mask)) != 0) bt[pos].pb(ind);
        pos++;
        mask *= 2;
    }
}

vl gr[M];

ll cyc(ll src){
    vb visited(n+1,false);
    vl dist(n+1,0);
    vl par(n+1,-1);
    ll ans = 1e15;
    queue<ll> q;
    q.push(src);
    visited[src] = true;
    par[src] = 0;
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        for(auto x: gr[cur]){
            if(!visited[x]){
                dist[x] = dist[cur] + 1;
                visited[x] = true;
                par[x] = cur;
                q.push(x);
            }
            else if(par[cur] != x && par[x] != cur){
                ans = min(ans,dist[x] + dist[cur] + 1);
                // cout<<cur<<"()"<<x<<"\n";
            }
        }
    }
    return ans;
}

void solve(){
    re n;
    fo(n){
        re a[i];
        comp(a[i],i+1);
    }
    map<pair<ll,ll>,bool> edge;
    fo(64){
        // cout<<i<<"()"<<bt[i].size()<<"\n";
        if(bt[i].size() > 2){
            // cout<<i<<"\n";
            pr(3); return;
        }
        if(bt[i].size() <= 1) continue;
        ll x = bt[i][0], y = bt[i][1];
        if(edge[mp(x,y)]) continue;
        gr[x].pb(y); gr[y].pb(x);
        edge[mp(x,y)] = true;
        edge[mp(y,x)] = true;
    }

    ll ans = 1e15;
    fo(n){
        if(a[i] == 0) continue;
        ans = min(ans,cyc(i+1));
    }
    ans = (ans == 1e15) ? -1 : ans;
    pr(ans);
}

int32_t main(){
    KOBE;
    ll t;
    // re t;
    t = 1;
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
