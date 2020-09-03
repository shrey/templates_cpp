

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

int main(){
    int n,m;
    cin>>n>>m;
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(1);
    vector<int> gr[n+1];
    vector<bool> visited(n+1,false);
    fo(m){
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    visited[1] = true;
    while(!pq.empty()){
        int par = pq.top();
        cout<<par<<" ";
        pq.pop();
        for(auto child: gr[par]){
            if(!visited[child]){
                pq.push(child);
                visited[child] = true;
            }
        }
    }


}