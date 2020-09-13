

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
int modulo = 1e9 + 7;

int main(){
    KOBE;
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        fo(n) cin>>arr[i];
        ll freq[200] = {0};
        fo(n) freq[arr[i]]++;
        ll i = 0;
        while(freq[i]>0){
            i++;
        }
        ll ans = 0;
        ans+=i;
        i = 0;
        while(freq[i]>0 && (freq[i])>=2){
            i++;
        }
        ans+=i;
        cout<<ans<<"\n";

    }
}

/*
3
3
1 2 3
4
0 0 1 1
5
0 1 2 0 1

*/
