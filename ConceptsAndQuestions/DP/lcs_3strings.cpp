

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

int max_no(int a, int b, int c){
    return max(a,max(b,c));
}

int main(){
    string a,b,c;
    a = "abedcf";
    b = "ibdcfe";
    c = "beklm";
    int dp[a.length()+1][b.length()+1][c.length()+1];
    memset(dp,0,sizeof dp);
    for(int i = 1; i<=a.length(); i++){
        for(int j = 1; j<=b.length(); j++){
            for(int k = 1; k<=c.length(); k++){
                if(a[i-1] == b[j-1] && b[j-1] == c[k-1]){
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1;
                }
                else{
                    dp[i][j][k] = max_no(dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]);
                }
            }
        }
    }
    cout<<dp[a.length()][b.length()][c.length()]<<endl;
}