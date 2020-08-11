

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
    int arr[] = {18, 1, 3, 6, 13, 17};
    int n = sizeof(arr)/sizeof(int);
    sort(arr,arr+n);
    int dp[n];
    dp[n-1] = 1;
    int result = INT_MIN;
    for(int i = n-2; i>=0; i--){
        int max_addition = 0;
        for(int j = i+1; j<n; j++){
            if((arr[j]%arr[i]) == 0){
                max_addition = max(max_addition,dp[j]);
            }
            dp[i] = max_addition + 1;
        }
        result = max(dp[i],result);
    }
    cout<<result<<endl;

}