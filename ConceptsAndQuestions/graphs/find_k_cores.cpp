

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
#define fs first
#define sc second

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

class Graph{
    umap<int,list<int> > adjlist;
    umap<int,bool> visited;
    umap<int,int> deg;
    int k = 3;
    int n;
    public:
        Graph(int N, int K){
            int n = N;
            int k = 3;
        }
        void addEdge(int x, int y){
            adjlist[x].pb(y);
            adjlist[y].pb(x);
        }

        bool dfs_until(int src){
            visited[src] = true;
            for(auto it: adjlist[src]){
                if(deg[src]<k){
                    deg[it]--;
                }
                if(!visited[it]){
                    if(dfs_until(it)){
                        deg[src]--;
                    }
                }
            }
            return (deg[src]<k);
        }
        void printDeg(){
            for(auto it: deg){
                cout<<it.first<<" "<<it.second<<endl;
            }
        }
        void solve(){
            for(auto it: adjlist){
                deg[it.first] = it.second.size();
            }
            int minDeg = INT_MAX;
            int start = 1;
            for(auto it: adjlist){
                if(deg[it.first]<minDeg){
                    minDeg = it.first;
                    start = it.first;
                }
            }
            dfs_until(start);
            for(auto it: adjlist){
                if(deg[it.fs]>=k){
                    cout<<it.first<<" -> ";
                    for(auto it2: it.sc){
                        if(deg[it2]>=k){
                            cout<<it2<<" ";
                        }
                    }cout<<endl;
                }
            }
        }

};

int main(){

    int k = 3;
    Graph g1(9,3);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.solve();

}