

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


#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)


using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

const ll M = 2e5+1;
vector<ll> gr[M];
ll n,m;

double e = 0, v = 0;

vector<ll> edges(M,0);
umap<ll,bool> visited;
void dfs(ll src){
    visited[src] = true;
    // cout<<src<<" = "<<edges[src]<<endl;
    edges[src]+=(gr[src].size());
    e+=edges[src];
    v++;
    for(auto x: gr[src]){
        if(!visited[x]){
            edges[x]--;
        }
    }
    for(auto x: gr[src]){
        if(!visited[x]){
            dfs(x);
        }
    }
}

bool solve(){
    for(ll i = 1; i<=n; i++){
        e = 0; v = 0;
        if(!visited[i]){
            dfs(i);
            if(e != (v*(v-1)/2)){
                // cout<<e<<" "<<v<<endl;
                return false;
            }
        }
    }
    return true;
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
    if(solve()){
        YES;
    }
    else{
        NO;
    }
}
