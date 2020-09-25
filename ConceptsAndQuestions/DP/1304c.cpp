

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

const ll M = 2e5+1;

bool solve(){
    ll n,m;
    cin>>n>>m;
    ll time[M],l[M],r[M];
    fo(n){
        cin>>time[i]>>l[i]>>r[i];
    }
    ll mn = m, mx = m;
    ll prev = 0;
    for(int i = 0; i<n; i++){

        mx+=(time[i]-prev);
        mn-=(time[i]-prev);
        // cout<<time[i]<<" = "<<"("<<mn<<","<<mx<<")"<<endl;
        if(l[i]>(mx) || (mn)>r[i]){
            return false;
        }
        else{
            mn = max(l[i],mn);
            mx = min(r[i],mx);
            prev = time[i];
        }
    }
    return true;
}

int main(){
    KOBE;
    ll t;
    cin>>t;
    while(t--){
        if(solve()){
            YES;
        }
        else{
            NO;
        }


    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
