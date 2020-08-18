//https://www.geeksforgeeks.org/minimum-initial-vertices-traverse-whole-matrix-given-conditions/



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

const int MAX = 100;

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

map<pair<int,int>,bool> visited;

struct node{
    int r,c,val;
};

bool compare(node &a, node &b){
    return (a.val>b.val);
}



void dfs(int mat[][MAX], int i, int j, int n){
    if(i<0 || i>=n || j<0 || j>=n || visited[mp(i,j)]){
        return;
    }
    visited[mp(i,j)] = true;
    if(i>0 && mat[i-1][j]<=mat[i][j]){
        dfs(mat,i-1,j,n);
    }
    if(j>0 && mat[i][j-1]<=mat[i][j]){
        dfs(mat,i,j-1,n);
    }
    if(i<n-1 && mat[i+1][j]<=mat[i][j]){
        dfs(mat,i+1,j,n);
    }
    if(j<n-1 && mat[i][j+1]<=mat[i][j]){
        dfs(mat,i,j+1,n);
    }
}

int solve(int mat[][MAX], int n){
    vector<node> vertices;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            node temp;
            temp.r = i;
            temp.c = j;
            temp.val = mat[i][j];
            vertices.pb(temp);
        }
    }
    sort(vertices.begin(),vertices.end(),compare);
    // for(auto it: vertices){
    //     cout<<it.r<<" "<<it.c<<" "<<it.val<<" "<<endl;
    // }
    int cnt = 0;
    for(auto it: vertices){
        if(!visited[mp(it.r,it.c)]){
            cout<<it.r<<" "<<it.c<<endl;
            dfs(mat,it.r,it.c,n);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int mat[][MAX] =    {{1,2,3},
                         {2,3,1},
                         {1,1,1}};
    int n = 3;
    cout<<solve(mat,n)<<endl;

}