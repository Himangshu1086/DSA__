# tree 
                1
              /   \
            /       \ 
          /           \
        2               3
      /  \            /   \
     /    \          /     \
    4      5       6         7




# preorder traversal

` root -> left_tree ->  right_tree  `


` code =>`

    void preorder (Node* root)  {

        if( root == NULL)
                return;
        cout << root->data;
        preorder(root->left);
        preorder(root->rigth);

    }

    output =   1 2 4 5 3 6 7 



# Inorder Traversal

` left tree  -> root  -> right tree`

            
**code**

    void inorder ( Node* root){

      if(!root)
        return;
      inorder(root->left);
      cout << root->data ;
      inorder(root->right);
    }

    output =  4 2 5 1 6 3 7




# Post Order Traversal

`right tree -> left tree -> root `



* code


      void postorder(Node * root){

      if(!root)
        return;
      inorder(root->right);
      inorder(root->left);
      cout << root->data ;
      
      } 

      output = 4 5 2 6 7 3 1



