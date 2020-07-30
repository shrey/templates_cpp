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
};