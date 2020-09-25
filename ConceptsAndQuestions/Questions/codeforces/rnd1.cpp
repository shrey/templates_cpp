

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

 bool solve(ll arr[], ll n, ll reqSum){
    ll p1 = 0, p2 = 0, currSum = arr[0];
    while(p2<n && p1<n && p1<=p2){
        if(reqSum>currSum){
            p2++;
            if(p2 == n) return false;
            currSum+=arr[p2];
        }
        else if(reqSum<currSum){
            currSum-=arr[p1];
            p1++;
            if(p1 == n) return false;
            if(p1>p2){
                p2++;
                currSum+=arr[p2];
            }
        }
        else{
            for(ll i = p1; i<=p2; i++){
                cout<<arr[i]<<" ";
            }cout<<"\n";
            return true;
        }
    }
    return false;
}

int main(){
    KOBE;
    ll arr[] = {1,4,20,3,10,5};
    ll n = sizeof(arr)/sizeof(ll);
    ll reqSum;
    cin>>reqSum;
    if(!solve(arr,n,reqSum)){
        cout<<-1<<"\n";
    }


}


//common errors
// row - n, col - m always and loop var
// see the freq of numbers carefully
// see if there's array overflow
