

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
#include<numeric>
#include<array>


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
#define nl cout<<"\n"
#define re cin >>
#define pll pair<ll,ll>
#define FOR(a,b) for(ll i = a; i<=b; i++)
#define all(x) x.begin(),x.end()

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

const ll M = 2e5+100;
ll a[M],n,freq[M+10] = {0};
bool mark[M] = {0};
ll dx[] = {-1,0,1};

void solve(){
    re n; fo(n) re a[i];
    sort(a,a+n);
    fo(n) freq[a[i]]++;
    set<ll> s;
    for(ll i = 1; i<M; i++){
        ll k = freq[i];
        if(k == 0) continue;
        if(mark[i-1]){
            if(mark[i]){
                s.insert(i+1);
                mark[i+1] = true;
            }else{
                // cout<<i<<"()"<<k<<"\n";
                s.insert(i); mark[i] = true;
                if(k > 1) s.insert(i+1), mark[i+1] = true;
            }
        }
        else if(mark[i]){
            s.insert(i+1);
            mark[i+1] = true;
        }
        else{
            for(ll j = 0; j<min((ll)3,k); j++){
                mark[i + dx[j]] = true;
                s.insert(i + dx[j]);
            }
        }
    }

    ll mx = s.size();
    // while(!s.empty()){
    //     cout<<*s.begin()<<" ";
    //     s.erase(s.begin());
    // }nl;
    ll i = 1;
    ll mn = 0;
    while(i<M){
        if(freq[i]){
            i += 3;
            mn++;
        }
        else{
            i++;
        }
    }
    cout<<mn<<" "<<mx<<"\n";
    // fo(n) cout<<a[i]<<" ";nl;
}

int32_t main(){
    KOBE;
    ll t;
    // re t;
    t = 1;
    while(t--) solve();
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
// try to find repeating pattern in matrices
