

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

ll min(ll a, ll b){
    if(a<b) return a;
    return b;
}

int main(){
    ll n;
    cin>>n;
    ll MAX = 10000000000000000;
    ll arr[n];
    fo(n) cin>>arr[i];
    sort(arr,arr+n);
    ll c = 1;
    while(pow(c,n-1)<arr[n-1]) c++;
    ll ans = 10000000000000000;
    for(int i = 2; i<=c; i++){
        ll currAns = 0;
        for(int j = 0; j<n; j++){
            ll p = pow(i,j);
            if(currAns+abs(p-arr[j])>MAX) break;
            currAns+=abs(p-arr[j]);
        }
        ans = min(ans,currAns);
    }
    ll sm = 0;
    fo(n) sm+=(arr[i]-1);
    ans = min(sm,ans);
    cout<<ans<<"\n";

}