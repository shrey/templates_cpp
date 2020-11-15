

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

int maxMerge(int arr[], int s, int e){
    int mid = (s+e)/2;
    int i = mid, j = mid-1;
    
}

int maxSum(int arr[], int s, int e){
    if(s>e){
        return 0;
    }else{
        return 1;
    }
    int mid = (s+e)/2;
    int l = maxSum(arr,s,mid);
    int r = maxSum(arr,mid+1,e);

}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        ll arr[n];
        fo(n){
            cin>>arr[i];
        }

    }
}