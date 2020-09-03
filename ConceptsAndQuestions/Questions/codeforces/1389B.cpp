

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

int solve(int arr[], int n, int z, int k){
    int ans = 0;
    for(int lm = 0; lm<=z; lm++){ //left moves
        int pos = k-2*lm;
        int s = 0;
        int maxLeft = 0;
        for(int i = 0; i<=pos; i++){
            s+=arr[i];
            maxLeft = max(maxLeft,(arr[i]+arr[i+1]));
        }
        ans = max(ans,s + maxLeft*lm);
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,z;
        cin>>n>>k>>z;
        int arr[n];
        fo(n) cin>>arr[i];
        cout<<solve(arr,n,z,k)<<"\n";
    }
}