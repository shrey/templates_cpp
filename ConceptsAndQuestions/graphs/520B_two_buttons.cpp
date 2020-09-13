

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



ll calcLength(ll n, ll m){
    queue<ll> q;
    umap<ll,bool> visited;
    umap<ll,ll> dist;
    dist[n] = 0;
    visited[n] = true;
    q.push(n);
    while(!q.empty()){
        ll par = q.front();
        q.pop();
        if(par == m){
            return dist[par];
        }
        if(!visited[2*par] && (par)<m){
            q.push(2*par);
            dist[2*par] = dist[par]+1;
            visited[2*par] = true;
        }
        if(par>1 && !visited[par-1]){
            q.push(par-1);
            dist[par-1] = dist[par]+1;
            visited[par-1] = true;
        }
    }
    return -1;
}

int main(){
    ll n,m;
    cin>>n>>m;
    cout<<calcLength(n,m);
}