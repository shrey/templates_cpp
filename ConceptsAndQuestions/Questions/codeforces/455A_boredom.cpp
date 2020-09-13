

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


#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
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

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin>>n;
    ll freq[100001] = {0};
    ll maxNum = INT_MIN;
    fo(n) {
        ll x;
        cin>>x;
        maxNum = max(x,maxNum);
        freq[x]++;
    }
    // sort(arr,arr+n);
    // fo(n) cout<<arr[i]<<" ";cout<<endl;
    ll dp[100001] = {0};
    dp[0] = 0;
    dp[1] = freq[1];
    for(ll i = 2; i<=maxNum; i++){
        dp[i] = max(dp[i-1],dp[i-2] + i*freq[i]);
    }
    cout<<dp[maxNum]<<"\n";
}
