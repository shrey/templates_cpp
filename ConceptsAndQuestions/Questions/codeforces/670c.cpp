

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
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)


using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

const ll M = 2e5+1;

class Graph{
    umap<ll,list<ll> > gr;
    ll n;
    umap<ll,bool> visited;
    ll a,b;
    ll n1,n2;
    ll ver;
    ll lf1, lf2;
    umap<ll,ll> child;
    public:
        Graph(ll N){
            n = N;
        }
        void addEdge(ll x, ll y){
            gr[x].pb(y);
            gr[y].pb(x);
        }
        ll dfs(ll curr){
            visited[curr] = true;
            ll ans = 1;
            for(auto x: gr[curr]){
                if(!visited[x]){
                    ll c = dfs(x);
                    ans+=c;
                    if(max(c,n-c)<ver){
                        ver = max(c,n-c);
                        a = curr; b = x; n1 = c; n2 = n-c;
                    }
                }
            }
            child[curr] = ans;
            return ans;
        }

        void solve(){
            n1 = LLONG_MAX; n2 = LLONG_MAX; ver = LLONG_MAX;
            dfs(1);
            // for(int i = 1; i<=n; i++){
            //     cout<<child[i]<<" ";
            // }cout<<endl;
            // cout<<a<<" "<<b<<endl;
            if(n1 == n2){
                visited.clear();
                lf1 = a;
                for(auto x: gr[a]){
                    if(x!=b){
                        cout<<a<<" "<<x<<"\n";
                        cout<<b<<" "<<x<<"\n";
                        return;
                    }
                }
            }
            else{
                cout<<a<<" "<<b<<"\n";
                cout<<a<<" "<<b<<"\n";
            }
        }
};

int main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;;
        Graph g(n);
        fo(n-1){
            ll x,y;
            cin>>x>>y;
            g.addEdge(x,y);
        }
        g.solve();
    }
}

/*
1
8
1 2
1 6
1 4
1 3
2 8
2 5
5 7
*/