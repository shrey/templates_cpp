

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

ll n,x,y;
const ll M = 2e5+1;
vector<ll> gr[M];
vector<bool> visited(M,false);
vector<ll> dist(M,0);
vector<ll> par(M,0);

bool solve(ll arr[]){
    ll currMax = 0;
    umap<ll,ll> pos;
    fo(n){
        ll curr = dist[arr[i]];
        if(curr<currMax) return false;
        currMax = max(curr,currMax);
        pos[arr[i]] = i;
    }
    ll cpos = 0;
    for(int i = 1; i<n; i++){
        ll curr = pos[par[arr[i]]];
        if(curr<cpos) return false;
        cpos = max(curr,cpos);
    }
    return true;
}

int main(){
    KOBE;
    cin>>n;
    fo(n-1){
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    queue<ll> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        ll curr = q.front();
        q.pop();
        for(auto x: gr[curr]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
                dist[x] = dist[curr]+1;
                par[x] = curr;
            }
        }
    }
    ll arr[M];
    fo(n){
        cin>>arr[i];
    }
    if(solve(arr)){
        YES;
    }
    else{
        NO;
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// try to double the max array size


/*
6
1 2
1 3
2 4
2 5
1 6
1 6 3 2 4 5
*/