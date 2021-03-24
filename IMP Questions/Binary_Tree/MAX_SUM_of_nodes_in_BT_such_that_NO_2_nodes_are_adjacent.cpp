// GFG 2 solution both are imp.
//Return a pair for each node in the binary tree such that the first of the pair indicates maximum sum
//when the data of a node is included and the second indicates maximum sum when the data of a particular node is not included.
#include<bits/stdc++.h>
#define ll long long
#define fors(i,n)  for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define rloop(i,x,n) for(int i=x;i>=0;i--)
#define LOOP(it,m) for(auto it=m.begin();it!=m.end();it++)
#define  pb              push_back
#define  mp              make_pair
#define  vll             vector<ll>
#define  pll             pair <ll,ll>
#define  umap            unordered_map
#define  uset            unordered_set
#define  lb              lower_bound
#define  ub              upper_bound
#define  maxe            *max_element
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

class Node
{
public:
    int data;
    Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

pair<int,int> maxSumHelper(Node *root)
{
    if(root==NULL)
    {
        pair <int,int> sum(0,0);
        return sum;
    }
    pair<int,int> sum1=maxSumHelper(root->left);
    pair<int,int> sum2=maxSumHelper(root->right);
    pair<int,int> sum;

    //Node is included (left and right children are not included)
    sum.first=root->data+sum1.second+sum2.second;
    // This node is excluded (Either left or right
    // child is included)
    sum.second=max(sum1.first,sum1.second)+max(sum2.first,sum2.second);

    return sum;
}
int maxSum(Node *root)
{
    pair <int,int> p=maxSumHelper(root);
    return max(p.first,p.second);
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

    Node *root= new Node(10);
    root->left= new Node(1);
    root->left->left= new Node(2);
    root->left->left->left= new Node(1);
    root->left->right= new Node(3);
    root->left->right->left= new Node(4);
    root->left->right->right= new Node(5);
    cout << maxSum(root);
    return 0;


}




