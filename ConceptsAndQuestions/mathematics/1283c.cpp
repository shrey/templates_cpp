

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
#define vp vector<pair<ll,ll> >
#define pr(t) cout<<t<<"\n"
#define int long long
ll mod = 1e9 + 7;

ll cl(ld a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }
}

ll flr(ld a){
    return (ll) a;
}

ll n;
const ll M = 2e5+100;
ll arr[M];

void solve(){
    vl give(M,0), take(M,0), loops;
    for(ll i = 1; i<=n; i++){

        if(arr[i]){
            // cout<<"here"<<arr[i]<<"\n";
            give[i]++;
            take[arr[i]]++;
        }
    }
    for(ll i = 1; i<=n; i++){
        if(arr[i] == 0 && take[i] == 0){
            loops.pb(i);
        }
    }
    if(loops.size() == 1){
        for(ll i = 1; i<=n; i++){
            if(i!=loops[0] && give[i] == 0){
                give[i]++;
                arr[i] = loops[0];
                take[loops[0]]++;
                break;
            }
        }
    }
    else if(loops.size()>1){
        // cout<<loops.size()<<"()\n";
        fo(loops.size()){
            ll cur = loops[i];
            ll nxt = loops[(i+1)%loops.size()];
            // cout<<cur<<" "<<nxt<<"\n";
            give[cur]++;
            take[nxt]++;
            arr[cur] = nxt;
        }
    }
    vl ins,outs;
    for(ll i = 1; i<=n; i++){
        if(give[i] == 0) ins.pb(i);
        if(take[i] == 0) outs.pb(i);
    }
    fo(outs.size()){
        arr[ins[i]] = outs[i];
    }
    for(ll i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<"\n";

}

int32_t main(){
    KOBE;
    cin>>n;
    fo(n) cin>>arr[i+1];
    solve();
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs


//problem ideas
//check piegonhole wherever possible
//there might be many instances of limited answers like 0,1,2 only
// see suffix and prefix
//don't be obsessed with binary search
