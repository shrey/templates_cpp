

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

class Graph{
    umap<int,list<pair<int, int > > > adjlist;
    int longest = INT_MIN;
    umap<int,bool>visited;
    vector<int> path;
    public:
        void addEdge(int x, int y, int wt){
            adjlist[x].pb(mp(y,wt));
            adjlist[y].pb(mp(x,wt));
        }
        void dfs_longest(int src, int len, vector<int> &paths){
            visited[src] = true;
            // cout<<src<<" ";
            for(auto it: adjlist[src]){
                // cout<<it.first<<endl;
                auto p = it.second;
                if(!visited[it.first]){
                    paths.pb(it.first);
                    if((len+it.second)>longest){
                        longest = len+it.second;
                        path = paths;
                    }
                    dfs_longest(it.first,len+it.second, paths);
                    paths.pop_back();
                }
            }
            visited[src] = false;
        }

        void solve(int src){
            vector<int> p;
            p.pb(0);
            dfs_longest(src,0,p);
            cout<<longest<<endl;
            fo(path.size()){
                cout<<path[i]<<" ";
            }
        }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.solve(0);
}