

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
int M = 1e9 + 7;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        fo(n) cin>>arr[i];
        ll maxi = 0;
        fo(n){
            if(arr[i]>arr[maxi]) maxi = i;
        }
        swap(arr[0],arr[maxi]);
        ll currGcd = arr[0];
        for(int i = 1; i<n-1; i++){
            ll maxg = i;
            ll currg = gcd(arr[i],currGcd);
            for(int j = i+1; j<n; j++){
                ll temp= gcd(currGcd,arr[j]);
                if(temp>currg){
                    maxg = j;
                    currg = temp;
                }
            }
            swap(arr[i],arr[maxg]);
            currGcd = currg;
        }
        fo(n) cout<<arr[i]<<" ";cout<<endl;
    }
}
