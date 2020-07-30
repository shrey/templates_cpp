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
        void topologicalSort(){
            int *indegree = new int[n];
            for(int i = 0; i<n; i++){
                indegree[i] = 0;
            }
            //update indegree by traversing
            for(auto x: adjlist){
                for(auto y: x.second){
                    indegree[y]++;
                }
            }
            //bfs and find 0 indegree nodes
            queue<int> q;
            for(int i = 0; i<n; i++){
                if(indegree[i] == 0){
                    q.push(i);
                    // cout<<i<<" ";
                }
            }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                cout<<node<<" ";
                //iterate over neighbours of node and reduce indegree
                for(auto neighbour: adjlist[node]){
                    indegree[neighbour]--;
                    if(indegree[neighbour] == 0){
                        q.push(neighbour);
                    }
                }
            }
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
    g.topologicalSort();
}
