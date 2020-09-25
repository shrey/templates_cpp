

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

const ll M = 3e5+10;
ll arr[M];
ll n,q;
ll ans = 0;


void insert(ll i){
    if(i == 0 || i == n+1) return;
    if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) ans+=arr[i];
    if(arr[i]<arr[i-1] && arr[i]<arr[i+1]) ans-=arr[i];
}
void erase(ll i){
    if(i == 0 || i == n+1) return;
    if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) ans-=arr[i];
    if(arr[i]<arr[i-1] && arr[i]<arr[i+1]) ans+=arr[i];
}
int main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        ans = 0;
        cin>>n>>q;
        arr[0] = -1;
        arr[n+1] = -1;
        for(ll i = 1; i<=n; i++){
            cin>>arr[i];
        }
        for(ll i = 1; i<=n; i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) ans+=arr[i];
            if(arr[i]<arr[i-1] && arr[i]<arr[i+1]) ans-=arr[i];
        }
        cout<<ans<<"\n";
        while(q--){
            ll l,r;
            cin>>l>>r;
            erase(l);
            erase(l-1);
            erase(l+1);
            if(l!=r){
                if(r-1!=l+1 && r-1!=l) erase(r-1);
                if(l+1!=r) erase(r);
                erase(r+1);
            }
            swap(arr[l],arr[r]);
            insert(l);
            insert(l-1);
            insert(l+1);
            if(l!=r){
                if(r-1!=l+1 && r-1!=l) insert(r-1);
                if(l+1!=r) insert(r);
                insert(r+1);
            }
            cout<<ans<<"\n";
        }
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
