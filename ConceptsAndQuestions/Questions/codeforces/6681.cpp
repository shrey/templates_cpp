

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

bool solve(string s, int n, int k){
    ll a = 0, b = 0;
    for(int i = 0; i<k; i++){
        char curr = s[i];
        for(int j = 0; (i+j*k)<(n); j++){
            if(s[i+j*k] == '1'){
                if(curr == '1' || curr == '?'){
                    curr = '1';
                }
                else {
                    return false;
                }
            }
            else if(s[i+j*k] == '0'){
                if(curr == '0' || curr == '?') {
                    curr = '0';
                }
                else{
                    return false;
                }
            }
        }
        if(curr == '0') a++;
        if(curr == '1') b++;
    }

    if(a>k/2 || b>k/2) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(solve(s,n,k)) {cout<<"YES"<<"\n";}
        else {
            cout<<"NO"<<"\n";
        }
    }
}
