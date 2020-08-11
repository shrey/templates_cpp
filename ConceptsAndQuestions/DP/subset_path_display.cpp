

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

bool dp[1000][1000];

void display(vector<int> &p){
    for(int i = 0; i<p.size(); i++){
        cout<<p[i]<<" ";
    }cout<<endl;
}

void print_all_subsets(int arr[], int i, int sum, vector<int> &p){
    if( i == 0 && sum!=0 && dp[i][sum]){
        //display the path
        p.push_back(arr[i]);
        display(p);
        return;

    }
    if(i == 0 && sum == 0){
        display(p);
        return;
    }
    if(dp[i-1][sum]){
        vector<int> b = p;
        print_all_subsets(arr,i-1,sum,b);
    }
    if(arr[i]<=sum && dp[i-1][sum-arr[i]]){
        p.push_back(arr[i]);
        print_all_subsets(arr,i-1,sum-arr[i],p);
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    int sum;
    cin>>sum;

    memset(dp,false, sizeof dp);

    for(int i = 0; i<=n; i++){
        dp[i][0] = true;
    }
    if(arr[0]<=sum){
        dp[0][arr[0]] = true;
    }
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=sum; j++){
            dp[i][j] = arr[i]<=j ? dp[i-1][j] || dp[i-1][j-arr[i]] : dp[i-1][j];
        }
    }
    if(dp[n-1][sum]){
        cout<<"YES"<<endl;
        vector<int> p;
        print_all_subsets(arr,n,sum,p);
    }
    else{
        cout<<"NO"<<endl;
    }


}