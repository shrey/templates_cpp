

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

int solve(string s, int k){
    umap<char,int> freq;
    int dis = 0;
    fo(s.length()){
        if(freq[s[i]] == 0) dis++;
        freq[s[i]]++;
    }
    int count = 0;
    for(int i = 0; i<s.length(); i++){

        int end = s.length()-1;
        int tempDis = dis;
        auto cfreq = freq;
        while(tempDis>=k && end>=i){
            if(tempDis == k){
                count++;
            }
            cfreq[s[end]]--;
            if(cfreq[s[end]] == 0) tempDis--;
            end--;
        }

        freq[s[i]]--;
        if(freq[s[i]] == 0) dis--;
        if(dis<k) break;
    }
    return count;
}

int main(){
    string s; int k;
    cin>>s>>k;
    cout<<solve(s,k)<<endl;

}