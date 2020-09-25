

//Shrey Dubey

//Contact Me at wshrey09@gmail.com



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

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define ss second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define imax INT_MAX
#define lmax LLONG_MAX
#define vi vector<int>
#define vl vector<ll>
#define pr(t) cout<<t<<"\n"

ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

const ll M = 2e5+1;

vl gr[M];
ll n,m;
vl comp[M];
umap<ll,ll> comp_num;
ll cc = 0;
umap<ll,bool> visited;
ll maxNode, minNode;
void dfs(ll cur){
    visited[cur] = true;
    maxNode = max(maxNode,cur);
    minNode = min(minNode,cur);
    for(auto x: gr[cur]){
        if(!visited[x]){
            dfs(x);
        }
    }
}



ll solve(){
    vector<pair<ll,ll> > ipair;
    for(ll i = 1; i<=n; i++){
        if(!visited[i]){
            maxNode = i; minNode = i;
            dfs(i);
            ipair.pb(mp(minNode,maxNode));
        }
    }
    ll currEnd = -1;
    ll ans = 0;
    for(auto x: ipair){
        if(x.first<=currEnd){
            ans++;
        }
        currEnd = max(x.second,currEnd);
    }

    return ans;
}


int main(){
    KOBE;
    cin>>n>>m;
    fo(m){
        ll x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    cout<<solve()<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
