

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

int compute(int arr[], int n, int k){
    int dp[k+1][n+1];
    memset(dp,0,sizeof dp);
    for(int i = 1; i<=k; i++){
        for(int j = 1; j<=n; j++){
            dp[i][j] = dp[i][j-1];
            if(arr[j-1]<=i && arr[j-1]>0){
                dp[i][j] += dp[(i/arr[j-1])][j-1] + 1;
            }
        }
    }
    return dp[k][n];
}


int main(){
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(int);
    int k = 10;
    cout<<compute(arr,n,k)<<endl;

}