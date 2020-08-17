

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

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

int maxprod(int n){
    if(n<3){
        return n-1;
    }
    if(n == 4){
        return n;
    }
    int res = 1;
    while(n>4){
        res*=3;
        n-=3;
    }
    return (res*n);
}

int main(){
    int n;
    cin>>n;
    int dp[n+1];
    if(n == 2){
        cout<<1<<endl;
        return 0;
    }
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i<=n; i++){
        int maxProd = 0;
        int j = i-1;
        while(j>=i/2){
            maxProd = max(maxProd,dp[j]*dp[i-j]);
            j--;
        }
        dp[i] = maxProd;
        if(i!=n)
            dp[i] = max(maxProd,i);
    }

    cout<<dp[n]<<" "<<maxprod(n)<<endl;
}