// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/



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
#include<math.h>


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
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr)/sizeof(int);
    int sum = 0;
    fo(n){
        sum+=arr[i];
    }
    bool dp[n+1][sum+1];
    for(int i = 0; i<=n; i++){
        dp[i][0] = true;
    }
    for(int i = 1; i<=sum; i++){
        dp[0][i] = false;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            dp[i][j] = (dp[i-1][j]);
            if(arr[i-1]<=j){
                dp[i][j] |=dp[i-1][j-arr[i-1]];
            }
        }
    }
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=sum; j++){
            if(dp[i][j]){
                cout<<"1 ";
            }
            else cout<<"0 ";
        }cout<<endl;
    }
    int result = 0;
    for(int j = sum/2; j>=0; j--){
        if(dp[n][j]){
            cout<<sum<<" "<<j<<endl;
            result = sum - (2*j);
            break;
        }
    }
    cout<<result<<endl;
}