

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

int main(){
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(arr)/sizeof(int);
    int dp[n];
    dp[0] = arr[0];
    for(int i = 1; i<n; i++){
        int max_val = arr[i];
        for(int j = i-1; j>=0; j--){
            max_val = max(max_val,dp[j] + arr[i-j-1]);
        }
        dp[i] = max_val;
    }
    for(int i = 0; i<n; i++){
        cout<<dp[i]<<" ";
    }
    // cout<<dp[n-1]<<endl;
}