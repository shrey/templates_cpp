//find the smallest hieght of node that can be visited from subtree of x





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
vector<int> gr[100];
vector<bool> visited(N, false);
int depth[N];
int dp[N];


void dfs(int cur, int par, int dep){
    visited[cur] = true;
    dp[cur] = dep;
    depth[cur] = dep;
    for(auto x: gr[cur]){
        if(!visited[x]){
            dfs(x,cur,dep+1);
            dp[cur] = min(dp[cur],dp[x]);
        }
        else if(x!=par){
            //backedge
            dp[cur] = min(dp[cur],depth[x]);
        }
    }
}

int main(){
    int n,x,y,m;
    cin>>n>>m;
    fo(m){
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    memset(dp,-1,sizeof dp);
    dfs(1,0,0);
    fo(n){
        cout<<"("<<i+1<<" - "<<dp[i+1]<<")"<<endl;
    }

}

/*

12 16
1 3
1 9
9 12
12 11
11 9
3 5
5 7
7 3
5 1
3 6
6 1
6 2
2 8
8 3
2 4
4 10


*/