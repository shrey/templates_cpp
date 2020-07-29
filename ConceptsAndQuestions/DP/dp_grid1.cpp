#include <iostream>
#include<string>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
#include<set>
#include<list>

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;
int main() {
    int rows,cols;
    cin>>rows>>cols;
    ll dp[rows+1][cols+1], arr[rows+1][cols+1];
    for(int i = 0; i<=rows; i++){
        for(int j = 0; j<=cols; j++){
            dp[i][j] = 0;
        }
    }
    char c;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){

            cin>>c;
            if(c == '.'){
                arr[i][j] = 0;
            }
            else{
                arr[i][j] = 1;
            }
        }
    }
    if(arr[0][0]!=0){
        cout<<"0"<<"\n";
        return 0;
    }
    dp[0][0] = 1;
    for(int i = 1; i<rows; i++){
        if(arr[i][0] == 0){
            dp[i][0] = (dp[i-1][0])%modulo;
        }
        else{
            dp[i][0] = 0;
        }
    }
    for(int i = 1; i<cols; i++){
        if(arr[0][i] == 0){
            dp[0][i] = dp[0][i-1]%modulo;
        }
        else{
            dp[0][i] = 0;
        }
    }
    for(int i = 1; i<rows; i++){
        for(int j = 1; j<cols; j++){
            if(arr[i][j] == 0){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%modulo;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    dp[rows-1][cols-1] = dp[rows-1][cols-1]%modulo;
    cout<<(dp[rows-1][cols-1])<<"\n";
}
