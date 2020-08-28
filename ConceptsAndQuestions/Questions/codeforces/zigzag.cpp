

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

int solve(int arr[], int n){
    umap<int,int> freq;
    fo(n){
        freq[arr[i]]++;
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        int s = i, e = i+1;
        umap<int,int> h1;
        umap<int,int> h2;
        h2 = freq;
        h2[arr[s]]--;
        h2[arr[e]]--;
        while(e<n){
            if(arr[s] == arr[e]){
                auto c1 = h1;
                auto c2 = h2;
                for(int j = s+1; j<e; j++){
                    if(c1[arr[j]]>0 && c2[arr[j]]>0){
                        // cout<<s<<" "<<j<<" "<<e<<endl;
                        // cout<<"("<<h1[arr[j]]<<")";
                        // cout<<"("<<h2[arr[j]]<<")"<<endl;
                        ans+=(c1[arr[j]]*c2[arr[j]]);
                        c1[arr[j]] = 0; c2[arr[j]] = 0;
                    }
                }
            }
            h1[arr[e]]++;
            if(e<n-1) h2[arr[e+1]]--;
            e++;
        }
        freq[arr[i]]--;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        int arr[n];
        fo(n){
            cin>>arr[i];
        }
        cout<<solve(arr,n)<<"\n";
    }
}