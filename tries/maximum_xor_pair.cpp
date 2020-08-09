

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

class node{
    public:
        node* left; //for 0
        node* right; //for 1
};

class Trie{
    node* root;
    public:
        Trie(){
            root = new node();
        }


        void insert(int n){
            //loop
            node* temp = root;
            for(int i = 31; i>=0; i--){
                int bit = (n>>i)&1;
                if(bit == 0){
                    if(temp->left == NULL){
                        temp->left = new node();
                    }
                    temp = temp->left;
                }
                else{
                    if(temp->right == NULL){
                        temp->right = new node();
                    }
                    temp = temp->right;
                }
            }
        }

        //to find max xor

        int max_xor_helper(int value){
            int current_ans = 0;
            node* temp = root;
            for(int j = 31; j>=0; j--){
                int bit = (value>>j)&1;
                if(bit == 0){
                    if(temp->right){
                        temp = temp->right;
                        current_ans += (1<<j);
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->left){
                        temp = temp->left;
                        current_ans += (1<<j);
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
            return current_ans;
        }

        int max_xor_main(int arr[], int n){
            int max_xor = 0;
            fo(n){
                int val = arr[i];
                insert(val);
                int current_xor = max_xor_helper(val);
                // cout<<current_xor<<" ";
                max_xor = max(max_xor,current_xor);
            }
            return max_xor;
        }
};

int main(){
    int input[] = {3,10,5,25,2,8};
    Trie T;
    cout<<T.max_xor_main(input,6)<<endl;

}