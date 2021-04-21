class Solution {
public:
    TreeNode * minValueNode(TreeNode * root)
    {
        TreeNode * curr=root;
        while(curr!=NULL && curr->left!=NULL)
        {
            curr=curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root==NULL)
           return NULL;

        if(key<root->val)
         root->left=deleteNode(root->left,key);

        else if(key>root->val)
            root->right=deleteNode(root->right,key);

        else  //(key==root->data)
        {
            if(root->left==NULL && root->right==NULL)
            {
                return  NULL;
            }
            else if(root->left==NULL)
            {
               TreeNode* temp = root->right;
               delete root;
               return temp;
            }
            else if(root->right==NULL)
            {
                TreeNode* temp = root->left;
                 delete root;
                return temp;
            }
             // node with two children: Get the inorder successor
             // (smallest in the right subtree)
             TreeNode * temp=minValueNode(root->right);

            // Copy the inorder successor's content to this node
              root->val = temp->val;

           // Delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};
