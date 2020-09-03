

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



#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map
#define mp make_pair

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

const int N = 100005;

//articulation points and bridges are points which on removing increase the number of connected components

vector<int> gr[N];
int low[N], disc[N], tme = 0; //discovery time and lowest time
vector<bool> visited(N, false);
set<int> art_p;
vector<pair<int,int> > bridge;
void dfs(int cur, int par){
    visited[cur] = true;
    low[cur] = disc[cur] = tme++;
    int no_child = 0;
    for(auto x: gr[cur]){
        if(!visited[x]){
            dfs(x,cur);
            no_child++;
            low[cur] = min(low[cur],low[x]);
            //articulation point if low[x]>=disc[cur]
            if(par!=0 && low[x]>=disc[cur]){
                art_p.insert(cur);
            }
            if(low[x]>disc[cur]){
                bridge.pb(mp(cur,x));
            }
        }
        else if(x!=par){
            //back edge cycle
            low[cur] = min(low[cur],disc[x]);
        }
    }
    if(par == 0 && no_child>=2){
        art_p.insert(cur);
    }
    return;
}

void solve(){
    int n,m,x,y;
    cin>>n>>m;
    fo(m){
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    dfs(1,0);
    for(auto it: art_p){
        cout<<it<<" ";
    }cout<<endl;
    for(auto it: bridge){
        cout<<it.first<<" , "<<it.second<<endl;
    }
}

int main(){
    solve();
}
/*
5 5
1 2
2 3
3 1
3 4
4 5
*/