

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
const int N = 25e4+1;
int curr = 0;
vector<int> gr[N];
map<pair<int,int>,int> cord;

struct node{
    int r,c,val;
    bool operator<(const node &k)const{
        return (val<k.val);
    }
};

void build_graph(int mat[][1000], int n, int m){
    int maxVal = INT_MIN;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int cordVal = cord[mp(i,j)];
            if(i>0){
                gr[cordVal].pb(cord[mp(i-1,j)]);
            }
            if(i<n-1){
                gr[cordVal].pb(cord[mp(i+1,j)]);
            }
            if(j>0){
                gr[cordVal].pb(cord[mp(i,j-1)]);
            }
            if(j<m-1){
                gr[cordVal].pb(cord[mp(i,j+1)]);
            }
            maxVal = max(maxVal,mat[i][j]);
        }
    }
}

int main(){
    int t,n,m;
    cin>>t;

    while(t--){
        cin>>n>>m;
        int mat[n][m];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>mat[i][j];
                cord[mp(i,j)] = curr++;
            }
        }
    }

}