

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

using namespace std;
typedef long long ll;
typedef long double ld;

#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define prDouble(x) cout<<fixed<<setprecision(15)<<x<<"\n" //to print decimal numbers
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

ld comp(ld t1,ld s1,ld p1, ld t2, ld s2, ld p2){
    ld x;
    p1+=((t2-t1)*s1);
    x = (p1*s2+p2*s1)/(s2+s1);
    if(x<0) x*=(-1.0);
    ld t = t2+((x-p1)/s1);
    return t;
}

ld solve(ld arr[], ll n, ld len){
    ld t1[n],t2[n];
    ld s1[n],s2[n];
    ld currSp = 2.0;
    t1[0] = arr[0];
    s1[0] = currSp;
    for(ll i = 1; i<n; i++){
        t1[i] = t1[i-1]+(arr[i]-arr[i-1])/(currSp);
        currSp+=1.0;
        s1[i] = currSp;
    }
    t2[n-1] = (len-(arr[n-1]));
    currSp = 2.0;
    s2[n-1] = currSp;
    for(ll i = n-2; i>=0; i--){
        t2[i] = t2[i+1]+((arr[i+1]-arr[i])/currSp);
        currSp+=1.0;
        s2[i] = currSp;
    }
    // fo(n) cout<<t1[i]<<" ";cout<<"\n";
    // fo(n) cout<<t2[i]<<" ";cout<<"\n";
    ll pos = 1;
    if(t1[0]>=t2[0]){
        return comp(0,1,0,t2[0],s2[0],arr[0]);
    }
    if(t1[n-1]<=t2[n-1]){
        return comp(t1[n-1],s1[n-1],arr[n-1],0,1,len);
    }
    while(t1[pos]<t2[pos]){
        if(t1[pos] == t2[pos]) return t1[pos];
        pos++;
    }
    // cout<<pos<<"\n";
    // fo(n) cout<<s1[i]<<" ";cout<<"\n";
    // fo(n) cout<<s2[i]<<" ";cout<<"\n";
    return comp(t1[pos-1],s1[pos-1],arr[pos-1],t2[pos],s2[pos],arr[pos]);
}

int32_t main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        ld len;
        ll n;
        cin>>n>>len;
        ld arr[n];
        fo(n) cin>>arr[i];
        prDouble(solve(arr,n,len));
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// use map for large inputs
