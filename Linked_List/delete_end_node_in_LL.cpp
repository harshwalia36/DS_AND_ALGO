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

//------------------------------------------------
// ---------CODE HERE-----------------

struct Node{
    int data;
    Node * next;
};

Node * delete_end_node(Node* head)
{
    Node * curr=head;
    if(curr==NULL)
        cout<<"Empty List\n;";
    else{
        while(curr->next->next!=NULL)
        {
            curr=curr->next;
        }
        delete curr->next;
        curr->next=NULL;
    }

}
void print_list(Node* head)
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

int main()
{
  ios_base::sync_with_stdio(false);

    Node *head=new Node();
  head->data=1;
  head->next=new Node();
  head->next->data=2;
  head->next->next=new Node();
  head->next->next->data=3;
  head->next->next->next=NULL;
  print_list(head);

  delete_end_node(head);
  print_list(head);

}





