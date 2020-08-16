

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
        fo(n){
            cin>>arr[i];
        }
        int inc[n];
        int dec[n];
        int rule_break = 0;
        fo(n){
            inc[i] = 0;
            dec[i] = 0;
        }
        bool fresh = true;
        for(int i = 0; i<n; i++){
            if(fresh){
                inc[i] = 1;
                dec[i] = 1;
                fresh = false;
                continue;
            }
            if(arr[i]>arr[i-1]){
                inc[i] = inc[i-1]+1;
                dec[i] = 0;
            }
            else if(arr[i]<arr[i-1]){
                dec[i] = dec[i-1]+1;
                inc[i] = 0;
            }
            else{
                inc[i] = inc[i-1];
                dec[i] = dec[i-1];
            }
            if(inc[i]>4 || dec[i]>4){
                rule_break++;
                fresh = true;
            }
        }
        cout<<"Case #"<<k<<": "<<rule_break<<endl;
    }
}