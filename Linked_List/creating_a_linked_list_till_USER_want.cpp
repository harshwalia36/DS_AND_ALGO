
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
//priority_queue<pi, vector<pi>, greater<pi> > pq;

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* linked_list()
{
    char ch;
    Node* head=new Node();
    Node* cur=head;
    int val;
    do{
        cout<<"Enter the data:"<<endl;
        cin>>val;
        cur->data=val;
        cur->next=NULL;
        cout<<"do u want to enter more(y/n):"<<endl;
        cin>>ch;
        if(ch=='y'||ch=='Y')
        {
         cur->next=new Node();      //creating new node
         cur=cur->next;
        }
    }
    while(ch=='y'||ch=='Y');

    return head;
}

void print_list(Node* head)
{
    Node *cur=head;
    while(cur!=NULL)
    {
        cout<<cur->data<<"->";
        cur=cur->next;
    }
}

//------------------------------------------------
// ---------CODE HERE-----------------

int main()
{
 // ios_base::sync_with_stdio(false);
   // cin.tie(NULL);

   Node* ptr=linked_list();
   print_list(ptr);
   delete ptr;

}




