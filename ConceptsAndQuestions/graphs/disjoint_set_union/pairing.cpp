

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
    list<pair<int,int> > l;
    int V;
    public:
        Graph(int V){
            this->V = V;
        }
        void addEdge(int x, int y){
            l.pb(mp(x,y));
        }
        int findSet(int i, int parent[]){
            if(parent[i] == -1){
                return i;
            }
            parent[i] = findSet(parent[i],parent);
            return parent[i];
        }

        void union_set(int a, int b, int parent[], int rank[]){
            int s1 = findSet(a,parent);
            int s2 = findSet(b,parent);
                if(s1!=s2){
                    if(rank[s1]>rank[s2]){
                    parent[s2] = s1;
                    rank[s1]+=rank[s2];
                }
                else{
                    parent[s1] = s2;
                    rank[s2]+=rank[s1];
                }
            }

        }

        int ways(){
            int parent[V],rank[V];
            fo(V){
                parent[i] = -1;
                rank[i] = 1;
            }
            for(auto edge: l){
                union_set(edge.first,edge.second,parent,rank);
            }
            int ans = 0;
            for(int i = 0; i<V-1; i++){
                for(int j = i+1; j<V; j++){
                    if(findSet(i,parent)!=findSet(j,parent)){
                        ans++;
                    }
                }
            }
            // fo(V){
            //     cout<<parent[i]<<" ";
            // }cout<<endl;
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