

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

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

//there should be no negative edge cycle

//there are at most v-1 edges in our path

//v or more edges means repeated


class Graph{
    map<pair<int,int> , int > edges;
    int v,e;
    public:
        Graph(int V, int E){
            v = V; e = E;
        }
        void addEdge(int x, int y, int wt){
            edges[mp(x,y)] = wt;
        }
        void bellman_ford(int src){
            int dist[v+1];
            for(int i = 0; i<=v; i++){
                dist[i] = INT_MAX;
            }
            dist[src] = 0;
            for(int i = 1; i<=v-1; i++){
                for(auto j: edges){
                    int u = j.first.first;
                    int v = j.first.second;
                    int wt = j.second;
                    if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                        dist[v] = dist[u]+wt;
                    }
                }
            }
            for(auto e: edges){
                int u = e.first.first;
                int v = e.first.second;
                if(dist[u]!=INT_MAX && dist[u]+e.second<dist[v]){
                    cout<<"Negative wt cycle"<<"\n";
                    return;
                }
            }
            for(int i = 1; i<=v; i++){
                cout<<"Distance of "<<i<<" from "<<src<<" is: "<<dist[i]<<"\n";
            }
        }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int v,e;
    cin>>v>>e;
    Graph g(v,e);
    fo(e){
        int x,y,wt;
        cin>>x>>y>>wt;
        g.addEdge(x,y,wt);
    }
    g.bellman_ford(1);
}
