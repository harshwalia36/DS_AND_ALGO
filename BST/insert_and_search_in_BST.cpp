// Insertion and search a node in bst and do a preorder traversal at a particular node.

#include<bits/stdc++.h>
#define ll long long
#define fors(i,n)  for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define LOOP(it,m) for(auto it=m.begin();it!=m.end();it++)
#define  pb              push_back
#define  mp              make_pair
#define  vll             vector<ll>
#define  pll             pair <ll,ll>
#define  umap            unordered_map
#define  uset            unordered_set
#define  lb              lower_bound
#define  ub              upper_bound
#define  maxe            *max_element        #return a pointer to max_element
#define  mine            *min_element
#define  gcd(a,b)        __gcd(a,b)
#define  lcm(a,b)        a/__gcd(a,b)*b
#define endl            "\n"
#define debug(x)        cout << " x =" << x << "\n";
#define init(c,a)       memset(c,a,sizeof(c))
#define mod             1000000007

using namespace std;

//------------------------------------------------
// ---------CODE HERE-----------------

struct Node{
	ll data;
	Node *left,*right;
	Node(ll x)
	{
		data=x;
		left=right=NULL;
	}
};
ll flag=0,q;
Node *tmp;

Node * insert(Node *root,ll data)
{
	if(root==NULL)
	{
		return new Node(data);
	}
	if(root->data>data)
	{
		root->left=insert(root->left,data);
	}
	else if(root->data<data)
	{
		root->right=insert(root->right,data);
	}
	return root;    //returning the root node
}

void preorder(Node *root)
{
	if(root==NULL)
	  return;

	if((root->data==q||flag ))
	{
	cout<<root->data<<endl;
	flag=1;
	}
	preorder(root->left);
	preorder(root->right);
}

Node * Search(Node *root,ll value)
{
  if (root == NULL || root->data == value)
       return root;
	if(root->data>value)
	{
		return Search(root->left,value);
	}
	else if(root->data<value)
	{
		return Search(root->right,value);
	}

}
int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 ll n,a;
 Node *root=NULL;
 cin>>n;
 loop(i,0,n)
 {
  cin>>a;
  root=insert(root,a);
 }

cin>>q;
tmp=Search(root,q);
preorder(tmp);
}






