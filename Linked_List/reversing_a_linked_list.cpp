
#include<bits/stdc++.h>
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

//------------------------------------------------
// ---------CODE HERE-----------------
struct Node{
    int data;
    Node * next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

struct LinkedList {
    Node *head;   //accessible to all member function
    LinkedList(){head=NULL;}

    void reverse()
    {
       Node* curr,*next,*prev;
       curr=head;prev=NULL;next=NULL;
       while(curr!=NULL)
       {
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
       }
       head=prev;
    }
    void print_list()
    {
    Node *curr=head;
     if(curr==NULL)
        printf("empty list");
    else{
     while(curr!=NULL)
     {
        cout<<curr->data<<"->";
        curr=curr->next;
     }
     cout<<endl;
    }
    }
    void push(int data)         //inserting in the begining
    {
        Node *temp=new Node(data);
        temp->next=head;
        head=temp;
    }
};



int main()
{
  ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

   /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list\n";
    ll.print_list();

    ll.reverse();

    cout << "\nReversed Linked list \n";
    ll.print_list();
    return 0;
}




