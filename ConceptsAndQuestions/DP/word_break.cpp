//https://www.geeksforgeeks.org/word-break-problem-dp-32/



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

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;


bool compute(){
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};
    int n = sizeof(dictionary)/sizeof(string);
    umap<string,int> dict;
    fo(n){
        dict[dictionary[i]] = 1;
    }
    string str;
    cin>>str;
    bool dp[str.length()+1];
    int size = str.length();
    memset(dp,false,sizeof dp);
    for(int i = 1; i<=str.length(); i++){
        if(!dp[i] && dict[str.substr(0,i)]){
            dp[i] = true;
        }
        if(dp[i]){
            if(i == size){
                return true;
            }
            for(int j = i+1; j<=size; j++){
                if(!dp[j] && dict[str.substr(i,j-i)]){
                    dp[j] = true;
                }
                if(j == size && dp[j]){
                return true;
                }
            }

        }
    }
    return false;
}

int main(){
    if(compute()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}