

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



ll recur(string &s, ll st, ll end, char ch){
    if(st>end) return 0;
    if(st == end){
        return (s[st] == ch)? 0 : 1;
    }
    //we check for both the halves
    ll mid = (st+end)/2;
    ll n1 = 0,n2 = 0;
    for(int i = st; i<=mid; i++){
        if(s[i]!=ch){
            n1++;
        }
    }
    for(int i = mid+1; i<=end; i++){
        if(s[i]!=ch) n2++;
    }
    // cout<<ch<<" : "<<"("<<st<<","<<end<<") = "<<n1<<","<<n2<<"\n";
    ll ans1 = n1+recur(s,mid+1,end,ch+1);
    ll ans2 = n2+recur(s,st,mid,ch+1);

    return min(ans1,ans2);
}

int main(){
    KOBE;
    ll t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        cout<<recur(s,0,n-1,'a')<<"\n";
    }
}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
// pass string or vector and such things with &
