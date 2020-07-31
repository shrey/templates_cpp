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
#define fo(x,y) for(int i = x; i<y; i++)
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

class Graph{
    umap <int,list<int> > adjlist;
    umap<int,bool> visited;
    list<int> sorted_nums;
    umap<int,bool> node_stack;
    bool is_cyclic = false;
    int n;
    public:
        Graph(int N){
            n = N;
        }
        void addEdge(int x, int y){
            adjlist[x].pb(y);
        }
        //do dfs, if repeated el occurs and check if it already it exists in the stack
        void dfs(int src){
            if(visited[src]){
                if(node_stack[src]){
                    is_cyclic = true;
                }
                return;
            }
            node_stack[src] = true;
            for(auto it: adjlist[src]){
                dfs(it);
                if(is_cyclic){
                    return;
                }
            }
            node_stack[src] = false;
        }
        void ans(){
            if(is_cyclic){
                cout<<"CYCLIC"<<endl;
            }
            else{
                cout<<"no"<<endl;
            }
        }
};

int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    int x,y;
    fo(m){
        cin>>x>>y;
        g.addEdge(x,y);


    }
    g.dfs(0);
    g.ans();
}
