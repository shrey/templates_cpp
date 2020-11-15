

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

#define fo(n) for(int i = 0; i<n; i++)
#define fnd(stl, data) find(stl.begin(), stl.end(), data)

using namespace std;
typedef long long ll;
int modulo = 1e9 + 7;

class node{
    public:
        node *left;
        node *right;
};

class Trie{
    public:
        node* root;
        Trie(){
            root = new node();
        }

        void insert(int num){
            node* temp = root;
            for(int i = 31; i>=0; i--){
                int bit = (num>>i)&1;
                if(bit){
                    if(!temp->right){
                        temp->right = new node();
                    }
                    temp = temp->right;
                }else{
                    if(!temp->left){
                        temp->left = new node();
                    }
                    temp = temp->left;
                }
            }
        }

        void doXor(int num){
            
        }

};

int main(){

}