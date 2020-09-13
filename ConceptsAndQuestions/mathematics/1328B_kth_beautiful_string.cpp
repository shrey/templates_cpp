

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

ll bs(ll n, ll k){
    ll s = 0, e = n;
    ll ans = 0;
    while(s<=e){
        ll mid = (s+e)/2;
        if(k<(mid*(mid-1)/2)){
            e = mid-1;
        }
        else{
            ans = mid;
            s = mid+1;
        }
    }
    return ans;
}

int main(){
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        ll t = bs(n,k-1);
        ll pos2 = (k-1)-(t*(t-1))/2;
        // cout<<pos2<<" "<<t<<endl;
        string ans = "";
        fo(n){
            ans+='a';
        }
        ans[n-t-1] = 'b';
        ans[n-pos2-1] = 'b';
        cout<<ans<<"\n";
    }

}