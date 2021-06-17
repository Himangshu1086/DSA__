#include<bits/stdc++.h>
using namespace std;

class BST 
{
    int data;
    BST *left , *right;

    public:
        // default constructor 
        BST();

        // parameterised constructor
        BST(int);
        
        // Insert function.
        BST* Insert(BST*, int);
    
        // preorder traversal
        void preorder(BST*);

        // Inorder traversal.
        void Inorder(BST*);

};


// Default Constructor definition.

BST ::BST()
    : data(0)
    , left(NULL)
    , right(NULL)
{
}

// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}
 


 // Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }
 
    // Insert data.
    if (value > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process left nodes.
        root->left = Insert(root->left, value);
    }
 
    // Return 'root' node, after insertion.
    return root;
}




// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
    if (root==NULL) {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}


// preorder traversal

void BST :: preorder(BST *root){

    if(root == NULL)
        return;
    cout << root->data<< endl;
    preorder(root->left);
    preorder(root->right);
}





int main(){

    BST b , *root = NULL;
    root = b.Insert(root, 1);
    b.Insert(root, 2);
    b.Insert(root, 3);
    b.Insert(root, 4);
    b.Insert(root, 5);
    b.Insert(root, 6);
    b.Insert(root, 7);
 
 cout<< "inorder traversal"<<endl;
    b.Inorder(root);
cout << "preorder traversal "<<endl;
    b.preorder(root);
    return 0;
  
}




