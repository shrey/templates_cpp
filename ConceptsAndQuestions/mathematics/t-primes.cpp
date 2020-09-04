

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
bool prime[1000001];
const ll N = 1000000;
void seive(){
    fo(N){
        prime[i+1] = true;
    }
    for(ll p = 2; p*p<=N; p++){
        if(prime[p]){
            for(ll i = p*p; i<=N; i+=p){
                prime[i] = false;
            }
        }
    }
}

int main(){
    ll t;
    cin>>t;
    seive();
    while(t--){
        ll n;
        cin>>n;
        ll t = sqrt(n);
        if(n == 1){
            cout<<"NO"<<"\n";
            continue;
        }
        bool is_tprime = false;
        if(t*t == n){
            if(prime[t]){
                is_tprime = true;
            }
        }
        if(is_tprime){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }

}