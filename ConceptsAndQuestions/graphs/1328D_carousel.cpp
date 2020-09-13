

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

void solve(ll arr[], ll n){
    ll k = 0;
    bool there = false;
    bool ex = false;
    ll rep = INT_MAX;
    for(ll i = 1; i<n; i++){
        if(arr[i] == arr[i-1]){
            rep = min(rep,i-1);
            there = true;
        }
        else{
            k++;
        }
    }

    if(k == 0){
        cout<<1<<"\n";
        fo(n)cout<<1<<" ";cout<<"\n";
        return;
    }
    if(n%2 == 0){
        cout<<2<<"\n";
        fo(n/2) cout<<1<<" "<<2<<" ";cout<<"\n";
        return;
    }
    if(there){
        cout<<2<<"\n";
        int curr = 1;
        for(int i = 0; i<n; i++){
            if(i == rep){
                cout<<curr<<" "<<curr<<" ";
                i++;
            }else{
                cout<<curr<<" ";
            }
            curr = (curr == 1)? 2: 1;
        }cout<<"\n";
        return;
    }
    if(arr[0] == arr[n-1]){
        ll temp = 1;
        cout<<2<<"\n";
        fo(n-1){
            cout<<temp<<" ";
            temp = temp == 1? 2 : 1;
        }cout<<1<<"\n";
        return;
    }
    cout<<3<<"\n";
    fo(n/2) cout<<1<<" "<<2<<" "; cout<<3<<"\n";

}

int main(){
    KOBE;
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll arr[n];
        fo(n) cin>>arr[i];
        solve(arr,n);

    }
}
