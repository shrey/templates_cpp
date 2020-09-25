

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
#define MAX 1000
using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

int dp[1000][3];


// CPP Program to count substrings which are


// Returns count of substrings divisible by 8
// but not by 3.
int count(char s[], int len)
{
    int cur = 0, dig = 0;
    int sum[MAX], dp[MAX][3];

    memset(sum, 0, sizeof(sum));
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    // Iterating the string.
    for (int i = 1; i <= len; i++)
    {
        dig = int(s[i-1])-48;
        cur += dig;
        cur %= 3;

        sum[i] = cur;

        // Prefix sum of number of substrings whose
        // sum of digits mudolo 3 is 0, 1, 2.
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-1][2];

        dp[i][sum[i]]++;
    }

    int ans = 0, dprev = 0, value = 0, dprev2 = 0;

    // Iterating the string.
    for (int i = 1; i <= len; i++)
    {
        dig = int(s[i-1])-48;

        // Since single digit 8 is divisible
        // by 8 and not by 3.
        if (dig == 8)
            ans++;

        // Taking two digit number.
        if (i-2 >= 0)
        {
            dprev = int(s[i-2])-48;  // 10th position
            value = dprev*10 + dig;  // Complete 2 digit
                                     // number

            if ((value%8 == 0) && (value%3 != 0))
                ans++;
        }

        // Taking 3 digit number.
        if (i-3 >= 0)
        {
            dprev2 = int(s[i-3])-48; // 100th position
            dprev  = int(s[i-2])-48;  // 10th position

            // Complete 3 digit number.
            value = dprev2*100 + dprev*10 + dig;

            if (value%8 != 0)
                continue;

            // If number formed is divisible by 8 then
            // last 3 digits are  also divisible by 8.
            // Then all the substring ending at this
            // index is divisible.
            ans += (i-2);

            // But those substring also contain number
            // which are not divisible by 3 so
            // remove them.
            ans -= (dp[i-3][sum[i]]);
        }
    }

    return ans;
}

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