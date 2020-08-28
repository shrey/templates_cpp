

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

const int N = 100005;

vector<int> gr[N];
int tin[N];
int tout[N], timer;

void euler_tour_1(int cur, int par){
    cout<<cur<<" ";
    for(auto x: gr[cur]){
        if(x!=par){
            euler_tour_1(x,cur);
            cout<<cur<<" ";
        }
    }
    return;
}
void euler_tour_2(int cur, int par){
    cout<<cur<<" ";
    for(auto x: gr[cur]){
        if(x!=par){
            euler_tour_2(x,cur);
        }
    }
    cout<<cur<<" ";
    return;
}
void euler_tour_3(int cur, int par){
    cout<<cur<<" ";
    tin[cur] = ++timer;
    for(auto x: gr[cur]){
        if(x!=par){
            euler_tour_3(x,cur);
        }
    }
    tout[cur] = timer;
    return;
}

//whether x is ancestor of y or not
bool is_ancestor(int x, int y){
    if(tin[x]<=tin[y] && tout[x]>=tout[y]) return true;
    return false;
}

void solve(){
    int n,x,y;
    cin>>n;
    for(int i = 0; i<n-1; i++){
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    timer = 0;
    // euler_tour_1(1,0);
    // cout<<endl;
    // euler_tour_2(1,0);
    // cout<<endl;
    euler_tour_3(1,0);
    cout<<endl;
    fo(n){
        cout<<i+1<<" : "<<tin[i+1]<<" - "<<tout[i+1]<<endl;
    }
    if(is_ancestor(6,7)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){
    solve();
}

/*
9
1 2
2 4
2 5
2 6
1 3
3 7
7 8
7 9

*/