//https://www.geeksforgeeks.org/recursively-break-number-3-parts-get-maximum-sum/



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

void setdp(int dp[], int n, int val){
    fo(n){
        dp[i] = val;
    }
}

int dp[10000];

int max_break(int n){
    if(n == 0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int n1 = max_break(n/2) + max_break(n/3) + max_break(n/4);
    dp[n] = max(n,n1);
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    fo(n+1){
        dp[i] = -1;
    }
    cout<<max_break(n)<<endl;

}