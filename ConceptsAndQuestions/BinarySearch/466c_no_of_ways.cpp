

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

ll ways(ll arr[], ll n){
    ll s = 0;
    fo(n) s+=arr[i];
    if(s%3!=0) return 0;
    ll cnt[n], sum[n];
    ll ss = 0;
    for(int i = n-1; i>=0; i--){
        ss+=arr[i];
        cnt[i] = 0;
        if(ss == s/3) cnt[i] = 1;
        sum[i] = cnt[i];
        if(i<n-1) sum[i]+=sum[i+1];
    }
    ll ans = 0;
    ll currSum = 0;
    for(int i = 0; i<n-2; i++){
        currSum += arr[i];
        if(currSum == s/3){
            ans+=sum[i+2];
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n];
    ll pref[n];
    fo(n) cin>>arr[i];
    cout<<ways(arr,n)<<"\n";
}
