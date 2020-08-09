

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
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

class Node{
    public:
        char data;
        umap<char,Node*> children;
        bool terminal;
        int freq;

        Node(char d){
            data = d;
            terminal = false;
            freq = 1;
        }
};

class Trie{
    Node* root;
    int cnt;

    public:
        Trie(){
            root = new Node('\0');
            cnt = 0;
        }
        void insert(char *w){
            Node* temp = root;
            for(int i = 0; w[i]!='\0'; i++){
                char ch = w[i];
                if(temp->children.count(ch)){
                    temp = temp->children[ch];
                    temp->freq++;
                }
                else{
                    Node* n = new Node(ch);
                    temp->children[ch] = n;
                    temp = n;
                }
            }
            temp->terminal = true;
        }

        void compute(char *w){
            Node* temp = root;
            char ans[100];
            for(int i = 0; w[i]!='\0'; i++){
                char ch = w[i];
                if(temp->children.count(ch)){
                    temp = temp->children[ch];
                    if(temp->freq == 1){
                        ans[i] = temp->data;
                        ans[i+1] = '\0';
                        cout<<ans<<" ";
                        break;
                    }
                    else{
                        ans[i] = temp->data;
                    }
                }
                else{
                    cout<<"Not Valid"<<endl;
                }
            }
        }

        bool find(char *w){
            Node* temp = root;
            for(int i = 0; w[i]!='\0'; i++){

                char ch = w[i];
                if(temp->children.count(ch) == 0){
                    return false;
                }
                temp = temp->children[ch];

            }
            return temp->terminal;
        }
};


int main(){
    Trie t;
    char words[][10] = {"cobra","dog","dove","duck"};
    for(int i = 0; i<4; i++){
        t.insert(words[i]);
    }
    for(int i = 0; i<4; i++){
        t.compute(words[i]);
    }
}