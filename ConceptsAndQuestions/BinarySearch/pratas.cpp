

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


bool is_possible(int a[], int n, int pratas, int time){
    int total = 0;
    for(int i = 0; i<n; i++){
        int temp = a[i];
        int curr_time = 0;
        while(curr_time<=time){
            curr_time+=a[i];
            a[i]+=temp;
            total++;
        }
        if(curr_time>time){
            total--;
        }
    }
    if(total>=pratas) return true;
    return false;
}

int min_time(int a[], int n, int pratas){
    int s = 0;
    int e = a[0]*(pratas)*(pratas+1)/2;
    // cout<<e<<endl;
    int ans = INT_MAX;
    while(s<=e){
        int mid = (s+e)/2;
        if(is_possible(a,n,pratas,mid) == true){
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
    int t;
    cin>>t;
    int pratas;
    fo(t){
        cin>>pratas;
        int n;
        cin>>n;
        int arr[n];
        fo(n){
            cin>>arr[i];
        }
        cout<<min_time(arr,n,pratas)<<endl;
        // int time;
        // cin>>time;
        // if(is_possible(arr,n,pratas,time)){
        //     cout<<"Yes"<<endl;
        // }
        // else{
        //     cout<<"NO"<<endl;
        // }
    }
}