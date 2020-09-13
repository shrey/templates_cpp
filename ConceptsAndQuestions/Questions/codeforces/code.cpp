

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

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll x[n], y[n];
        fo(n){
            cin>>x[i];
        }
        fo(n) cin>>y[i];
        sort(x,x+n);
        //find longest segment whose last and first diff<=k
        ll l[n];
        ll r[n];
        ll i = 1, j = 0;
        l[0] = 1;
        while(i<n){
            while(x[i]-x[j]>k){
                j++;
            }
            l[i] = max(l[i-1],(i-j)+1);
            i++;
        }
        i = n-2; j = n-1;
        r[n-1] = 1;
        while(i>=0){
            while(x[j]-x[i]>k){
                j--;
            }
            r[i] = max(r[i+1],(j-i+1));
            i--;
        }
        // fo(n) cout<<l[i]<<" "; cout<<endl;
        // fo(n) cout<<r[i]<<" "; cout<<endl;
        ll ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans,l[i]+(i<n-1?r[i+1]:0));
        }
        cout<<ans<<"\n";
    }
}