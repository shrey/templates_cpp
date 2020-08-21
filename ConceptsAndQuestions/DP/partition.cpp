

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
#include <math.h>



#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map
#define mp make_pair

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

int main(){
    int a[] = {1, 5, 11, 5};
    int sum = 0;
    int n = sizeof(a)/sizeof(int);
    fo(n){
        sum+=a[i];
    }
    bool dp[n+1][sum+1];
    dp[0][0] = true;
    for(int i = 1; i<=n; i++){
        dp[i][0] = true;
    }
    for(int i = 1; i<=sum; i++){
        dp[0][i] = false;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            dp[i][j] = dp[i-1][j];
            if(a[i-1]<=j){
                dp[i][j]|=dp[i-1][j-a[i-1]];
            }
        }
    }
    if(dp[n][sum/2]){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}