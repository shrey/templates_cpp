

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


#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

class Graph{
    umap<int,list<int> > adjlist;
    umap<int,list<int> > rev;
    umap<int,vector<int> > components; //this is the real components broken down by kosaraju algo
    vector<int> order;
    umap<int,bool> visited;
    int n;
    public:
        Graph(int N){
            n = N;
        }
        void addedge(int x, int y){
            adjlist[x].pb(y);
            rev[y].pb(x);
        }
        void dfs(int src){
            if(visited[src]){
                return;
            }
            visited[src] = true;
            for(auto it: adjlist[src]){
                dfs(it);
            }
            order.pb(src);
        }
        void dfs_rev(int src, int col){
            if(visited[src]){
                return;
            }
            components[col].pb(src);
            visited[src] = true;
            for(auto it: rev[src]){
                dfs_rev(it,col);
            }
        }
        void solve(){
            for(int i = 1; i<=n; i++){
                dfs(i);
            }
            visited.clear();
            int col = 1;
            for(auto it: order){
                cout<<it<<" ";
            }
            for(int i = n; i>=1; i--){
                if(!visited[order[i-1]]){
                    dfs_rev(order[i-1],col);
                    col++;
                }
            }
            for(auto it: components){
                cout<<it.first<<" -> ";
                for(auto it2: it.second){
                    cout<<it2<<" , ";
                }cout<<endl;
            }

        }

};

int main(){
    int m,n;
    cin>>n>>m;
    Graph g(n);
    fo(m){
        int x,y;
        cin>>x>>y;
        g.addedge(x,y);
    }
    g.solve();
}
