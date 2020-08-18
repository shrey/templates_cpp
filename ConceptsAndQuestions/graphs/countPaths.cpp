

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

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

class Graph{
    umap<int,list<int> > adjlist;
    umap<int,int> path;

    public:
        void addEdge(int x, int y){
            adjlist[x].pb(y);
        }
        void dfs_helper(int src){
            if(path[src]){
                return;
            }
            int ans = 0;
            for(auto it: adjlist[src]){
                dfs_helper(it);
                ans+=path[it];
            }
            path[src] = ans;
        }
        void solve(int s, int e){
            path[e] = 1;
            dfs_helper(s);
            cout<<path[s]<<endl;
        }


};

int main()
{

    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    int s,e;
    cin>>s>>e;
    g.solve(s,e);

    return 0;
}