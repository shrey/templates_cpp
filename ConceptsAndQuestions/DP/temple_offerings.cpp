

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
    int a[] = {1, 2, 2};
    int n = sizeof(a)/sizeof(int);
    int inc[n], dec[n];
    fo(n){
        inc[i] = 0;
        dec[i] = 0;
    }
    int curr = 0;
    for(int i = 1; i<n; i++){
        if(a[i]>a[i-1]){
            curr++;
            inc[i] = curr;
        }
        else{
            curr = 0;
        }
    }
    curr = 0;
    for(int i = n-2; i>=0; i--){
        if(a[i]>a[i+1]){
            curr++;
            dec[i] = curr;
        }
        else{
            curr = 0;
        }
    }
    int ans = 0;
    fo(n){
        cout<<inc[i]<<" "<<dec[i]<<endl;
    }
    for(int i = 0; i<n; i++){
        ans+=max(inc[i],dec[i]);
    }
    ans+=n;
    cout<<ans<<endl;
}