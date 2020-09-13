

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
    umap<ll,list<ll> > gr;
    umap<ll,ll> dist;
    umap<ll,ll> visited;
    ll n;
    public:
        Graph(ll N){n = N;}
        void addEdge(ll x, ll y){
            gr[x].pb(y);
            gr[y].pb(x);
        }
        void findDist(ll src){
            visited[src] = true;
            for(auto x: gr[src]){
                if(!visited[x]){
                    dist[x] = dist[src]+1;
                    findDist(x);
                }
            }
        }

        ll distAB(ll a, ll b){
            visited.clear();
            dist.clear();
            findDist(a);
            return dist[b];
        }
        ll computeDiameter(){
            findDist(1);
            ll farthestNode = 1;
            ll maxDist = 0;
            for(int i = 2; i<=n; i++){
                if(dist[i]>maxDist){
                    farthestNode = i;
                    maxDist = dist[i];
                }
            }
            // fo(n+1){
            //     cout<<dist[i]<<" ";
            // }
            visited.clear();
            dist.clear();
            findDist(farthestNode);
            maxDist = 0;
            for(int i = 1; i<=n; i++){
                if(dist[i]>maxDist){
                    maxDist = dist[i];
                }
            }
            return maxDist;

        }

};

bool compute(){
        ll n,a,b,da,db;

        cin>>n>>a>>b>>da>>db;
        Graph g(n);
        fo(n-1){
            ll x,y;
            cin>>x>>y;
            g.addEdge(x,y);
        }
        ll diam = g.computeDiameter();
        ll distAB = g.distAB(a,b);
        if(da>=distAB){
            return true;
        }
        if(2*da>=diam){
            return true;
        }
        if(2*da>=db){
            return true;
        }
        else{
            return false;
        }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        if(compute()){
            cout<<"Alice"<<"\n";
        }
        else{
            cout<<"Bob"<<"\n";
        }


    }
}
