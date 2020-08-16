

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
    int t;
    cin>>t;
    for(int k = 1; k<=t; k++){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        int count = 0;
        int lastMax = INT_MIN;
        for(int i = 0; i<n; i++){
            if(i == 0){
                if(arr[i]>arr[i+1]){
                    count++;
                }
            }
            else if(i == n-1){
                if(arr[i]>lastMax){
                    count++;
                }
            }
            else{
                if(arr[i]>lastMax && arr[i]>arr[i+1]){
                    count++;
                }
            }
            lastMax = max(lastMax,arr[i]);
        }
        cout<<"Case #"<<k<<": "<<count<<"\n";
    }
}