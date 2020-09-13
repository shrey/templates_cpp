

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

bool solve(ll arr[], ll n){
    ll aux[n];
    fo(n) aux[i] = arr[i];
    sort(aux,aux+n);
    ll minNum = aux[0];
    fo(n){
        if(aux[i]!=arr[i]){
            if(arr[i]%minNum) return false;
        }
    }
    return true;
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
        if(solve(arr,n)){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }

    }
}
