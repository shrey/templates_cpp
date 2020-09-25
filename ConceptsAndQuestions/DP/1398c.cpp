

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


#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map
#define mp make_pair
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)


using namespace std;
typedef long long ll;
typedef long double ld;
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
        string s;
        cin>>s;
        vector<int> v;
        for(int i = 0; i<n; i++){
            v.pb((s[i]-'0'));
        }
        umap<ll,ll> m;
        m[0] = 1;
        ll val = 0;
        ll ans = 0;
        for(ll i = 0; i<n; i++){
            val+=v[i];
            val--;
            cout<<"("<<val<<")"<<" = "<<m[val]<<endl;
            ans+=m[val];
            m[val]++;
        }
        cout<<ans<<"\n";
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
