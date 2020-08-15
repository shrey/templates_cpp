

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

double dp[100][100][100];

double f1(int r, int p, int s){ //rock survival
    if(r == 0 || s == 0){
        return 0;
    }
    if(p == 0){
        return 1;
    }
    if(dp[r][p][s]!=-1.0){
        return dp[r][p][s];
    }
    double ret = 0.0;
    double total = r*s + p*s + s*p;
    ret+=f1(r-1,p,s)*(r*p/total);
    ret+=f1(r,p-1,s)*(s*p/total);
    ret+=f1(r,p,s-1)*(r*s/total);
    dp[r][p][s] = ret;
    return ret;
}

double f2(int r, int p, int s){     //for scissor
    if(r == 0){
        return 1;
    }
    if(p == 0 || s == 0){
        return 0;
    }
    if(dp[r][p][s]!=-1.0){
        return dp[r][p][s];
    }
    double ret = 0.0;
    double total = r*s + p*s + s*p;
    ret+=f2(r-1,p,s)*((r*p)/total);
    ret+=f2(r,p-1,s)*((s*p)/total);
    ret+=f2(r,p,s-1)*((r*s)/total);
    dp[r][p][s] = ret;
    return ret;

}

double f3(int r, int p, int s){ //for paper
    if(s == 0){
        return 1;
    }
    if(p == 0 || r == 0){
        return 0;
    }
    if(dp[r][p][s]!=-1.0){
        return dp[r][p][s];
    }
    double ret = 0.0;
    double total = r*s + p*s + s*p;
    ret+=f3(r-1,p,s)*((r*p)/total);
    ret+=f3(r,p-1,s)*((s*p)/total);
    ret+=f3(r,p,s-1)*((r*s)/total);
    dp[r][p][s] = ret;
    return ret;
}

int main(){
    int r,p,s;
    cin>>r,p,s;

    memset(dp,-1.0,sizeof dp);
    cout<<f1(r,p,s)<<" ";
    memset(dp, -1.0, sizeof dp);
    cout<<f2(r,p,s)<<" ";
    memset(dp,-1.0,sizeof dp);
    cout<<f3(r,p,s)<<endl;
}