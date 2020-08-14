

//Shrey Dubey

//Contact Me at wshrey09@gmail.com

// https://www.geeksforgeeks.org/maximum-games-played-winner/


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


int compute(int n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    if(n%2 == 0){
        return (1+compute(n/2));
    }
    else{
        return (1+compute((n+1)/2));
    }
}

int main(){
    int n;
    cin>>n;
    int dp[n];
    dp[0] = 1;
    dp[1] = 2;
    int i = 2;
    do{
        dp[i] = dp[i-1] + dp[i-2];
    }while(dp[i++]<=n);
    // cout<<i-2<<endl;
    cout<<compute(n)<<endl;
}