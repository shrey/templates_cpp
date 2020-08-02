

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

int main(){
    int arr[] = {20,30,40,40,40,50,100,1100};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin>>key;

    bool present = binary_search(arr,arr+n,key);
    if(present){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }

    //to find the pos of the occurance
    auto it = lower_bound(arr,arr+n,key);
    cout<<"Lower Bound: "<<(it-arr)<<endl;
    it = upper_bound(arr,arr+n,key);
    cout<<"Upper Bound: "<<(it-arr-1)<<endl; //returns occurance of first el greater than key, so do -1
    //can also be used to calculate frequency

}