

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

int nmb(char s){
    return (s-'0');
}

string solve(string num){
    int n = num.length();

    for(int i = 0; i<n; i++){
            string curr = "";
            curr+=num[i];
            if(stoi(curr)%8 == 0){
                return curr;
            }
        for(int j = i+1; j<n; j++){
            string curr2 = "";
            curr2 += num[i];
            curr2+=num[j];
            // cout<<curr2<<endl;
            if(stoi(curr2)%8 == 0){
                return curr2;
            }
            for(int k = j+1; k<n; k++){
                string curr3 = "";
                curr3 += curr2;
                curr3+=num[k];
                // cout<<curr3<<endl;
                if(stoi(curr3)%8 == 0){
                    return curr3;
                }
            }
        }
    }
    return "";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string num;
    cin>>num;
    string ans = solve(num);
    if(ans!=""){
        YES;
        cout<<ans<<"\n";
    }
    else{
        NO;
    }
}
