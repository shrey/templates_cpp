

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

class personCompare{
    public:
        bool operator()(pair<string,int> p1, pair<string,int> p2){
            return p1.second<p2.second;
        }
};

int main(){
    int no_of_transactions,friends;
    cin>>no_of_transactions>>friends;
    map<string,int> net;
    string x,y;
    int amt;
    while(no_of_transactions--){
        cin>>x>>y>>amt;
        net[x]-=amt;
        net[y]+=amt;
    }
    multiset<pair<string,int>,personCompare > m;
    for(auto it: net){
        if(it.second!=0){
            m.insert(mp(it.first,it.second));
        }
    }
    int cnt = 0;
    while(!m.empty()){
        auto high = prev(m.end());
        auto low = m.begin();
        int debit = low->second;
        int credit = high->second;
        string debit_person = low->first;
        string credit_person = high->first;
        m.erase(low); m.erase(high);
        int settelled_amt = min(-debit,credit);
        debit+=settelled_amt;
        credit-=settelled_amt;
        cout<<debit_person<<" gives "<<settelled_amt<<" to "<<credit_person<<endl;
        if(debit) m.insert(mp(debit_person,debit));
        if(credit) m.insert(mp(credit_person,credit));
        cnt++;
    }
    cout<<cnt<<endl;
}