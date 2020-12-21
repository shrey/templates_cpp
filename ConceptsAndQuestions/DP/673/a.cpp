

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
ll row[M] = {0};
ll col[M] = {0};

vl gr[M];

bool visited[M] = {false};
bool mark[M] = {false};

ll flag = 1;

void dfs(ll cur){
    visited[cur] = 1;

    for(auto x: gr[cur]){
        if(!visited[x]) dfs(x);
    }
}

void fix(ll cur){
    if(col[cur] == 0) return;
    // cout<<"()"<<cur<<"\n";
    ll temp = row[cur];
    col[cur] = 0;
    cur = temp;
    fix(temp);
}

void solve(){
    ll n,m,r,c;
    re n; re m;
    vp op; vp nop;
    ll cnt = 0;
    fo(m){
        re r; re c;
        if(r == c) continue;
        row[r] = c;
        op.pb(mp(r,c));
        col[c] = r;
        cnt++;
    }
    // for(auto p: op){
    //     if(!row[op.sec]){

    //     }
    // }
    for(ll i = 1; i<=n; i++){
        if(row[i] && !col[i]){
            // cout<<i<<"\n";
            // cout<<row[i]<<"()\n";
            fix(row[i]);
        }
    }

    for(auto p: op){
        if(row[p.ff] && col[p.sec]){
            gr[p.ff].pb(p.sec);
            gr[p.sec].pb(p.ff);
            mark[p.ff] = 1;
            mark[p.sec] = 1;

        }
    }
    ll cc = 0;
    for(ll i = 1; i<=n; i++){
        if(mark[i] && !visited[i]){
            // cout<<i<<"()\n";
            dfs(i);
            cc++;
        }
    }
    // cout<<cc<<"\n";
    ll ans = cnt + cc;
    pr(ans);
    for(ll i = 0; i<=n; i++){
        visited[i] = false;
        gr[i].clear();
        mark[i] = false;
        row[i] = 0;
        col[i] = 0;
    }
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
