

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
        int freq;
        bool terminal;
        node(char a){
            data = a;
            terminal = false;
            freq = 1;
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
                else{
                    temp->freq++;
                }
                temp = temp->children[w[i]];
            }
            temp->terminal = true;
        }
        
};
