

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

int replaceIndex(vector<int> &v, int s, int e, int key){
    int ans = 0;
    while(s<=e){
        int mid = (s+e)/2;
        if(key<=v[mid]){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}

void lis(int arr[], int n){
    vector<int> v(n);
    int len = -1;
    v[0] = arr[0];
    len++;
    for(int i = 1; i<n; i++){
        if(arr[i]>v[len]){
            v[len+1] = arr[i];
            len++;
        }
        else if(arr[i]<v[0]){
            v[0] = arr[i];
        }
        else{
            v[replaceIndex(v,0,len,arr[i])] = arr[i];
        }
    }
    cout<<len+1<<endl;
    for(int i = 0; i<=len; i++){
        cout<<v[i]<<" ";
    }
}


int lis_dp(int arr[], int n){
    int dp[n];
    dp[0] = 1;
    for(int i = 1; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    return dp[n-1];
}

int main(){
    int n;

    int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    n = sizeof(arr)/sizeof(int);
    // lis(arr,n);
    cout<<lis_dp(arr,n)<<endl;
    // vector<int> v;
    // v.pb(1);
    // v.pb(3);
    // v.pb(5);
    // v.pb(7);
    // v.pb(9);
    // v.pb(13);
    // v.pb(11);
    // v.pb(12);
    // cout<<replaceIndex(v,0,v.size()-1,1)<<endl;
}