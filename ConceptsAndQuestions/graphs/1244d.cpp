

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
ll c[4][M],n,x,y;
vl gr[M];
ll dp[M][4][4];
vb visited(M,false);
umap<ll,ll> mark;

ll dfs(ll cur, ll p1col, ll p2col, ll par){
    // cout<<cur<<"()"<<p1col<<"()"<<p2col<<endl;
    // visited[cur] = true;
    if(dp[cur][p1col][p2col] != -1){
        // pr("here");
        return dp[cur][p1col][p2col];
    }
    ll ans = 1e15;
    if(gr[cur].size() == 1 && par!=0){
        for(ll i = 1; i<=3; i++){
            if(i!=p1col && i!=p2col) ans = min(ans,c[i][cur]);
        }
    }
    for(auto x : gr[cur]){
        if(x!=par){
            for(ll i = 1; i<=3; i++){
                if(i!=p1col && i!=p2col){
                    ll temp = c[i][cur] + dfs(x,i,p1col,cur);
                    if(ans>temp){
                        ans = temp;
                        mark[cur] = i;
                    }
                }
            }
        }
    }
    dp[cur][p1col][p2col] = ans;
    return ans;
}

void dfs_assign(ll cur, ll p1col, ll p2col, ll par){
    for(ll i = 1; i<=3; i++){
        if(i!=p1col && i!=p2col){
            mark[cur] = i;
        }
    }
    for(auto x: gr[cur]){
        if(x!=par){
            dfs_assign(x,mark[cur],p1col,cur);
        }
    }
}

void solve(){
    memset(dp,-1,sizeof(dp));
    re n;
    fo(n) re c[1][i+1];
    fo(n) re c[2][i+1];
    fo(n) re c[3][i+1];
    fo(n-1){
        re x; re y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    ll st;
    for(ll i = 1; i<=n; i++){
        if(gr[i].size()>2){
            pr(-1);
            return;
        }
        if(gr[i].size() == 1){
            st = i;
        }
    }
    pr(dfs(st,0,0,0));
    ll node = gr[st][0];
    ll val = 1e15;
    ll ans = 1e15;
    ll col2;
    ll node2;
    for(auto x: gr[node]){
        if(x!=st) node2 = x;
    }
    for(ll i = 1; i<=3; i++){
        if(i == mark[st]) continue;
        ll cur = dp[node2][i][mark[st]] + c[i][node];
        if(cur<ans){
            col2 = i;
            ans = cur;
        }
    }
    mark[node] = col2;
    dfs_assign(node2,mark[node],mark[st],node);
    for(ll i = 1; i<=n; i++){
        cout<<mark[i]<<" ";
    }nl;
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
