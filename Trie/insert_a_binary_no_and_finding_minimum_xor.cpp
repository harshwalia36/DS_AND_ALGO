
struct Trienode{
    Trienode *left, *right;
};
Trienode *root;
ll overall_xor=0;

ll get_minimum_xor_with(int x)
{
    Trienode *curr=root;
    ll curr_xor=0;
    for(int i=31;i>=0;i--)
    {
        int bit=(x>>i)&1;
        if(bit==0)
        {
            if(curr->left)
             {
                 curr=curr->left;
             }
             else{
                 curr=curr->right;
                 curr_xor+=pow(2,i);   // 1*pow(2,i);
             }
        }
        else{
            if(curr->right)
             {
                 curr=curr->right;
             }
             else{
                 curr=curr->left;
                 curr_xor+=pow(2,i);
             }
        }
    }
    return curr_xor;
}

void insert(int val)
{
    Trienode *curr=root;
    for(int i=31;i>=0;i--)
    {
       int bit=(val>>i)&1;
       if(bit==0)
       {   if(!curr->left)
             curr->left=new Trienode();
         curr=curr->left;
       }
       else{
           if(!curr->right)
             curr->right=new Trienode();
           curr=curr->right;
       }
    }
}
