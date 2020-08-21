// https://www.geeksforgeeks.org/vertex-cover-problem-set-2-dynamic-programming-solution-tree/


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

class TreeNode{
    public:
        int data,vc;
        TreeNode* left;
        TreeNode* right;
};

TreeNode* newNode(int data){
    TreeNode* root = new TreeNode();
    root->left = NULL;
    root->right = NULL;
    root->data = data;
    root->vc = 0;
    return root;
}

int traverse(TreeNode* root){

    if(root == NULL){
        return 0;
    }
    // cout<<root->data<<endl;
    if(root->vc!=0){
        return root->vc;
    }
    int ans1 = 0,ans2 = 0;
    if(root->left){
        ans1+= (1 + traverse(root->left->left) + traverse(root->left->right));
    }
    if(root->right){
        ans1+= (1 + traverse(root->right->left) + traverse(root->right->right));
    }
    ans2 = (1 + traverse(root->right) + traverse(root->left));
    root->vc = min(ans1,ans2);
    return min(ans1,ans2);
}

int main(){
    TreeNode *root             = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
    cout<<traverse(root)<<endl;
}