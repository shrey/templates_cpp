

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
typedef long double ld;
ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }

}


ll solve(string s, ll x, ll y){
    ll ans = 0;
    for(auto c: s){
        if(c-'0' == x){
            ans++;
            swap(x,y);
        }
    }
    if(x != y && ans%2 == 1){
        ans--;
    }
    return ans;
}

int main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll ans = INT_MIN;
        for(int i = 0; i<10; i++){
            for(int j = 0; j<10; j++){
                ans = max(ans,solve(s,i,j));
            }
        }
        cout<<s.length()-ans<<"\n";
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
