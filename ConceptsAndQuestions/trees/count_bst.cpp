

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
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

int dp[1000];

int bst_count(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int sum = 0;
    for(int i = 1; i<=n; i++){
        sum+=(bst_count(i-1)*bst_count(n-i));
    }
    dp[n] = sum;
    return sum;
}


int main(){
    int n;
    cin>>n;
    fo(n+1){
        dp[i] = -1;
    }
    cout<<bst_count(n)<<endl;
}