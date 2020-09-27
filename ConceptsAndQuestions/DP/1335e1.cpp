

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
        ll n;
        cin>>n;
        ll arr[n];
        fo(n) cin>>arr[i];
        ll freq[n][n][50];
        forn(i,n){
            forn(j,n){
                forn(k,27){
                    freq[i][j][k] = 0;
                }
            }
        }
        for(ll i = 0; i<n; i++){
            for(ll j = i; j<n; j++){
                if(j == i){
                    freq[i][j][arr[i]]++;
                }else{
                    for(ll k = 1; k<=26; k++){
                        freq[i][j][k] = freq[i][j-1][k];
                    }
                    freq[i][j][arr[j]]++;
                }
            }
        }
        ll ans = 1;
        for(ll i = 1; i<n-1; i++){
            for(ll j = i; j<n-1; j++){
                ll currMax = INT_MIN;
                ll othMax = INT_MIN;
                for(ll k = 1; k<=26; k++){
                    currMax = max(freq[i][j][k],currMax);
                    othMax = max(min(freq[0][i-1][k],freq[j+1][n-1][k]),othMax);
                }
                ans = max(ans,currMax+othMax*2);
            }
        }
        for(ll i = 0; i<n; i++){
            for(ll j = 1; j<=26; j++){
                ans = max(ans,freq[0][i][j]);
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
