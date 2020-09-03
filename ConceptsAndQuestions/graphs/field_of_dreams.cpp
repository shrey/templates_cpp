

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

string arr[501];
map<pair<int,int>,int> pos;
vector<int> gr[501];
vector<int> visited(501,false);
int low[100005];
int tme = 0;
int disc[100005];
int n,m;
int one = 0;
int num = 0;
void build_gr(){
    fo(n){
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 'g'){
                int curr = pos[mp(i,j)];
                if(i>0 && arr[i-1][j] == 'g'){
                    gr[curr].pb(pos[mp(i-1,j)]);
                }
                if(i<n-1 && arr[i+1][j] == 'g'){
                    gr[curr].pb(pos[mp(i+1,j)]);
                }
                if(j>0 && arr[i][j-1] == 'g'){
                    gr[curr].pb(pos[mp(i,j-1)]);
                }
                if(j<n-1 && arr[i][j+1] == 'g'){
                    gr[curr].pb(pos[mp(i,j+1)]);
                }
            }
        }
    }
}

void dfs(int curr, int par){
    visited[curr] = true;
    disc[curr] = low[curr] = tme++;
    int no_child = 0;
    for(auto it: gr[curr]){
        if(!visited[it]){
            dfs(it,curr);
            low[curr] = min(low[curr],low[it]);
            if(low[it]>=disc[curr] && par!=-1){
                one = 1;
            }
            no_child++;
        }
        else if(it!=par){
            low[curr] = min(low[curr],disc[it]);
        }
    }
    if(par == -1 && no_child>1){
        one = 1;
    }
}

void solve(){
    int cc = 0;
    for(int i = 0; i<num; i++){
        if(!visited[num]){
            cc++;
            dfs(i,-1);
        }
    }
    if(cc>1){
        cout<<2<<"\n";
    }
    else if(one){
        cout<<1<<"\n";
    }
    else{
        cout<<2<<"\n";
    }

}


int main(){

    cin>>n>>m;
    fo(n) cin>>arr[i];
    num = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 'g'){
                pos[mp(i,j)] = num++;
            }
        }
    }
    build_gr();
    solve();
}

/*
3 3
ggg
gdg
ggg
*/