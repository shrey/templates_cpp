

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
#define fo(x,y) for(int i = x; i<y; i++)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

int dp[100001];

int recur(int arr[], int i, int n, int k, int z){
    if(i == n || k<0 || i<0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    //going to right
    int s1 = 0,s2 = 0;
    if(i<n-1){
        s1 = recur(arr,i+1,n,k-1,z);
    }
    //checking and going left
    if(z>0 && i>0){
        s2 = recur(arr,i-1,n,k-1,z-1);
    }
    dp[i] = arr[i] + max(s1,s2);
    return dp[i];
}


int main(){
    int t;
    cin>>t;
    int n,k,z;

    fo(0,t){
        cin>>n>>k>>z;
        int arr[n];
        for(int i = 0; i<=n; i++){
            dp[i] = -1;
        }
        fo(0,n){
            cin>>arr[i];
        }
        cout<<recur(arr,0,n,k,z)<<"\n";
    }
}