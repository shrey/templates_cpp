

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

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int dp[s1.length()+1][s2.length()+1];
    fo(s1.length()+1){
        dp[i][0] = 0;
    }
    fo(s2.length()+1){
        dp[0][i] = 0;
    }
    for(int i = 1; i<=s1.length(); i++){
        for(int j = 1; j<=s2.length(); j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[s1.length()][s2.length()]<<endl;

    int index = s1.length();
    char ans[index];
    int i = s1.length(), j = s2.length();
    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans[index-1] = s1[i-1];
            i--; j--;
            index--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<ans<<endl;

}