

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
    int V;
    list<pair<int,int> > l;
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
            parent[i] = findSet(parent[i],parent); //path compression
            return parent[i];
        }
        void union_set(int a, int b, int parent[], int rank[]){
            int s1 = findSet(a,parent);
            int s2 = findSet(b,parent);
            if(s1!=s2){
                if(rank[s1]<rank[s2]){//union by rank(size)s
                    parent[s1] = s2;
                    rank[s2]+=rank[s1];
                }
                else{
                    parent[s2] = s1;
                    rank[s1]+=rank[s2];
                }
            }
        }
        bool contains_cycle(){
            int parent[V+1];
            int rank[V+1];
            fo(V+1){
                parent[i] = -1;
                rank[i] = 1;
            }
            for(auto edge: l){
                int i = edge.first;
                int j = edge.second;

                int s1 = findSet(i,parent);
                int s2 = findSet(j,parent);
                if(s1!=s2){
                    union_set(s1,s2,parent,rank);
                }
                else{
                    cout<<"Same Parents "<<i<<" "<<j<<endl;
                    return true;
                }
            }
            return false;
        }
};

int main(){
    Graph g(4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,1);
    if(g.contains_cycle()){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}