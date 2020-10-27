

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
#include<cstring>

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
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
#define nl cout<"\n"

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

ll a[6];
const ll M = 2e5;
ll b[M],n;

void solve(){
    sort(a,a+6);
    sort(b,b+n);
    vp notes;
    for(ll i = 0; i<n; i++){
        for(ll j = 0;j<6; j++){
            notes.pb(mp(b[i]-a[j],i));
        }
    }
    sort(notes.begin(),notes.end());
    // for(auto x: notes){
    //     cout<<x.ff<<"()"<<x.sec<<"\n";
    // }
    ll ans = lmax;
    ll l = 0, r = 0, distinct = 0;
    map<ll,ll> marked;
    marked[notes[r].sec]++;
    distinct++;
    while(r<notes.size()){
        // cout<<l<<" "<<r<<"()"<<distinct<<"\n";
        if(distinct == n){
            ans = min(ans,notes[r].ff - notes[l].ff);
            marked[notes[l].sec]--;
            if(marked[notes[l].sec] == 0) distinct--;
            l++;
        }
        else{
            r++;
            if(r<notes.size()){
                marked[notes[r].sec]++;
                // if(notes[r].sec == 5){
                //     cout<<marked[notes[r].sec]<<"--<>\n";
                // }
                if(marked[notes[r].sec] == 1) {
                    distinct++;
                }
            }
        }
    }
    pr(ans);
}

int32_t main(){
    KOBE;
    fo(6) cin>>a[i];
    cin>>n;
    fo(n) cin>>b[i];
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