

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

int n = 4;
int dist[10][10] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
    };
int dp[1000][1000];
//if all citied have been visited
int visitedAll = (1<<n)-1;
int travellingSalesman(int mask, int pos){
    if(mask == visitedAll){
        return dist[pos][0];
    }
    if(dp[mask][pos]!=-1){
        cout<<1<<endl;
        return dp[mask][pos];
    }
    int ans = INT_MAX;
    //try to go to unvisited city
    for(int city = 0; city<n; city++){
        if(((1<<city)&mask)==0){
            int newAns = dist[pos][city] + travellingSalesman((mask|(1<<city)),city);
            ans = min(newAns,ans);
        }
    }
    dp[mask][pos] = ans;
    return ans;
}

int main(){
    memset(dp,-1,sizeof dp);
    cout<<travellingSalesman(1,0)<<endl;
}