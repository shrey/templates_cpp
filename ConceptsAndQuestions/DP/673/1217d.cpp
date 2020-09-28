

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


const ll M = 1e5+1;
ll arr[M]; ll n;
vector< vl > ans;

void oper(ll i, ll j, ll x){
    arr[i] -= i*x;
    arr[j] += i*x;
    vl temp;
    temp.pb(i);
    temp.pb(j);
    temp.pb(x);
    ans.pb(temp);
}

bool solve(){
    ll sum = 0;
    for(ll i = 1; i<=n; i++) sum+=arr[i];
    if(sum%n!=0){
        return false;
    }
    ll res = sum/n;
    for(ll i = 2; i<=n; i++){
        if(arr[i]%i){
            oper(1,i,i-(arr[i]%i));
        }
        oper(i,1,arr[i]/i);
    }
    for(ll i = 2; i<=n; i++){
        oper(1,i,res);
    }
    for(ll i = 1; i<=n; i++){
        if(arr[i]!=res) return false;
    }
    if(ans.size()>3*n) return false;
    cout<<ans.size()<<"\n";
    for(auto x: ans){
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
    }
    return true;
}

int32_t main(){
    ll t;
    cin>>t;
    while(t--){
        cin>>n;
        for(ll i = 1; i<=n; i++){
            cin>>arr[i];
        }
        if(!solve()){
            cout<<"-1\n";
        }
        ans.clear();
    }
    KOBE;
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
