

//Shrey Dubey

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
#include<climits>

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define sec second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define imax INT_MAX
#define lmax LLONG_MAX
#define vi vector<int>
#define vl vector<ll>
#define pr(t) cout<<t<<"\n"
#define int long long
ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        ll n0,n1,n2;
        cin>>n0>>n1>>n2;
        string ans = "";
        if(n2){
            fo(n2+1) ans+='1';
        }
        if(n0) fo(n0+1) ans+='0';
        if(ans.length() == 0){
            ans+='1';
            fo(n1){
                if(i%2 == 0){
                    ans+='0';
                }else{
                    ans+='1';
                }
            }
        }
        else if(ans[ans.length()-1] == '1'){
            fo(n1){
                if(i%2 == 0){
                    ans+='0';
                }else{
                    ans+='1';
                }
            }
        }else if(ans[ans.length()-1] == '0'){
            if(n2) n1--;
            fo(n1){
                if(i%2 == 0){
                    ans+='1';
                }else{
                    ans+='0';
                }
            }
        }
        cout<<ans<<"\n";
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs