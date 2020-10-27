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
#include<climits>
#include<bitset>
#include<cstring>
#include<numeric>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[6];
    for(int i=0;i<6;i++){
        cin>>a[i];
    }
    int n;
    cin>>n;
    int b[n];
    set<pair<int,int> >s;
    for(int i=0;i<n;i++){
        cin>>b[i];
        for(int j=0;j<6;j++){
            s.insert(make_pair(b[i]-a[j],i));
        }
    }
    map<int,int>m;
    for(auto i:s){
        m[i.second]=0;
    }
    for(auto i:s){
        m[i.second]++;
    }
    for(auto i:s){
        if(m[i.second]>1){
            m[i.second]--;
            s.erase(*s.begin());
        }else{
            break;
        }
    }
    auto p=*s.begin();
    int ab=p.first;
    int op=0;
    set<int>ss;
    for(auto i:s){
        ss.insert(i.second);
        if(ss.size()==n){
            op=i.first;
            break;
        }
    }
    cout<<op-ab<<"\n";

    return 0;
}