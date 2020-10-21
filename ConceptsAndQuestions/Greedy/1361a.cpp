

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

const ll M = 6e5;
vl gr[M];
vl col[M];
ll n,m;
ll t[M];
bool possible = true;
vl visited(M,0);

bool check(ll v, ll clr){
    set<ll> s;
    for(auto x: gr[v]){
        if(visited[x] && t[x] == clr){
            return false;
        }
        else if(visited[x] && t[x]<clr){
            s.insert(t[x]);
        }
    }
    if(s.size() == clr-1){
        return true;
    }
    return false;
}

void solve(){
    for(ll i = 1; i<=n; i++){
        for(auto v: col[i]){
            if(check(v,i)){
                visited[v] = true;
            }
            else{
                pr(-1);
                return;
            }
        }
    }
    vp res;
    for(ll i = 1; i<=n; i++){
        res.pb(mp(t[i],i));
    }
    sort(res.begin(),res.end());
    for(auto p: res){
        cout<<p.sec<<" ";
    }cout<<"\n";
}

int32_t main(){
    KOBE;
    cin>>n>>m;
    fo(m){
        ll x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    for(ll i = 1; i<=n; i++){
        cin>>t[i];
        col[t[i]].pb(i);
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
