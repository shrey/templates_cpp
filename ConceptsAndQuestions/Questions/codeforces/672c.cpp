

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

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define ff first
#define ss second
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

ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

int main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        ll arr[n];
        fo(n) cin>>arr[i];
        ll pkm[n];
        bool flag = true;
        ll k = 0;
        pkm[0] = arr[0];
        ll i = 1;
        while(i<n){
            if(flag){
                if(arr[i]>=pkm[k]){
                    pkm[k] = arr[i];
                }
                else{
                    pkm[k+1] = arr[i];
                    k++;
                    flag = false;
                }
            }
            else{
                if(arr[i]<=pkm[k]){
                    pkm[k] = arr[i];
                }else{
                    pkm[k+1] = arr[i];
                    k++;
                    flag = true;
                }
            }
            i++;
        }
        ll ans = 0;
        ll res = INT_MIN;
        for(ll i = 0; i<=k; i++){
            if(i%2 == 0){
                ans+=pkm[i];
            }
            else{
                ans-=pkm[i];
            }
            res = max(res,ans);
        }
        cout<<res<<"\n";
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
