

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
    int n = 5;
    int arr[2][5] ={{ 1, 2, 3, 4, 5},
                    { 6, 7, 8, 9, 10}};
    int dp[2][5] = {0};
    for(int j = 0; j<2; j++){
        for(int i = 0; i<2; i++){
            dp[i][j] = arr[i][j];
        }
    }

    int result = 0;
    for(int j = 2; j<n; j++){
        int max_no = max(dp[0][j-2],dp[1][j-2]);
        dp[0][j] = max_no+arr[0][j];
        result = max(result,dp[0][j]);
        dp[1][j] = max_no + arr[1][j];
        result = max(result,dp[1][j]);
    }
    cout<<result<<endl;

}