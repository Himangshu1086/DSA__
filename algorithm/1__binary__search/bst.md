-author : Himangshu baishya 
# BINARY SEARCH TREE
<br>

- **inorder traversal of BST is always  sorted**


<br>
<br>

## Search()  ==>  O(log N)
<br>

           - Compare x with the middle element.
           - If x matches with the middle element, we return the mid index.
           - Else If x is greater than the mid element, then x can only lie in the right half subarray after the mid element. So we recur for the right half.
           - Else (x is smaller) recur for the left half.

code :

      search  ( Node *root , int key)
      {
          if(root ==NULL )
              return NULL;

          if ( key == root->data)
              return root;

          if (key < root->data)
              return Search(  root->left , key );

          return Search(  root->right , key );
      }

<br>
<br>

## Insert()   ===> O(log N)

<br>

        insert( Node*  root , value )
        { 
            if( root == NULL)
              return  new Node( value ); 
            if( value < root->data  )
              root->left = insert ( root->left , value ) ;
            else
              root->right = insert  ( root->right , value);
            
            
        }
        
<br>
<br>

        insert( root , 6 );
        insert( root , 2 );
        insert( root , 4 );
        insert( root , 5 );
        insert( root , 3 );
        insert( root , 1 );
        insert( root , 7 );

                          6
                        /   \
                       2     7
                      / \
                     1   4
                        / \
                       3   5
                      
        inorder : 1 2 3 4 5 6 7
        preorder : 6 2 1 4 3 5 7


<br><br><br>






## delete()   ===> O( log N)
<br>
<br>

    case-1 : delete a leaf node
    case-2 : delete node with one children
    case-3 : delete node with two children
    ==> soln == find the min in right-subtree , copy the value in targeted node , delete duplicate from right-subtree

code

      Delete  ( Node* root , int key)
      {
        //find the data 
          if( root==NULL)
            return ;
          else if( key < root->data)
              root->left = Delete ( root->left , key);
          else if(key > root->data)
              root->right = Delete ( root->right , key);
          else      //get the key , ready to delete the node
            {
                  // case-1:No Child 
                  if( root->left == NULL &&  root->right ==NULL)
                      {
                        delete root;
                        root = NULL;
                      }

                  // case-2 : One Child

                  else if (root->left == NULL)
                  {
                      Node* temp = root;
                      root = root->right;
                      delete temp;
                  }
                  else if (root->right == NULL)
                  {
                      Node* temp = root;
                      root = root->left;
                      delete temp;
                  }


                  // case-3 : 2 Child

                  else
                  {
                      Node* temp = FindMin(root->right);
                      root->data = temp->data;
                      root->right = Delete( root->right , temp->data);
                  }
            }
            return root;
      }



<br><br>



<br><br>
### tree taken :=>

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

            
`code`

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



