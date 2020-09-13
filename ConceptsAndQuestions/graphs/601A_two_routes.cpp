

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
const int M = 401;


ll sssp(ll mat[M][M], int n){
    queue<ll> q;
    q.push(1);
    umap<ll,bool> visited;
    umap<ll,ll> dist;
    visited[1] = true;
    while(!q.empty()){
        ll curr = q.front();
        q.pop();
        for(int i = 1; i<=n; i++){
            if(mat[curr][i] && !visited[i]){
                dist[i] = dist[curr]+1;
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return dist[n];
}


int main(){
    KOBE;
    ll mat1[M][M] = {0};
    ll mat2[M][M];
    ll n,m;
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            mat2[i][j] = 1;
        }
    }
    fo(m){
        ll x,y;
        cin>>x>>y;
        mat1[x][y] = mat1[y][x] = 1;
        mat2[x][y] = mat2[y][x] = 0;
    }
    ll ans;
    if(mat1[1][n]){
        ans = sssp(mat2,n);
    }
    else{
        ans = sssp(mat1,n);
    }
    if(ans){
        cout<<ans<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }
}
