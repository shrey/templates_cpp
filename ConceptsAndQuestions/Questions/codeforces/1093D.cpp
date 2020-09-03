

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
#define MAX 998244353
using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

ll pwm(ll a, ll n){
    if(!n) return 1;
    ll t = (pwm(a,n/2)%MAX);
    t = (t*t)%MAX;
    if(n&1){
        t = (t*a)%MAX;
    }
    return t;
}

class Graph{
    umap<int,list<int> > adjlist;
    umap<int,bool> even;
    umap<int,bool> visited;
    bool possible;
    int cnt0 = 0, cnt1 = 0;
    int N;
    public:
        Graph(int n){
            N = n;
            possible = true;
        }
        void addEdge(int x, int y){
            adjlist[x].pb(y);
            adjlist[y].pb(x);
        }
        void dfs(int src, bool isEven){
            if(visited[src]){
                if(isEven!=even[src]){
                    // cout<<src<<"()"<<endl;
                    possible = false;
                }
                return;
            }
            visited[src] = true;
            even[src] = isEven;
            if(isEven){
                cnt0++;
            }else{
                cnt1++;
            }
            for(auto it: adjlist[src]){
                dfs(it,!isEven);
            }
        }
        void solve(){
            ll ans = 1;
            for(int i = 1; i<=N; i++){
                cnt0 = 0; cnt1 = 0;
                if(!visited[i]) dfs(i,true);
                // cout<<cnt0<<"()"<<cnt1<<endl;
                if(!possible){
                    cout<<0<<"\n";
                    return;
                }
                if(cnt0 || cnt1)
                    ans=((ans*(pwm(2,cnt0)+pwm(2,cnt1)))%MAX);
            }
            cout<<ans<<"\n";
        }
};

int main(){
    int t,n,m,x,y;
    cin>>t;
    while(t--){
        cin>>n>>m;
        Graph g(n);
        fo(m){
            cin>>x>>y;
            g.addEdge(x,y);
        }
        g.solve();
    }
}

/*
1
6 5
1 2
1 3
2 4
2 5
2 6
*/