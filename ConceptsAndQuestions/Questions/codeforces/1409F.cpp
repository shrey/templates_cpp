

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

ll substrings(string s, string t){
    ll ans = 0;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == t[0]){
            for(int j = i+1; j<s.length(); j++){
                if(s[j] == t[1]) ans++;
            }
        }
    }
    return ans;
}

int main(){
    ll n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;
    vector<vector<vector<int> > > dp(n+1,vector<vector<int> >(n+1,vector<int>(n+1,INT_MIN)));
    //dp[i][ck][cnt0] i is position, ck is chances, cnt0 is the number of t0s in substring (0,i)
    dp[0][0][0] = 0;
    for(int i = 0; i<n; i++){
        for(int ck = 0; ck<=k; ck++){
            for(int cnt0 = 0; cnt0<=n; cnt0++){
                if(dp[i][ck][cnt0] == INT_MIN) continue;
                int e0 = s[i]==t[0];
                int e1 = s[i] == t[1];
                int e01 = t[0] == t[1];
                dp[i+1][ck][cnt0+e0] = max(dp[i+1][ck][cnt0+e0],dp[i][ck][cnt0]+(e1?cnt0 : 0));\
                if(ck<k){
                    dp[i+1][ck+1][cnt0+1] = max(dp[i+1][ck+1][cnt0+1],dp[i][ck][cnt0] + (e01?cnt0 : 0));
                    dp[i+1][ck+1][cnt0+e01] = max(dp[i+1][ck+1][cnt0+e01],dp[i][ck][cnt0] + cnt0);
                }
            }
        }
    }
    int ans = 0;
    for(int ck = 0; ck<=k; ck++){
        for(int cnt0 = 0; cnt0<=n; cnt0++){
            ans = max(ans,dp[n][ck][cnt0]);
        }
    }
    cout<<ans<<"\n";

}