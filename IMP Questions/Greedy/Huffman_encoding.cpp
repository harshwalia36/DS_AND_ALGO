#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	 
	 struct Node{
	     int val;
	     Node* left,*right;
	     
	     
	     Node(int x)
	     {
	         val=x;
	         left=right=NULL;
	     }
	 };
	 struct compare {

      bool operator()(Node* l, Node* r)
      
      {
      return (l->val > r->val);
      }
    };
	 
	 void preorder(vector<string> &res, Node *root,string s)
	 {
	     if(!root)
	     return;
	     
	     if(!root->left && !root->right)
	     {
	         res.push_back(s);
	       
	     }
	       preorder(res,root->left,s +"0");
	         preorder(res,root->right,s +"1");
	 }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue <Node *, vector<Node *>, compare>  pq;   //min priority queue
		    for(int i=0;i<N;i++)
		    {
		        Node *temp=new Node(f[i]);
		        pq.push(temp);
		    }
		    
		    vector <string> res;
		    
		     while(pq.size()!=1)
		    {
		        Node * a=pq.top();
		        pq.pop();
		      //  cout<<a->val<<endl;
		        Node * b=pq.top();
		      //  cout<<b->val<<endl;
		        pq.pop();
		        //a<=b
		        
		        Node * temp=new Node(a->val+b->val);
		        temp->left=a;
		        temp->right=b;
		        pq.push(temp);
		    }
		    
		    preorder(res,pq.top(),"");
		    return res;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends