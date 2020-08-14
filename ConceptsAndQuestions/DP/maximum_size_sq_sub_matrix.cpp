

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


bool check_possibility(int m[][5], int size, int i, int j){
    bool possible = true;
    int r = i, c = j;
    while(i>=0 && j>=0 && size){
        // cout<<i<<" "<<c<<" , "<<r<<" , "<<j<<endl;
        if(m[i][c] == 0 || m[r][j] == 0){
            possible = false;
            break;
        }
        i--; j--; size--;
    }
    if((i<0 || j<0) && size){
        possible = false;
    }
    // if(possible){
    //     cout<<"YES"<<endl;
    // }
    // else{
    //     cout<<"NO"<<endl;
    // }
    return possible;
}


int main(){
        int R = 6, C = 5;
        int m[][5]= {
                    {0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};
        int dp[R][C];

        for(int i = 0; i<R; i++){
            for(int j = 0; j<C; j++){
                if(m[i][j]){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        int result = 1;
        // for(int i = 1; i<R; i++){
        //     for(int j = 1; j<C; j++){
        //         if(dp[i-1][j-1] && dp[i][j]){
        //             if(check_possibility(m,dp[i-1][j-1]+1,i,j)){
        //                 dp[i][j] = dp[i-1][j-1] + 1;
        //             }
        //         }
        //         result = max(result,dp[i][j]);
        //     }cout<<endl;

        // }
        // for(int i = 0; i<R; i++){
        //     for(int j = 0; j<C; j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        for(int i = 1; i<R; i++){
            for(int j = 1; j<C; j++){
                if(dp[i][j]){
                    dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                }
                result = max(result,dp[i][j]);
            }
        }
        for(int i = 0; i<R; i++){
            for(int j = 0; j<C; j++){
                cout<<dp[i][j]<<" ";
            }cout<<endl;
        }
        cout<<result<<endl;

}