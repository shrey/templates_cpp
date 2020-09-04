

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

ll max(ll a, ll b){
    return (a>b)? a:b;
}

double dmax(double a, double b){
    return(a>b)?a:b;
}

int main(){
    ll n,l;
    cin>>n>>l;
    ll arr[n];
    fo(n) cin>>arr[i];
    sort(arr,arr+n);
    int maxDiff = INT_MIN;
    for(ll i = 1; i<n; i++){
        maxDiff = max(maxDiff,arr[i]-arr[i-1]);
    }
    double ans = maxDiff;
    ans = ans/2.0;
    ans = dmax(ans,dmax(arr[0]-0,l-arr[n-1]));
    prDouble(ans);
}