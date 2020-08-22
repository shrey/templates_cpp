

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

class DSU{
    int *parent;
    int *rank;
    public:
        DSU(int n){
            parent = new int[n];
            rank = new int[n];
            fo(n){
                parent[i] = -1;
                rank[i] = 1;
            }
        }

        int find(int i){
            if(parent[i] == -1){
                return i;
            }
            parent[i] = find(parent[i]);
            return parent[i];
        }
        void unite(int a, int b){
            int s1 = find(a);
            int s2 = find(b);
            if(s1!=s2){
                if(rank[s1]<rank[s2]){
                    parent[s1] = s2;
                    rank[s2]+=rank[s1];
                }
                else{
                    parent[s2] = s1;
                    rank[s1]+=rank[s2];
                }
            }
        }
};

class Graph{
    vector<vector<int> > edgelist;
    int V;
    public:
        Graph(int V){
            this->V = V;
        }
        void addEdge(int x, int y, int w){
            vector<int> v(3);
            v[0] = w;
            v[1] = x;
            v[2] = y;
            edgelist.pb(v);
        }
        int kruskal_mst(){
            sort(edgelist.begin(), edgelist.end());
            int ans = 0;
            DSU s(V);
            for(auto edge: edgelist){
                int w = edge[0];
                int x = edge[1];
                int y = edge[2];
                //take that edge in mst if it's in diff components
                if(s.find(x)!=s.find(y)){
                    s.unite(x,y);
                    ans+=w;
                }
            }
            return ans;
        }
};

int main(){
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);
    cout<<g.kruskal_mst()<<endl;
}