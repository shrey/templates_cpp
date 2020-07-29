

//shrey dubey



#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
#include<set>
#include<list>
#include<iomanip>


#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

double dp[3001][3001];

double heads_prob(double prob[], int n, int x){
    if(x == 0){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    if(dp[n][x]> -0.9){
        return dp[n][x];
    }
    dp[n][x] = (prob[n]*heads_prob(prob,n-1,x-1) + (1-prob[n])*heads_prob(prob,n-1,x));
    return dp[n][x];
}

int main(){
    int n;
    cin>>n;
    double prob[n+1];
    for(int i = 1; i<=n; i++){
        cin>>prob[i];
    }
    int x = (n+1)/2;
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=x; j++){
            dp[i][j] = -1;
        }
    }
    prDouble(heads_prob(prob,n,x));

    // double dp[n+1][x+1];
    // dp[0][0] = 1.0;
    // for(int i = 1; i<=x; i++){
    //     dp[0][x] = 0;
    // }
    // for(int i = 1; i<=n; i++){
    //     dp[i][0] = 1;
    // }
    // for(int i = 1; i<=x; i++){
    //     dp[i][i] = prob[i]*dp[i-1][i-1];
    // }
    // for(int i = 1; i<=n; i++){
    //     for(int j = 1; j<=x; j++){
    //         dp[i][j] = dp[i-1][j-1]*prob[i] + (1-prob[i])*dp[i-1][i];
    //     }
    // }
    // cout<<dp[n][x]<<endl;
}
