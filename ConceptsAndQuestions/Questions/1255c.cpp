

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
#include <array>

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

ll n,x,y,z;
vector<vl> q;
umap<ll,vl> pos;
umap<ll,ll> cnt;
umap<ll,bool> visited;
umap<ll,bool> psh;
vl ans;

void fill(ll i){
    if(i == n){
        return;
    }
    ll cur = ans[i];
    for(auto vec: pos[cur]){
        if(!visited[vec]){
            visited[vec] = true;
            for(auto x: q[vec]){
                if(!psh[x]){
                    ans.pb(x);
                    psh[x] = true;
                }
            }
        }
    }
    fill(i+1);
}

void solve(){
    ll fst;
    for(ll i = 1; i<=n; i++){
        if(cnt[i] == 1){
            fst = i;
            break;
        }
    }
    ans.pb(fst);
    psh[fst] = true;
    ll lst = pos[fst][0];
    visited[lst] = true;
    ll thr;
    for(auto x: q[lst]){
        if(!psh[x] && cnt[x] == 2){
            ans.pb(x);
            psh[x] = true;
        }
        else{
            if(!psh[x])thr = x;
        }
    }
    ans.pb(thr);
    psh[thr] = true;
    fill(1);
    for(auto x: ans){
        cout<<x<<" ";
    }nl;

}

int32_t main(){
    KOBE;
    cin>>n;
    fo(n-2){
        re(x); re(y); re(z);
        pos[x].pb(i);
        pos[y].pb(i);
        pos[z].pb(i);
        cnt[x]++;
        cnt[y]++;
        cnt[z]++;
        vl cur;
        cur.pb(x); cur.pb(y); cur.pb(z);
        q.pb(cur);
    }
    solve();
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
