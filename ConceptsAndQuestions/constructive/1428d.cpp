

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
#include<bitset>

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
#define imin INT_MIN
#define lmin LLONG_MIN
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define vb vector<bool>
#define pr(t) cout<<t<<"\n"
#define int long long
#define ql queue<ll>
#define qp queue<pair<ll,ll> >
#define endl "\n"

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


//code starts here

ll n;
const ll M = 2e5;
ll arr[M];

int32_t main(){
    KOBE;
    cin>>n;
    for(ll i = 1; i<=n; i++) cin>>arr[i];
    vl ones,twos,threes;
    ll twomatch[M], threematch[M];
    for(ll i = n; i>=1; i--){
        if(arr[i] == 1){
            ones.pb(i);
        }
        else if(arr[i] == 2){
            if(ones.size() == 0){
                pr(-1);
                return 0;
            }else{
                twomatch[i] = ones.back();
                ones.pop_back();
            }
            twos.pb(i);
        }
        else if(arr[i] == 3){
            if(threes.size()){
                threematch[i] = threes.back();
            }
            else if(twos.size()){
                threematch[i] = twos.back();
            }
            else if(ones.size()){
                threematch[i] = ones.back();
                ones.pop_back();
            }
            else{
                pr(-1);
                return 0;
            }
            threes.pb(i);
        }
    }
    vp targets;
    ll currow = 1;
    umap<ll,bool> visited;
    for(ll i = 1; i<=n; i++){
        if(arr[i] == 0 || visited[i]) continue;
        ll curcol = i;
        while(curcol!=0){
            visited[curcol] = true;
            if(arr[curcol] == 1){
                targets.pb(mp(currow,curcol));
                curcol = 0;
                currow++; //because no other target should be here
            }else if(arr[curcol] == 2){
                targets.pb(mp(currow,curcol));
                curcol = twomatch[curcol];
            }else if(arr[curcol] == 3){
                targets.pb(mp(currow,curcol));
                curcol = threematch[curcol];
                targets.pb(mp(currow,curcol));
                currow++;
            }
        }
    }
    cout<<targets.size()<<"\n";
    for(auto x: targets){
        cout<<x.first<<" "<<x.second<<"\n";
    }

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
