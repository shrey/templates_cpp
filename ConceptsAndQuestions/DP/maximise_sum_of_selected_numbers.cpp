

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


#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

int main(){
    int arr[] = {1, 2, 3};
    int n = sizeof(arr)/sizeof(int);
    umap<int,int> ans;
    int maximum = 0;
    fo(n){
        ans[arr[i]]++;
        maximum = max(maximum,arr[i]);
    }
    for(int i = 2; i<=maximum; i++){
        ans[i] = max(ans[i-1],ans[i-2] + ans[i]*i);
    }
    cout<<ans[maximum]<<endl;
}