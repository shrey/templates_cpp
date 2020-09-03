

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
#include <numeric>



#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map
#define mp make_pair

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

int main(){
    int n;
    cin>>n;

    ll arr[n];

    fo(n) cin>>arr[i];
    if(n == 1){
        cout<<1<<" "<<1<<"\n";
        cout<<-arr[0]<<"\n";
        cout<<1<<" "<<1<<"\n";
        cout<<0<<"\n";
        cout<<1<<" "<<1<<"\n";
        cout<<0<<"\n";
        return 0;
    }
    cout<<1<<" "<<n<<"\n";
    fo(n-1){
        cout<<-(n*arr[i])<<" ";
        arr[i]-=(n*arr[i]);
    }cout<<"0\n";
    cout<<1<<" "<<n-1<<"\n";
    fo(n-1){
        cout<<(-arr[i])<<" ";
    }cout<<"\n";
    cout<<n<<" "<<n<<"\n";
    cout<<(-arr[n-1])<<"\n";

}