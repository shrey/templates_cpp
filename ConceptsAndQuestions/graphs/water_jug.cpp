//https://www.geeksforgeeks.org/water-jug-problem-using-bfs/



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

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

struct node{
    int x, y;
};

void solve(int m, int n, int target){
    node src = {0,0};
    queue<node> q;
    q.push(src);
    umap<node,bool> visited;
    visited[src] = true;
    vector<node> path;
    node p = {-1,-1};
    bool isSolvable = false;
    while(!q.empty()){
        node p = q.front();
        q.pop();
        int r = p.x;
        int c = p.y;
        if(visited[p] || r<0 || c<0 || r>m || c>n){
            continue;
        }
        visited[p] = true;
        path.pb(p);
        if(r == target || c == target){
            isSolvable = true;
            if(r==target){
                node curr = {r,0};
                path.pb(curr);
            }
            else{
                node curr = {0,c};
                path.pb(curr);
            }
            fo(path.size()){
                cout<<"("<<path[i].x<<","<<path[i].y<<")"<<endl;
            }
            break;
        }
        node curr1 = {r,n};
        node curr2 = {m,c};
        q.push(curr1);
        q.push(curr2);
        for(int i = 0; i<=max(m,n); i++){
            int c = r + i;
            int d = c-i;

        }
    }
}

int main(){

}