

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


    bool solve(string s, int x){
        string w;
        fo(s.length()){
            w.pb('1');
        }
        for(int i = 0; i<s.length(); i++){
            if(s[i] =='0'){
                if(i>=x){
                    w[i-x] = '0';
                }
                if((i+x)<s.length()){
                    w[i+x] = '0';
                }
            }
        }
        // cout<<w<<endl;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '1'){
                if(!((i>=x && w[i-x] == '1') || (((i+x)<s.length()) && w[i+x] == '1'))){
                    cout<<-1<<"\n";
                    return false;
                }
            }
        }
        cout<<w<<"\n";
        return true;
    }

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; int x;
        cin>>s>>x;
        solve(s,x);
    }
}