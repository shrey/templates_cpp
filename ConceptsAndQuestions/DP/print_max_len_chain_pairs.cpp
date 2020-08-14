

//https://www.geeksforgeeks.org/print-maximum-length-chain-of-pairs/

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

struct pairs{
    int s;
    int e;
};

bool compare(pairs &a, pairs &b){
    return(a.e<b.e);
}

void print_sets(pairs p[], int pos, int total, int dp[], int prevMin){
    if(pos<0){
        return;
    }
    while(pos>0 && (dp[pos]!=total || (p[pos].e>prevMin))){
        pos--;
    }
    // cout<<p[pos].s<<" "<<p[pos].e<<endl;
    print_sets(p,pos-1,total-1,dp,p[pos].s);
    // cout<<pos<<endl;
    if(pos>=0 && dp[pos] == total && p[pos].e<prevMin)
        cout<<"("<<p[pos].s<<","<<p[pos].e<<")"<<" ";
    return;
}

int main(){
    pairs p[] = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};

    int n = sizeof(p)/sizeof(pairs);
    sort(p,p+n,compare);
    int dp[n];
    fo(n){
        dp[i] = 1;
    }
    int result = 0;
    dp[0] = 1;
    for(int i = 1; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(p[i].s>p[j].e){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        result = max(result,dp[i]);
    }
    print_sets(p,n-1,result,dp, INT_MAX);
    // fo(n){
    //     cout<<dp[i]<<" ";
    // }
    // fo(n){
    //     cout<<p[i].s<<" "<<p[i].e<<endl;
    // }
}