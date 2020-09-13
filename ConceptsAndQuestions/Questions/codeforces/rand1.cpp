

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


#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
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

bool solve(string s){
    ll n = s.length();
    ll t1 = 0, t2 = 0;
    ll s1 = INT_MIN,s2 = INT_MIN;
    for(int i = 0; i<n-1; i++){
        if(s[i] == 'A' && s[i+1] == 'B'){
            if(s1<0){
                s1 = i;
            }
            else if(abs(s1-s2) == 1 && abs(i-s2)!=1){
                s1 = i;
            }
        }
        if(s[i] == 'B' && s[i+1] == 'A'){
            if(s2<0){
                s2 = i;
            }
            else if(abs(s1-s2) == 1 && abs(i-s1)!=1){
                s2 = i;
            }
        }
    }
    if(s1>=0 && s2>=0 && abs(s1-s2)>1){
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    cin>>s;
    if(solve(s)){
        YES;
    }
    else{
        NO;
    }
}
