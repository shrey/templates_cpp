

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
#define MAX 100005
using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

int dp[100][100];

int optimalGameStrategy(int arr[], int n, int i, int j){
    if(i>j){
        return 0;
    }
    if(i == j){
        return arr[i];
    }
    if(i == j-1){
        return max(arr[i],arr[j]);
    }
    //choosing i
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans1 = arr[i] + min(optimalGameStrategy(arr,n,i+2,j),optimalGameStrategy(arr,n,i+1,j-1));
    int ans2 = arr[j] + min(optimalGameStrategy(arr,n,i+1,j-1),optimalGameStrategy(arr,n,i,j-2));
    dp[i][j] = max(ans1,ans2);
    return dp[i][j];
}

int main(){
    int arr1[] = { 20, 30, 2, 2, 2, 10 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    memset(dp,-1,sizeof dp);
    cout<<optimalGameStrategy(arr1,n,0,n-1)<<endl;
}