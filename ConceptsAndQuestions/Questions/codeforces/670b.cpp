

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
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)


using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;



ll solve(ll arr[], ll n){
    vector<ll> pos,neg;
    for(int i = 0; i<n; i++){
        if(arr[i]<0){
            neg.pb(arr[i]);
        }
        else{
            pos.pb(arr[i]);
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<int>());
    ll n1 = pos.size(), n2 = neg.size();
    ll ans = LLONG_MIN;
    for(int i = 0; i<=5; i++){
        ll curr = 1;
        if(i>pos.size() || (5-i)>neg.size()) continue;
        for(int j = 1; j<=i; j++){
            curr*=(pos[n1-j]);
        }
        ll rem = 5-i;
        for(int j = 1; j<=rem; j++){
            curr*=(neg[n2-j]);
        }
        ans = max(ans,curr);
    }
    // fo(n2) cout<<neg[i]<<" ";cout<<endl;
    if(neg.size()>=5){
        ll curr = 1;
        for(int i = 0; i<5; i++){
            curr*=neg[i];
        }
        ans = max(curr,ans);
    }

    return ans;
}


int main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        fo(n) cin>>arr[i];
        cout<<solve(arr,n)<<"\n";
    }
}
