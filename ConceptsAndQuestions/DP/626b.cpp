

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
#define bgr cout<<"BGR"<<"\n";

ll mod = 1e9 + 7;

ll cl(double a){
    if(a>(ll) a){
        return (ll)a+1;
    }
    else{
        return (ll)a;
    }

}

void solve(ll r, ll g, ll b){
    if(r && g && b){
        bgr;
        return;
    }
    ll mx = max(r,max(g,b));
    if((g+b) == 0 || (r+g) == 0 || (r+b) == 0){

        if(r == mx) cout<<"R"<<"\n";
        if(g == mx) cout<<"G"<<"\n";
        if(b == mx) cout<<"B"<<"\n";
        return;
    }
    if(g>1 && b>1){
        bgr;
        return;
    }
    if(r>1 && b>1){
        bgr;
        return;
    }
    if(r>1 && g>1){
        bgr;
        return;
    }
    if(r>1){
        cout<<"BG"<<"\n";
        return;
    }
    if(b>1){
        cout<<"GR"<<"\n";
        return;
    }
    if(g>1){
        cout<<"BR"<<"\n";
        return;
    }
    if(r && g){
        cout<<"B"<<"\n";
        return;
    }
    if(b && g){
        cout<<"R"<<"\n";
        return;
    }
    if(r && b){
        cout<<"G"<<"\n";
        return;
    }

}

int main(){
    KOBE;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll r = 0, b = 0, g = 0;
    fo(s.length()){
        if(s[i] == 'R') r++;
        if(s[i] == 'G') g++;
        if(s[i] == 'B') b++;
    }
    solve(r,g,b);
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
