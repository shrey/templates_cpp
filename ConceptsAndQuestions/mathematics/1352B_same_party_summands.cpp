

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

void compute(ll n, ll k){
    if(k%2 == 0 && n%2 == 1){
        cout<<"NO"<<"\n";
        return;
    }
    if(n<k){
        cout<<"NO"<<"\n";
        return;
    }

    if(k%2 == 0){
        cout<<"YES"<<"\n";
        fo(k-1){
            cout<<1<<" ";
        }
        cout<<(n-(k-1))<<"\n";
    }
    else{
        if(n%2 == 0){
            if(n<2*k){
                cout<<"NO"<<"\n";
                return;
            }
            else{
                cout<<"YES"<<"\n";
                fo(k-1){
                    cout<<2<<" ";
                }
                cout<<(n-2*(k-1))<<"\n";
            }
        }else{
            cout<<"YES"<<"\n";
            fo(k-1) cout<<1<<" ";
            cout<<(n-(k-1))<<"\n";
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;//sum - n , number of summands - k
        cin>>n>>k;
        compute(n,k);
    }
}