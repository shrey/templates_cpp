

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

string maxcompute(int dig, int s){
    if(dig == 0){
        return "";
    }
    if(s == 0){
        return ("0" + maxcompute(dig-1,s));
    }
    int k = 9;
    while(k>s) k--;
    return (to_string(k) + maxcompute(dig-1,s-k));
}

string mincompute(int m, int s){
     string lowest = "";
    while(s>9){
        lowest+='9';
        s-=9;
    }
    int dig = lowest.length();
    if(dig<m-1){
        lowest+=(to_string(s-1));
        dig++;
        while(dig<m-1){
            lowest+='0';
            dig++;
        }lowest+='1';
    }
    else{
        if(dig<m) lowest+=to_string(s);
    }
    reverse(lowest.begin(),lowest.end());
    return lowest;
}

int main(){
    int s,m;
    cin>>m>>s;
    if(s>(9*m) || (s<1 && m>1)){
        cout<<-1<<" "<<-1<<"\n";
        return 0;
    }
    cout<<mincompute(m,s)<<" "<<maxcompute(m,s)<<"\n";
    // cout<<maxcompute(m,s)<<endl;


}