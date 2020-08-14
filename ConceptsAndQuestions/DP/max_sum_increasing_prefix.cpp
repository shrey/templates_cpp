// https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-from-a-prefix-and-a-given-element-after-prefix-is-must/



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
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    int t = 2;
    int k = 5;
    int dp[n];
    fo(n){
        dp[i] = arr[i];
    }
    int result = 0;
    for(int i = 1; i<=t; i++){
        if(i>k){
           if(arr[i]>arr[k]){
                dp[i] = dp[k] + arr[i];
                result = max(result,dp[i]);
            }
            else{
                dp[i] = INT_MIN;
            }
        }
        else{
            for(int j = 0; j<i; j++){
                if(arr[i]>arr[j]){
                    dp[i] = max(dp[i],dp[j]+arr[i]);
                }
            }
        }
    }
    if(t == k){
        result = dp[k];
    }

    if(k>t){
        result = 1;
        for(int i = 0; i<=t; i++){
            if(arr[k]>arr[i]){
                result = max(result,dp[i] + arr[k]);
            }
        }
    }
    cout<<result<<endl;
}
