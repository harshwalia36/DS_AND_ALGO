 /* Q- Given a Binary Tree with all unique values and two nodes value n1 and n2.
 The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present
  in the tree or none of them is present. */

 /* If n1 and n2 are present, return pointer
   to LCA. If both are not present, return
   NULL. Else if left subtree contains any
   of them return pointer to left.*/
 Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root==NULL)
       return NULL;

       if(root->data==n1 || root->data==n2)
       return root;

       Node *l=lca(root->left,n1,n2);
       Node *r=lca(root->right,n1,n2);

       if(l!=NULL && r!=NULL)
       return root;

       return l!=NULL ?l:r;
    }
