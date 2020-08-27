

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

int dp[1000][3];

int recur(string s, int i, int m){
    if(i == s.length()){
        return 0;
    }
    cout<<i<<" "<<m<<endl;
    if(dp[i][m]!=-1) return dp[i][m];
    if(i<2){
        int num = stoi(s.substr(0,i+1));
        int x = s[i]-'0';
        dp[i][m] = (num%8==0 && (m+x)%3!=0)? 1+ recur(s,i+1,(m+x)%3) : recur(s,i+1,(m+x)%3);
        return dp[i][m];
    }
    int last3 = stoi(s.substr(i-2,3));

    int x = s[i]-'0';
    dp[i][m] = (last3%8 == 0 && (m+x)%3!=0)? 1+recur(s,i+1,(m+x)%3) : recur(s,i+1,(m+x)%3);
    return dp[i][m];


}

int findSubs(string s){
    int ans = 0;
    memset(dp,-1,sizeof dp);
    for(int i = 0; i<s.length(); i++){
        ans+=recur(s,i,0);
    }
    for(int i = 0; i<s.length(); i++){
        for(int j = 0; j<3; j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<findSubs(s)<<endl;
}