

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
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll arr[n];
        fo(n) cin>>arr[i];
        ll max_elem = INT_MIN, sum = 0;
        fo(n){
            if(arr[i]>max_elem) max_elem = arr[i];
            sum+=arr[i];
        }
        if(max_elem*2>(sum) || sum%2 == 1){
            cout<<"T"<<"\n";
        }
        else{
            cout<<"HL"<<"\n";
        }



    }
}