

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
#define fo(x,y) for(int i = x; i<y; i++)
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

bool is_possible(int a[], int n, int k, int t){
    int painters = 0;
    int i = 0;
    int currTime = 0;
    while(i<n){
        if(a[i]>t){
            return false;
        }
        currTime+=a[i];
        if(currTime>t){
            painters++;
            currTime = 0;
        }
        else{
            i++;
        }
    }
    if(currTime) painters++;
    if(painters<=k){
        return true;
    }else{
        return false;
    }

}

int min_time(int a[], int n, int k){
    int s = a[n-1];
    int e = 0;
    fo(n){
        e+=a[i];
    }
    int ans = -1;
    while(s<=e){
        int mid = (s+e)/2;
        // cout<<s<<" "<<mid<<" "<<e<<endl;
        if(is_possible(a,n,k,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }

    }
    return ans;
}

int main(){
    int k,n;
    cin>>k>>n;
    int a[n];
    fo(n){
        cin>>a[i];
    }
    cout<<min_time(a,n,k)<<endl;

}