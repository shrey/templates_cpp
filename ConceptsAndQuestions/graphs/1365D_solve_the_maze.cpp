

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


#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)


using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

const int M = 100;
int n,m;
char mat[M][M];

int dir[][4] = {{1,0},{0,1},{-1,0},{0,-1}};

bool valid(int i, int j){
    if(i>=0 && i<n && j>=0 && j<m) return true;
    // cout<<"("<<i<<" "<<j<<")"<<endl;
    return false;
}


bool solve(){
    int b = 0, g = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 'B') b++;
            if(mat[i][j] == 'G') g++;
        }
    }
    if(g == 0) return true;
    if(mat[n-2][m-1] == 'B' || mat[n-1][m-2] == 'B') return false;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 'B'){
                for(int k = 0; k<4; k++){
                    int r = i + dir[k][0];
                    int c = j + dir[k][1];
                    if(valid(r,c)){
                        if(mat[r][c] == 'G') return false;
                        if(mat[r][c] == '.') mat[r][c] = '#';
                    }
                }
            }
        }
    }
    vector<vector<bool> > visited(M,vector<bool>(M,false));
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout<<mat[i][j]<<" ";
    //     }cout<<endl;
    // }
    queue< pair<int,int > > q;

    if(mat[n-1][m-1] == '.'){
        visited[n-1][m-1] = true;
        q.push(mp(n-1,m-1));
    }
    while(!q.empty()){
        auto curr = q.front();
        // cout<<curr.first<<" "<<curr.second<<endl;
        q.pop();
        for(int k = 0; k<4; k++){
            int r = curr.first + dir[k][0];
            int c = curr.second + dir[k][1];

            if(valid(r,c) && !visited[r][c] && mat[r][c]!='#'){
                // cout<<r<<" "<<c<<endl;
                q.push(mp(r,c));
                visited[r][c] = true;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if((mat[i][j] == 'G' && !visited[i][j]) || (mat[i][j] == 'B' && visited[i][j])){
                return false;
            }
        }
    }
    return true;
}

int main(){
    KOBE;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cin>>mat[i][j];
            }
        }
        if(solve()){
            YES;
        }
        else{
            NO;
        }
    }
}
