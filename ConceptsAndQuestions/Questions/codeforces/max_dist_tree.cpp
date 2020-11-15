

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
    int N;
    umap<int,int> nodeCount;
    umap<int,bool> visited;
    vector<int> nodeSides;
    public:
        Graph(int n){
            N = n;
        }
        void addEdge(int x, int y){
            adjlist[x].pb(y);
            adjlist[y].pb(x);
        }
        int count(int src){
            nodeCount[src] += 1;
            visited[src] = true;
            for(auto it: adjlist[src]){
                if(!visited[it]){
                    nodeCount[src]+=count(it);
                }
            }
            return nodeCount[src];
        }
        void traverse(int src){
            visited[src] = true;
            for(auto it: adjlist[src]){
                if(!visited[it]){
                    nodeSides.push_back(nodeCount[it]*(N-nodeCount[it]));
                    traverse(it);
                }
            }
        }
        void solve(int p[], int k){
            count(1);
            visited.clear();
            traverse(1);
            int ans = 0;
            sort(nodeSides.begin(), nodeSides.end(),greater<int>());
            sort(p,p+k,greater<int>());
            int j = 0;
            if(k>(N-1)){
                while((k-j)>(N-1)){
                    ans+=nodeSides[0]*p[j];
                    j++;
                }
            }
            
        }       
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Graph g(n);
        int x,y;
        fo(n-1){
            cin>>x>>y;
            g.addEdge(x,y);
        }

    }
}