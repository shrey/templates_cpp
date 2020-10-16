

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
#define imin INT_MIN
#define lmin LLONG_MIN
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<ll,ll> >
#define pr(t) cout<<t<<"\n"
#define int long long
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

vl b(3);

ll ans = 0;

void oper(){
    // fo(3) cout<<b[i]<<" ";cout<<"\n";
    if(b[0]<0 || b[1]<0){
        return;
    }
    ll tb = min((b[0]-b[2])/2,b[1]);
    b[0]-=tb*2;
    b[1] -= tb;
    // cout<<tb<<"()\n";
    ans+=tb;
    sort(b.rbegin(),b.rend());
}

ll solve(){
    if(b[0]>2*(b[0]+b[1]+b[2]-b[0])){
        return (b[0]+b[1]+b[2] - b[0]);
    }else{
        return (b[0]+b[1]+b[2])/3;
    }
}

int32_t main(){
    KOBE;
    cin>>b[0]>>b[1]>>b[2];
    sort(b.rbegin(),b.rend());
    cout<<solve()<<"\n";
    // if(b[0]-b[2]<=1){
    //     cout<<(b[0]+b[1]+b[2])/3<<"\n";
    //     return 0;
    // }
    // while(b[0]-b[2]>1 && (b[0]>0 && b[1]>0)){
    //     oper();
    // }
    // ans+=min(b[0],min(b[1],b[2]));
    // cout<<ans<<"\n";
    // ll tb = (b[0]-b[2])/2;
    // b[0]-=(tb*2);
    // b[1]-=tb;
    // ans+=(tb);
    // if(b[1]-b[2]>1 && b[0]>b[2]){
    //     tb = min((b[1]-b[2])/2,b[0]-b[2]);
    //     b[1]-=2*tb;
    //     b[0]-=tb;
    //     ans+=tb;
    // }
    // ans+=(min(b[0],min(b[1],b[2])));
    // cout<<ans<<"\n";
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
