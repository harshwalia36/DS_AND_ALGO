#include<bits/stdc++.h>
using namespace std;

class StackNode{

    public:
    int data;
    StackNode * next;

    StackNode()
    {next=NULL;}
};


StackNode* newNode(int data)
{
    StackNode * temp=new StackNode();
    temp->data=data;
    temp->next=NULL;
    return temp;
}
int isEmpty(StackNode* root)
{
    return !root;
}
void push(StackNode **top,int data)
{
    StackNode *temp=newNode(data);
    temp->next=*top;
    *top=temp;
    cout<<temp->data<<" is pushed into the stack\n";
}
void pop(StackNode **top)
{
    if (isEmpty(*top))
        cout<<"stack is already empty\n";
    else{
    StackNode *temp=*top;
    cout<<"popped element is "<<temp->data<<endl;
    *top=(*top)->next;
    free(temp);
    }
}
int peek(StackNode *top)
{
   if (isEmpty(top))
        cout<<"stack is already empty\n";

        return (top->data);
}



int main()
{
  StackNode *top=NULL;
  push(&top,1);
  push(&top,2);
  push(&top,3);
  push(&top,4);
  push(&top,5);

  while(!isEmpty(top))
    {
        // print top element in stack
        cout<<peek(top)<<" \n";
        // remove top element in stack
        pop(&top);
    }
    
}