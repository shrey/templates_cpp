

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
const ll modulo = 1e9 + 7;

class Graph{
    umap<ll,list<ll> > gr;
    umap<ll,bool> visited;
    umap<ll,ll> children;
    vector<ll> edgeProd;
    int n;
    public:
        Graph(int N){n = N;}
        void addEdge(ll x, ll y){
            gr[x].pb(y);
            gr[y].pb(x);
        }
        void dfs(ll src){
            visited[src] = true;
            children[src] = 1;
            for(auto x: gr[src]){
                if(!visited[x]){
                    dfs(x);
                    children[src] += (children[x]);
                    children[src] = children[src]%modulo;
                    edgeProd.pb((((children[x])%modulo)*((n-children[x])%modulo))%modulo);
                }
            }
        }
        void labelNodes(vector<ll> factors){
            dfs(1);
            sort(edgeProd.begin(),edgeProd.end(),greater<ll>());
            sort(factors.begin(), factors.end(),greater<ll>());

            ll ans = 0;
            ll len = factors.size();
            ll i = 0;
            // fo(edgeProd.size()){
            //     cout<<edgeProd[i]<<" ";
            // }cout<<endl;
            // fo(factors.size()){
            //     cout<<factors[i]<<" ";
            // }cout<<endl;
            ll toMult = 1;
            while((len-i)>=(n-1)){
                toMult=((toMult)%modulo * (factors[i])%modulo)%modulo;
                i++;
            }
            if(toMult>1) ans+=(edgeProd[0]*toMult);
            ll j = 0;
            while(i<len){
                ans+=(((edgeProd[j]%modulo)*(factors[i]%modulo))%modulo);
                ans = ans%modulo;
                i++; j++;
            }
            while(j<(n-1)){
                ans=(((ans)%modulo) + ((edgeProd[j])%modulo))%modulo;
                j++;
            }
            cout<<ans<<"\n";
            // fo(edgeProd.size()){
            //     cout<<edgeProd[i]<<" ";
            // }cout<<"\n";
        }
        void pgr(){
            ll cnt = 0;
            for(auto par: gr){
                if(!visited[par.first]) cnt++;
            }
            cout<<cnt<<endl;
        }
};

int main(){
    ll t,n,x,y,k;
    cin>>t;
    while(t--){
        cin>>n;
        Graph g(n);
        fo(n-1){
            cin>>x>>y;
            g.addEdge(x,y);
        }
        cin>>k;
        vector<ll> factors;
        fo(k){
            ll a;
            cin>>a;
            factors.pb(a);
        }
        g.labelNodes(factors);
        // g.pgr();
    }
}

/*
1
16
5 10
16 1
14 1
7 5
13 2
16 11
1 7
1 4
3 14
8 16
1 6
4 9
4 12
5 13
1 15
18
45893 9901 51229 15511 46559 28433 4231 30241 29837 34421 12953 6577 12143 52711 40493 89 34819 28571

*/