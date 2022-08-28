#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

class Stack{
   int top;

   public:
   int a[MAX];
   Stack()
   {
       top=-1;
   }
   bool push(int x)
   {
       if(top>=MAX-1)
       {
           cout<<"Stack overflow"<<endl;
           return false;
       }
       else{
           cout<<x<<" is pushed into stack\n";
           a[++top]=x;
           return true;
       }
       
   }
   void pop()
   {
       if(top==-1)
       {
           cout<<"Stack is already empty\n";
       }
       else{
           cout<<a[top]<<" is popped from stack";
           top--;
       }
   }
   int peek()
   {
       if(top==-1)
       {
           cout<<"Stack is already empty\n";
       }
       else{
           return a[top];
       }
       return 0;
   }
   bool isEmpty()
   {
      if(top==-1)
      return true;
      else
      return false;
   }
};

int main()
{
  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);

  s.pop();
  cout<<s.peek()<<endl;
  cout<<s.isEmpty()<<endl;

}