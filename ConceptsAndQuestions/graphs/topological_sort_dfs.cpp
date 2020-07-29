

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
#define fo(x,y) for(int i = x; i<y; i++)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

class Graph{
    umap <int,list<int> > adjlist;
    umap<int,bool> visited;
    list<int> sorted_nums;
    int n;
    public:
        Graph(int N){
            n = N;
        }
        void addEdge(int x, int y){
            adjlist[x].pb(y);
        }
        void topological_sort(){
            for(int i = 1; i<=n; i++){
                dfs(i);
            }
            for(auto it: sorted_nums){
                cout<<it<<" ";
            }
        }
        void dfs(int src){
            if(visited[src]){
                return;
            }
            visited[src] = true;
            for(auto it: adjlist[src]){
                dfs(it);
            }
            sorted_nums.push_front(src);
        }
};

int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    int x,y;
    fo(0,m){
        cin>>x>>y;
        g.addEdge(x,y);
    }
    g.topological_sort();
}
