

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
#define prDouble(x) cout<<fixed<<setprecision(15)<<x //to print decimal numbers
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
    umap<ll,ll> visited;
    public:
        void addEdge(ll x, ll y){
            gr[x].pb(y);
            gr[y].pb(x);
        }
        double dfs(ll src){
            bool leaf = true;
            visited[src] = true;
            double sum = 0;
            double children;
            for(auto x: gr[src]){
                if(!visited[x]){
                    sum+=dfs(x)+1;
                    leaf = false;
                    children++;
                }
            }
            if(leaf){
                return 0.0;
            }
            double ans = (sum*1.0/children);
            return ans;
        }
        void solve(){
            double ans = dfs(1);
            prDouble(ans);cout<<"\n";
        }
};

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin>>n;
    Graph g;
    fo(n-1){
        ll x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    g.solve();
}
