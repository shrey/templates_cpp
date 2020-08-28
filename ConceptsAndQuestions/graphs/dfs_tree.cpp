

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

const int N = 100;
vector<int> gr[N];
vector<bool> visited(N,false);
vector<int> dTree[N];

void generateDfs(int src){
    visited[src] = true;
    for(auto x: gr[src]){
        if(!visited[x]){
            dTree[src].pb(x);
            dTree[x].pb(src);
            generateDfs(x);
        }
    }
}

void printTree(int cur, int par){
    cout<<cur<<" ";
    for(auto x: dTree[cur]){
        if(x!=par){
            printTree(x,cur);
        }
    }
}

int main(){
    int n,x,y,v;
    cin>>n>>v;
    fo(v){
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    generateDfs(1);
    cout<<"DFS TREE IS:- "<<endl;
    printTree(1,0);
}

/*
12 16
1 3
1 6
1 5
1 9
9 11
9 12
11 12
3 7
3 5
3 6
3 8
7 5
6 2
2 8
2 4
4 10


*/