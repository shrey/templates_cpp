#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};


struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


void inorder(struct node *root)
{
    if (root == NULL) return;
        inorder(root->left);
        printf(" %d", root->key);
        inorder(root->right);

}
void postOrder(struct node *root)
{
    if (root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->key);
}
void preOrder(struct node *root){
    if (root == NULL)
              return;


    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

struct node* insert(struct node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}


struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
unsigned int countNodes(struct node* root)
{
    int c=1;
        if (root==NULL)
            return 0;
        else{
            c += countNodes(root->left);
            c += countNodes(root->right);
            return c;
        }
}

int height(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {

       int lheight = height(node->left);
       int rheight= height(node->right);


       if (lheight > rheight)
           return(lheight+1);
       else return(rheight+1);
   }
}
int search(struct node* root, int x)
{
    if(root==NULL){
            return 0;
        }
        else if(root->key==x){
            return 1;
        }
        else if(root->key<x){
            return(search(root->right,x));
        }
        else{
            return(search(root->left,x));
        }
}

int main(){
    struct node *root;
    root=NULL;
    int choice;
    int x;
    do{
        printf("\n1.Insert \n2.Delete \n3. Inorder \n4. Preorder");
        printf("\n5.Postorder \n6.Height \n7.Count \n8.Search \n9.Exit");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter number to be inserted: ");
                scanf("%d",&x);
                root=insert(root,x);
                break;

            case 2:
                printf("\nEnter number to be deleted: ");
                scanf("%d",&x);
                root=deleteNode(root,x);
                break;

            case 3:
                inorder(root);
                break;

            case 4:
                preOrder(root);
                break;

            case 5:
                postOrder(root);
                break;

            case 6:
                x=height(root);
                printf("\nHeight of the tree is:   %d",x);
                break;

            case 7:
                x=countNodes(root);
                printf("\nNumber of nodes in the tree are:   %d",x);
                break;

            case 8:;
                int z;
                printf("\nEnter number to be searched: ");
                scanf("%d",&x);
                z=search(root,x);
                if(z==1){
                    printf("Found\n");
                }
                else if(z==0){
                    printf("Doesn't exist\n");
                }
                break;

            case 9:
                printf("\n THANK YOU FOR INTERACTING \n");
                return 0;

        }
    }while(choice<10);
}






 /* struct node *curr = root;


    struct node* parent = NULL;


    while (curr != NULL && curr->key != key)
    {

        parent = curr;


        if (key < curr->key)
            curr = curr->left;
        else
            curr = curr->right;
    }


    if (curr == NULL)
    {
       printf("Key Not found");
        return;
    }

    if (parent == NULL)
        printf("The node with key %d is root node",key);

    else if (key < parent->key)
        printf("Given key is left node of node with key %d" ,parent->key);

    else
       printf( "Given key is right node of node with key %d " ,parent->key);*/