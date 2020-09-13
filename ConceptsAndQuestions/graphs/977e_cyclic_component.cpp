

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
umap<ll,bool> visited;
bool ans = true;

void dfs(ll src){
    visited[src] = true;
    ll deg = gr[src].size();
    if(deg!=2) ans = false;
    for(auto x: gr[src]){
        if(!visited[x]) dfs(x);
    }
}

bool isCyclic(ll src){
    ans = true;
    dfs(src);
    return ans;
}

int main(){
    KOBE;
    ll n,m;
    cin>>n>>m;
    ll x,y;
    fo(m){
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    ll ans =0;
    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            // cout<<"("<<i<<endl;
            if(isCyclic(i)){
                // cout<<"()"<<i<<endl;
                ans++;
            }
        }
    }

    cout<<ans<<"\n";
}
