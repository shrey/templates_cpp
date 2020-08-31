//https://www.geeksforgeeks.org/count-ways-increase-lcs-length-two-strings-one/



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

int toInt(char ch){
    return (ch-'a');
}

int main(){
    string str1,str2;
    cin>>str1>>str2;
    int n = str1.length();
    int m = str2.length();
    vector<int> pos[26];
    fo(m){
        pos[toInt(str2[i])].pb(i+1);
    }
    int lcsl[n+2][m+2], lcsr[n+2][m+2];
    memset(lcsl,0,sizeof lcsl);
    memset(lcsr,0,sizeof lcsr);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                lcsl[i][j] = lcsl[i-1][j-1]+1;
            }
            else{
                lcsl[i][j] = max(lcsl[i-1][j],lcsl[i][j-1]);
            }
        }
    }
    for(int i = n; i>0; i--){
        for(int j = m; j>0; j--){
            if(str1[i-1] == str2[j-1]){
                lcsr[i][j] = lcsr[i+1][j+1]+1;
            }
            else{
                lcsr[i][j] = max(lcsr[i][j+1],lcsr[i+1][j]);
            }
        }
    }
    int ways = 0;
    for(int i = 1; i<=n; i++){
        for(char ch = 'a'; ch<='z'; ch++){
            for(int j = 0; j<pos[toInt(ch)].size(); j++){
                int p = pos[toInt(ch)][j];
                if(lcsl[i][p-1] + lcsr[i+1][p+1] == lcsl[n][m]){
                    ways++;
                }
            }
        }
    }
    cout<<ways<<endl;
}