

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


int dp[10000][10000];

int compute(int arr[], int i, int sum){
    if(i < 0){
        if(sum == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    // cout<<arr[i]<<" "<<sum<<endl;
    if(sum == 0){

        return 1;
    }
    if(dp[i][sum]!=-1){

        return dp[i][sum];
    }
    //include and exclude
    dp[i][sum] = max(compute(arr,i-1,sum-arr[i]), compute(arr,i-1,sum));
    return dp[i][sum];
}

int main(){
    int arr[] = {4, 1, 10, 12, 5};
    int n = sizeof(arr)/sizeof(int);
    int sum;
    cin>>sum;
    for(int i = 0; i<=1000; i++){
        for(int j = 0; j<=1000; j++){
            dp[i][j] = -1;
        }
    }
    if(compute(arr,n-1,sum)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}