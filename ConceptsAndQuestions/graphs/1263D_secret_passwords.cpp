

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
const int N = 2e5+100;
vector<int> gr[N];
vector<int> visited(N, false);

void addEdge(int x, int y){
    gr[x].pb(y); gr[y].pb(x);
}

void dfs(int curr){
    visited[curr] = true;
    for(auto x: gr[curr]){
        if(!visited[x]) dfs(x);
    }
}

int main(){
    int n;
    cin>>n;
    string s[n];
    fo(n) cin>>s[i];
    for(int i = 0; i<n; i++){
        for(char c: s[i]){
            addEdge(i,c-'a'+n);
        }
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<"\n";
}