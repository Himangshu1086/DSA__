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
        
        // search function
        BST* Search(BST* , int);

        // Insert function.
        BST* Insert(BST*, int);
    
        //delete function
        BST* Delete(BST* , int);

        // preorder traversal
        void preorder(BST*);

        // Inorder traversal.
        void Inorder(BST*);

        //postOrder traversal
        void postOrder(BST*);

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

//Search function

BST* BST :: Search(BST* root , int key)
{
    if(root ==NULL )
        return NULL;
    if ( key == root->data)
        return root;
    if (key < root->data)
        return Search(  root->left , key );
    return Search(  root->right , key );
}



// Delete a node from the BST

BST* BST :: Delete(BST* root  , int key)
{
    
}



// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
    if (root==NULL) {
        return;
    }
    Inorder(root->left);
    cout << root->data <<"  ";
    Inorder(root->right);
}


// preorder traversal

void BST :: preorder(BST *root){

    if(root == NULL)
        return;
    cout << root->data<< "  ";
    preorder(root->left);
    preorder(root->right);
}

// postOrder traversal 

void BST :: postOrder(BST* root)
{
    if(root == NULL)
        return;
    preorder(root->left);
    preorder(root->right);
    cout << root->data<< "  ";
    
}


int main()
{

    BST b , *root = NULL;
    root = b.Insert(root, 6);
    b.Insert(root, 2);
    b.Insert(root, 4);
    b.Insert(root, 5);
    b.Insert(root, 3);
    b.Insert(root, 1);
    b.Insert(root, 7);
 
 cout << "inorder traversal"<< " :   ";
    b.Inorder(root);
cout <<endl<< "preorder traversal "<< " :   ";
    b.preorder(root);
    cout << endl;
    if(b.Search(root , 8)==NULL)
        cout << "key is not present"<< endl;
    else
        cout << "key is present " << endl;
    return 0;
  
}




