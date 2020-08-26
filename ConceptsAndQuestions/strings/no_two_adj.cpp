// https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/


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

void swapChars(string &s1, int i, int j){
    char temp = s1[i];
    s1[i] = s1[j];
    s1[j] = temp;
}

struct Key{
    char ch;
    int freq;
    bool operator<(const Key &k) const{
        return freq<k.freq;
    }
};

void reArrangeStr(string s){
    string str = "";
    priority_queue<Key> pq;
    int count[26] = {0};
    int n = s.length();
    fo(n){
        count[s[i]-'a']++;
    }
    for(char ch = 'a'; ch<='z'; ch++){
        if(count[ch-'a']){
            Key c = {ch,count[ch-'a']};
            pq.push(c);
        }
    }
    Key prev = {'#',-1};
    while(!pq.empty()){
        Key t = pq.top();
        pq.pop();
        str+=t.ch;
        if(prev.freq>0){
            pq.push(prev);
        }
        t.freq--;
        prev = t;
    }
    if(str.length() == s.length()){
        cout<<str<<endl;
    }
    else{
        cout<<"Not Possible"<<endl;
    }
}

int main(){
    string s;
    cin>>s;
    int n = s.length();
    reArrangeStr(s);
    for(int i = 1; i<s.length(); i++){
        if(s[i] == s[i-1]){
            int j = i+1;
            while(j<n && s[i-1] == s[j]){
                j++;
            }
            if(j == n){
                cout<<"Not Possible"<<endl;
                return 0;
            }
            swapChars(s,i,j);
        }
    }
    cout<<s<<endl;
}