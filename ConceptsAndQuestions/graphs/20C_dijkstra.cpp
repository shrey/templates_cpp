

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

class Graph{
    umap<ll,list<pair<ll,ll> > > gr;
    int n;
    umap<ll,ll> parent;
    public:
        Graph(int N){n = N;}

        void addEdge(ll x, ll y, ll wt){
            gr[x].pb(mp(y,wt));
            gr[y].pb(mp(x,wt));
        }

        void printPath(ll src){
            if(src == 0){
                return;
            }
            printPath(parent[src]);
            cout<<src<<" ";
        }

        void dijkstra(ll src){
            umap<ll,ll> dist;
            fo(n+1) dist[i] =  LLONG_MAX;
            dist[src] = 0;
            set<pair<ll,ll> > s;
            parent[src] = 0;
            s.insert(mp(0,src));
            while(!s.empty()){
                auto p = *s.begin();
                ll distNode = p.first;
                ll node = p.second;
                // cout<<node<<" ";
                if(distNode == n){
                    break;
                }
                s.erase(s.begin());
                for(auto x: gr[node]){
                    if(distNode+x.second < (dist[x.first])){
                        ll dest = x.first;
                        auto f = s.find(mp(dist[dest],dest));
                        if(f!=s.end()){
                            s.erase(f);
                        }
                        dist[dest] = distNode+x.second;
                        s.insert(mp(dist[dest],dest));
                        parent[dest] = node;
                    }
                }
            }
            if(dist[n] == LLONG_MAX){
                cout<<-1<<"\n";
            }
            else{
                printPath(n);
                cout<<"\n";
            }


        }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    Graph g(n);
    fo(m){
        ll x,y,wt;
        cin>>x>>y>>wt;
        g.addEdge(x,y,wt);
    }
    g.dijkstra(1);
}