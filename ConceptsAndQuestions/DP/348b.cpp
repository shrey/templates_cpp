

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
    ll v;
    cin>>v;
    umap<ll,ll> lit;
    ll minLit = INT_MAX;
    ll minDig = -1;
    fo(9){
        cin>>lit[i+1];
        if(minLit>=lit[i+1]){
            minLit = lit[i+1];
            minDig = max(i+1,minDig);
        }
    }
    string ans = "";
    ll dig_no = v/minLit;
    fo(dig_no){
        ans+=('0'+minDig);
    }
    v-=(dig_no*minLit);
    fo(9){
        lit[i+1]-=(minLit);
    }
    for(int i = 0; i<ans.length(); i++){
        if(v>0){
            ll curr = 9;
            while(v<lit[curr] && curr>=0){
                curr--;
            }
            ans[i] = ('0'+curr);
            v-=lit[curr];
        }
    }
    if(ans == ""){
        cout<<-1<<"\n";
        return 0;
    }
    cout<<ans<<"\n";
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
