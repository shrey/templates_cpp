

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
        ll n;
        cin>>n;
        ll num = n;
        vector<ll> fact;
        bool flag = false;
        umap<ll,bool>used;
        for(ll i = 2; (i*i)<=n; i++){
            if(n%i == 0){
                fact.pb(i);
                n/=i;
                if(n%i == 0){
                    flag = true;
                    while(n%i == 0){
                        n/=i;
                    }
                }
            }
        }
        if(n>1) fact.pb(n);

        if(fact.size() == 2 && !flag){
            cout<<fact[0]<<" "<<fact[0]*fact[1]<<" "<<fact[1]<<"\n";
            cout<<1<<"\n";
            continue;
        }
        else{
            n = num;
            vector<ll> d;
            for(ll i = 2; (i*i)<=n; i++){
                if(n%i == 0){
                    d.pb(i);
                    d.pb(n/i);
                }
            }
            d.pb(n);
            sort(d.begin(),d.end());
            vl connect(fact.size());
            for(ll i = 0; i<fact.size(); i++){
                ll p = fact[i];
                ll q = fact[(i+1)%(fact.size())];
                for(ll j = 0; j<d.size(); j++){
                    if(!used[d[j]] && d[j]%p == 0 && d[j]%q == 0){
                        connect[i] = d[j];
                        used[d[j]] = true;
                        break;
                    }
                }
            }
            for(ll i = 0; i<fact.size(); i++){
                ll p = fact[i];
                used[p] = true;
                cout<<p<<" ";
                for(ll j = 0; j<d.size(); j++){
                    if(!used[d[j]] && d[j]%p == 0){
                        used[d[j]] = true;
                        cout<<d[j]<<" ";
                    }
                }
                if(fact.size()>1){
                    cout<<connect[i]<<" ";
                }
            }
            cout<<'\n'<<0<<'\n';
        }
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
