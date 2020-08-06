

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
#define fo(x,y) for(long long i = x; i<y; i++)
#define fo(n) for(long long i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
long long modulo = 1e9 + 7;


bool is_possible(long long a[], long long n, long long m, long long ht){
    long long wood = 0;
    fo(n){
        if(a[i]>ht){
            wood+=(a[i]-ht);
        }
    }
    if(wood>=m){
        return true;
    }
    else{
        return false;
    }
}

long long max_ht(long long a[], long long n, long long m){
    long long s = 0, e = a[n-1];
    long long ans = 0;
    while(s<=e){
        long long mid = (s+e)/2;
        if(is_possible(a,n,m,mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;
}

int main(){
    long long n,m;
    cin>>n>>m;
    long long arr[n];
    fo(n){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<max_ht(arr,n,m)<<endl;
}