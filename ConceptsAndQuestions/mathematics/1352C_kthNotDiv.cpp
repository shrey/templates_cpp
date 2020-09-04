

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

ll cpt(ll num, ll n){
    ll a = num/n;
    return (num-a);
}

ll findNum(ll n, ll k){
    ll s = 0, e = n*k;
    ll ans = -1;
    while(s<=e){
        ll mid = (s+e)/2;
        ll curr = cpt(mid,n);
        if(curr == k){
            ans = mid;
            e = mid-1;
        }
        else if(curr<k){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        cout<<findNum(n,k)<<"\n";
    }
}