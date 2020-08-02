

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

int find_no(int a[], int n, int key){
    int s = 0;
    int e = n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(a[mid] == key){
            return mid;
        }
        else if(a[s]<=a[mid]){
            if(key<=a[mid] and key >=a[s]){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        else{
            if(key >= a[mid] && key<=a[e]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    fo(n){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<find_no(arr,n,key)<<endl;
}