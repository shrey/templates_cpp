

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

bool is_possible(int arr[], int n, int kids, int max_pages){
    int currPages = 0;
    int i = 0;
    while(i<n){
        currPages+=arr[i];
        if(currPages>max_pages){
            // cout<<currPages<<endl;
            kids--;
            currPages = 0;
            if(kids==0) return false;
        }
        else{
            i++;
        }
    }
    return true;
}


int min_concecutive(int arr[], int n, int kids){
    int e = 0;
    for(int i = 0; i<n; i++){
        e+=arr[i];
    }
    int s = arr[n-1];
    int ans = INT_MAX;
    while(s<=e){
        int mid = (s+e)/2;
        if(is_possible(arr,n,kids,mid)){
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
    int arr[] = {10,20,30,40};
    int n = sizeof(arr)/sizeof(int);
    int kids = 2;
    cout<<min_concecutive(arr,n,kids)<<endl;

}