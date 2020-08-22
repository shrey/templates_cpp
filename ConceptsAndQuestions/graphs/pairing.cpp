

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
    umap<int,list<int> > adjlist;
    umap<int,int> setNo;
    umap<int,bool> visited;
    int V;
    public:
        Graph(int V){
            this->V = V;
        }
        void addEdge(int x, int y){
            adjlist[x].pb(y);
        }
        void dfs(int src, int sno){
            visited[src] = true;
            setNo[src] = sno;
            for(auto it: adjlist[src]){
                if(!visited[it]) dfs(it,sno);
            }
        }
        int ways(){
            fo(V){
                setNo[i] = i;
            }
            for(int i = 0; i<V; i++){
                if(!visited[i]){
                    dfs(i,i);
                }
            }
            int ans = 0;
            for(int i = 0; i<V-1; i++){
                for(int j = i+1; j<V; j++){
                    if(setNo[i]!=setNo[j]){
                        ans++;
                    }
                }
            }
            return ans;
        }

};

int main(){
    int n, e;
    cin>>n>>e;
    Graph g(n);
    fo(e){
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    cout<<g.ways()<<endl;
}