

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
const ll mod = 1e9 + 7;

const ll M = 1e5+1;

vector<ll> rgr[M];
vector<ll> bgr[M];

ll n,k;

ll pow(ll n, ll k){
    if(k == 0){
        return 1;
    }
    ll a = (pow(n,k/2));
    if(k%2){
        return ((((a*a)%mod)*(n%mod))%mod);
    }
    return ((a*a)%mod);
}

vector<bool> visited(M, false);
ll ans = 0;

ll cntNode(ll curr){
    visited[curr] = true;
    ll ans = 1;
    for(auto x: rgr[curr]){
        if(!visited[x]){
            ans+=cntNode(x);
        }
    }
    return ans;
}
//subtract all non black seq
void compute(){
    for(ll i = 1; i<=n; i++){
        if(rgr[i].size() && !visited[i]){

            ll cnt = cntNode(i);
            // cout<<i<<"="<<cnt<<","<<pow(cnt,k)<<endl;s
            ans = (ans - pow(cnt,k));
            ans+=mod;
            ans%=mod;
        }
        if(rgr[i].size() == 0){
            ans--;
        }
    }
    ans = ans%mod;
    cout<<ans<<"\n";
}

int main(){
    KOBE;
    cin>>n>>k;
    fo(n-1){
        ll x,y,col;
        cin>>x>>y>>col;
        if(col == 0){
            rgr[x].pb(y);
            rgr[y].pb(x);
        }
        else{
            bgr[x].pb(y);
            bgr[y].pb(x);
        }
    }
    ans = pow(n,k);
    // cout<<ans<<"\n";
    compute();

}
