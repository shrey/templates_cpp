

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


bool subset_divisible(int arr[], int n, int m){

    if(n>m){
        return true;
    }
    bool dp[m];
    memset(dp,false,m);
    for(int i = 0; i<n; i++){
        if(dp[0]){
            return true;
        }
        bool temp[m];
        memset(temp,false,m);
        for(int j = 0; j<m; j++){
            if(dp[j]){

                if(dp[(j+arr[i])%m] == false){
                    temp[(j+arr[i])%m] = true;
                }
            }
        }
        for(int j = 0; j<m; j++){
            if(temp[j]){
                dp[j] = true;
            }
        }
        dp[(arr[i]%m)] = true;
    }
    return dp[0];
}

int main(){
    int arr[] = {3,1,7,5};
    int n = sizeof(arr)/sizeof(int);
    int m;
    cin>>m;
    if(subset_divisible(arr,n,m)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


}