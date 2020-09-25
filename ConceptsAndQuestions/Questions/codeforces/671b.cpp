

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
#define F first
#define S second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(ll i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)
#define forn(x,n) for(ll x = 0; x<n; x++)
#define imax INT_MAX
#define lmax LLONG_MAX
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
        ll x;
        cin>>x;
        if(x == 0){
            cout<<0<<"\n";
            continue;
        }
        ll ans = 1;
        ll p = 2;
        ll curr = p-1;
        ll cells = 1;
        while(cells<=x){
            ans++;
            x-=cells;
            p*=2;
            curr = p-1;
            cells = (curr*(curr+1))/2;
        }
        ans--;
        cout<<ans<<"\n";
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
