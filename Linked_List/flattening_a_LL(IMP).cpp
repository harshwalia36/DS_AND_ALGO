
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;

	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}

};
*/

/*  Function which returns the  root of
    the flattened linked list. */

Node *merge(Node *first,Node *sec)
{
   if(first==NULL)
   return sec;
   else if(sec==NULL)
   return first;

   Node *result;
   if(first->data>=sec->data)
   {
       result=sec;
       result->bottom=merge(first,sec->bottom);
   }
   else
   {
       result=first;
       result->bottom=merge(first->bottom,sec);
   }
   result->next=NULL;
   return result;
}

Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL)
   return root;

   return merge(root,flatten(root->next));
}
