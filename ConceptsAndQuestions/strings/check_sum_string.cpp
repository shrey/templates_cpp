

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

string sumStr(string s1, string s2){
    int num = stoi(s1) + stoi(s2);
    return to_string(num);
}

bool checkSumStr(string s, int beg, int l1, int l2){
    string s1 = s.substr(beg,l1);
    string s2 = s.substr(beg+l1,l2);
    string s3 = sumStr(s1,s2);
    cout<<s1<<" "<<s2<<" "<<s3<<endl;
    int n = s3.length();
    if(n>s.length()-l1-l2-beg){
        return false;
    }
    if(s3 == s.substr(beg+l1+l2,n)){
        if(s.length() == (beg+l1+l2+n)){
            return true;
        }
        return checkSumStr(s,beg+l1,l2,n);
    }
    return false;
}

bool isSumStr(string s){
    int n = s.length();
    for(int i = 1; i<n; i++){
        for(int j = 1; (i+j)<n; j++){
            if(checkSumStr(s,0,i,j)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    string s;
    cin>>s;
    if(isSumStr(s)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}