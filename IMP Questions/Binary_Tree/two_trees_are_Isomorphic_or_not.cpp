  /* We simultaneously traverse both trees. Let the current internal nodes of two trees being traversed be n1 and n2 respectively. There are following two conditions for subtrees rooted with n1 and n2 to be isomorphic.
1) Data of n1 and n2 is same.
2) One of the following two is true for children of n1 and n2
       a) Left child of n1 is isomorphic to left child of n2 and right child of n1 is isomorphic to right child of n2.
       b) Left child of n1 is isomorphic to right child of n2 and right child of n1 is isomorphic to left child of n2.*/
  bool isIsomorphic(Node *r1,Node *r2)
    {
      if(r1==NULL && r2==NULL)
      return true;

      if(r1==NULL || r2==NULL)
       return false;

       return (r1->data==r2->data && ((isIsomorphic(r1->left,r2->left)&& isIsomorphic(r1->left,r2->left))||(isIsomorphic(r1->left,r2->right)&& isIsomorphic(r1->right,r2->left))));



    }
