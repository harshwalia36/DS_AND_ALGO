    int height(struct Node* node){
        Node * curr;
        if(node==NULL)
        return 0;
        int lheight=height(node->left)+1;
        int rheight=height(node->right)+1;
        return max(lheight,rheight);
    }

    int diameter(Node* root) {
     if(root==NULL)
     return 0;

     int leftsubtree=height(root->left);
     int rightsubtree=height(root->right);

     int Ldiam=diameter(root->left);
     int Rdiam=diameter(root->right);

     int fd=max(leftsubtree+rightsubtree+1,max(Ldiam,Rdiam));

     return fd;
    }
