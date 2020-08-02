

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


bool canPlaceCows(int stalls[], int n, int cows, int min_sep){
    int last_cow = stalls[0];
    int cnt = 1;
    for(int i = 1; i<n; i++){
        if((stalls[i]-last_cow)>=min_sep){
            last_cow = stalls[i];
            cnt++;
            if(cnt == cows){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int stalls[] = {1,2,4,8,9};
    int n = sizeof(stalls)/sizeof(int);
    int cows = 3;
    int s = 0;
    int e = stalls[n-1]-stalls[0];
    int ans = 0;
    while(s<=e){
        int mid = (s+e)/2;

        bool cows_rakh_paye = canPlaceCows(stalls,n,cows,mid);

        if(cows_rakh_paye){
            // cout<<mid<<endl;
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }

    }
    cout<<ans<<endl;
}