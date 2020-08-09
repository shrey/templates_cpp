

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
        node* right; // for 1
};

class Trie{
    node* root;
    public:
        Trie(){
            root = new node();
        }
        void insert(int num){
            node* temp = root;
            for(int i = 31; i>=0; i--){
                int bit = (num>>i)&1;
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
        int findMaxXorPair(int val){
            node* temp = root;
            int ans = 0;
            for(int i = 31; i>=0; i--){
                int bit = (val>>i)&1;
                if(bit == 0){
                    if(temp->right){
                        ans+=(1<<i);
                        temp = temp->right;
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    if(temp->left){
                        ans+=(1<<i);
                        temp = temp->left;
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
            return ans;
        }
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    fo(n){
        cin>>arr[i];
    }
    int lbest[n],rbest[n];
    int left_value = 0;
    Trie tl;
    tl.insert(0);
    for(int i = 0; i<n; i++){
        left_value = left_value^arr[i];
        lbest[i] = max((i == 0)? 0 : lbest[i-1], tl.findMaxXorPair(left_value));
        tl.insert(left_value);
    }
    Trie tr;
    tr.insert(0);
    int right_value = 0, ans = INT_MIN;
    for(int i = n-1; i>=0; i--){
        right_value = right_value^arr[i];
        rbest[i] = max((i == n-1)? 0: tr.findMaxXorPair(right_value),rbest[i+1]);
        tr.insert(right_value);
        ans = max(rbest[i] + (i == 0? INT_MIN : lbest[i-1]),ans);
    }
    cout<<ans<<endl;
}