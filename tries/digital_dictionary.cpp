

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


#define prDouble(x) cout<<fixed<<setprecision(10)<<x //to print decimal numbers
#define pb push_back
#define F first
#define S second
#define umap unordered_map
#define fo(x,y) for(int i = x; i<y; i++)
#define fo(n) for(int i = 0; i<n; i++)
#define nch '\0'
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;


class node{
    public:
        char data;
        map<char,node*> children;
        bool terminal;
        node(char a){
            data = a;
            terminal = false;
        }
};

class Trie{
    node* root;
    public:
        Trie(){
            root = new node('\0');
        }
        void insert(char *w){
            node* temp = root;
            for(int i = 0; w[i]!='\0'; i++){
                if(!temp->children.count(w[i])){
                    temp->children[w[i]] = new node(w[i]);
                }
                temp = temp->children[w[i]];
            }
            temp->terminal = true;
        }

        void dfs(node* src,string ans){
            if(src->terminal){
                cout<<ans<<endl;
            }
            for(auto it: src->children){
                string ans2 = ans+it.first;
                // cout<<ans2<<" ";
                dfs(it.second,ans2);
            }
            return;
        }

        bool find(char *w){
            node* temp = root;
            string ans = "";
            for(int i = 0; w[i]!='\0'; i++){
                if(temp->children.count(w[i])){
                    temp = temp->children[w[i]];
                    ans.push_back(w[i]);
                }
                else{
                    insert(w);
                    cout<<"No Suggestions"<<endl;
                    return false;
                }
            }

            dfs(temp,ans);
            // cout<<"END"<<endl;
            return true;
            //we have found the word and now we do dfs
        }



};

int main(){
    int n;
    cin>>n;
    Trie T;
    for(int i = 0; i<n; i++){
        char word[10000];
        cin>>word;
        T.insert(word);
    }
    int q;
    cin>>q;
    while(q--){
        char word[10000];
        cin>>word;
        T.find(word);
        // cout<<"end"<<endl;
    }
}