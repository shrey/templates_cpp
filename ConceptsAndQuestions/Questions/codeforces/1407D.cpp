

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
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin>>n;
    ll arr[n];
    fo(n) cin>>arr[i];
    ll i = 0;
    ll ans = 0;
    while(i<n-1){
        if(arr[i+1]>arr[i]){
            ll curr = arr[i];
            ll prev = i;
            i++;
            while(i<n && arr[i]>curr){
                i++;
            }
            if(i == n) {i = prev+1; ans++;}
            else{ ans++;}
        }
        else if(arr[i]>arr[i+1]){
            ll curr = arr[i];
            ll prev = i;
            i++;
            while(i<n && arr[i]<curr) i++;
            if(i == n) {i = prev+1; ans++;}
            else {ans++;}
        }else{
            i++;
            ans++;
        }
    }
    cout<<ans<<"\n";
}
