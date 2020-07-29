

//shrey dubey



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
    unordered_map<int,list<int> > adjList;
    int min_cycle = INT_MAX;
    int n;
    public:
        Graph(int N){
            n = N;
        }

        void addEdge(int x,int y){
            adjList[x].pb(y);
            adjList[y].pb(x);
        }

        int find_shortest(){
            for(int i = 1; i<=n; i++){
                bfs(i);
            }
            return min_cycle;
        }

        void bfs(int src){
            umap<int,bool> visited;
            umap<int,int> distance;
            umap<int,int> father;
            visited[src] = true;
            father[src] = 0;
            queue<int>q;
            q.push(src);
            distance[src] = 0;
            while(!q.empty()){
                int parent = q.front();
                q.pop();
                for(auto child: adjList[parent]){
                    if(!visited[child]){
                        q.push(child);
                        visited[child] = true;
                        distance[child] = distance[parent] + 1;
                        father[child] = parent;
                    }
                    else if(visited[child] && father[parent]!=child){
                        //back edge found
                        int cycle_length = distance[child] + distance[parent] + 1;
                        if(cycle_length<min_cycle){
                            min_cycle = cycle_length;
                            // cout<<min_cycle<<endl;
                        }
                    }
                }
            }
        }

};

int main(){
    int n,m;
    cin>>n>>m;
    Graph g(n);
    fo(0,m){
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    cout<<g.find_shortest()<<endl;
}
