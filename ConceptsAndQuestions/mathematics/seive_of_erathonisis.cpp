

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

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;


int prime_seive(int n){
    bool prime[n+1];
    memset(prime,true,sizeof prime);
    for(int p = 2; p*p<=n; p++){
        if(prime[p] == true){
            for(int i = p*p; i<=n; i+=p){
                prime[i] = false;
            }
        }
    }
    int cnt = 0;
    for(int i = 2; i<=n; i++){
        if(prime[i]){
            // cout<<i<<" ";
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    cout<<prime_seive(n)<<endl;
}