

//https://www.geeksforgeeks.org/number-substrings-divisible-6-string-integers/

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
    if(dp[i][m] !=-1){
        return dp[i][m];
    }
    int x = s[i]-'0';
    dp[i][m] = ((x+m)%3 == 0 && (x%2) == 0)? 1 + recur(s,i+1,(x+m)%3): recur(s,i+1,(x+m)%3);
    return dp[i][m];
}

int count_subs(string s){
    memset(dp,-1,sizeof dp);
    int ans = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '0'){
            ans++;
        }
        else{
            ans+=recur(s,i,0);
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<count_subs(s)<<endl;

}