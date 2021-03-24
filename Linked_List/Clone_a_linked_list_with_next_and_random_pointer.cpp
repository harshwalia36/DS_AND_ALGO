Node *copyList(Node *head) {
     Node *curr,*ptr,*iter=head;
     curr=head;
     //creating dummy nodes
     while(curr!=NULL)
     {  ptr=new Node(curr->data);
         ptr->next=curr->next;
         curr->next=ptr;
         curr=ptr->next;
     }

     //make dummy nodes point to random pointers
     while(iter!=NULL)
     {
         if(iter->arb!=NULL)
         iter->next->arb=iter->arb->next;
         else
         iter->next->arb=NULL;
         iter=iter->next->next;
     }
     //next pointers
     Node *dhead=head->next,*sec;
     iter=head;
     while(iter!=NULL)
     {
       sec=iter->next->next;
       if(sec!=NULL)
       iter->next->next=sec->next;
       else
       iter->next->next=NULL;
       iter->next=sec;
       iter=sec;
     }
     return dhead;

}
