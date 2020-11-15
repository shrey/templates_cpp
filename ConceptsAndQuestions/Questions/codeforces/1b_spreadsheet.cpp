

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
#define KOBE ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)


using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

bool num(char ch){
    if((ch-'0')>=0 && (ch-'0')<=9) return true;
    return false;
}

bool rxcy(string s){
    if(s[0] == 'R'){
        ll i = 1;
        if(num(s[i])){
            while(i<s.length() && num(s[i])) i++;
            // cout<<i<<endl;
            if(s[i] == 'C'){
                // cout<<i<<endl;
                i++;
                if(num(s[i])){
                    while(i<s.length() && num(s[i])) i++;
                    if(i == s.length()) return true;
                }
            }
        }
    }
    return false;
}

int main(){
    KOBE;

    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        if(rxcy(s)){
            ll n = s.length();
            string cols = "";
            ll j = s.length()-1;
            while(s[j]!='C' && j>=0){
                cols+=s[j];
                j--;
            }
            reverse(cols.begin(), cols.end());
            ll col = stoi(cols);
            ll curr = 1;
            ll p = 0;
            while(curr<col){
                curr*=26;
                p++;
            }
            p--;
            //p is the power of 26 closest to col
            curr/=26;
            string ans = "";
            while(col>0){
                ll chnum = col/curr;
                ans+=('A'+(chnum-1));
                col%=(chnum*curr);// div by zero?
                curr/=26;
            }
            j = 1;
            string rNum = "";
            while(num(s[j]) && j<n){
                rNum+=s[j];
                j++;
            }
            string res = ans+rNum;
            cout<<res<<"\n";
        }
        else{
            string res = "";
            res+='R';
            string tno = "";
            ll n = s.length();
            ll j = n-1;
            while(num(s[j])){
                tno+=s[j];
                j--;
            }
            reverse(tno.begin(), tno.end());
            res+=tno;
            res+='C';
            ll p = 0;
            while(!num(s[p]) && p<n){
                p++;
            }

            j = 0;
            ll curr = pow(26,p-1);
            ll ans = 0;
            while(!num(s[j]) && j<n){
                ll cnum = s[j]-'A'+1;
                ans+=(cnum*curr);
                curr/=26;
                j++;
            }
            res+=(to_string(ans));
            cout<<res<<"\n";
        }
    }


}
