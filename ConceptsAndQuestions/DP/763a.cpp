

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
#define int long long
ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll n,x,y;
const ll M = 1e5+5;
umap<ll,bool> good;
umap<ll,bool> visited;
vl gr[M];
ll c[M];
bool possible = false;

bool dfs(ll curr, ll par, ll col){
    for(auto x: gr[curr]){
        if(x!=par && (c[x]!=col || (!dfs(x,curr,col)))) return false;
    }
    return true;
}


bool comp(ll i){
    for(auto x: gr[i]){
        if(!dfs(x,i,c[x])) return false;
    }
    return true;
}

ll ans = -1;
bool solve(){
    bool flag = true;
    for(ll i = 1; i<=n; i++){
        for(auto x: gr[i]){
            if(c[x]!=c[i]){
                flag = false;
                // cout<<i<<" _ "<<c1<<" () "<<x<<" _ "<<c2<<"\n";
                if(comp(i)){
                    ans = i;
                    // cout<<i<<endl;
                    return true;
                }
                if(comp(x)){
                    ans = x;
                    // cout<<x<<endl;
                    return true;
                }
            }
        }
    }
    if(flag) return true;
    return false;
}

int32_t main(){
    KOBE;
    cin>>n;
    fo(n-1){
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    fo(n) cin>>c[i+1];
    // cout<<"here";
    if(solve()){
        YES;
        if(ans == -1){
            cout<<1<<"\n";
        }
        else{
            cout<<ans<<"\n";
        }
    }else{
        NO;
    }

}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
