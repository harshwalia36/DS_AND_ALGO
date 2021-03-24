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
    Node *next,*prev;
    Node(int x){
        data=x;
        next=NULL;
        prev=NULL:
    }
};

int countPairs(Node *first,Node *last,int sum)
{
    int cnt=0;
    while(first!=last && first!=NULL && last!=NULL && first!=last->next)
    {
        if((first->data + last->data)==sum)
            {cnt++;
              first=first->next;
              last=last->prev;
            }
        else if((first->data + last->data)<sum)
            first=first->next;
        else
            last=last->prev;
    }
    return cnt;
}

int countTriplets(Node *head,int x)
{
    Node *cur=head,*first,*last;
    int cnt=0;
    last=head;
    while(last->next!=NULL)
        last=last->next;

    while(cur!=NULL)
    {
        first=curr->next;
        cnt+=countPairs(first,last,x-curr->data);
    }
    return cnt;
}

Node *insert(Node **head,int data)
{
      Node *temp=new Node(data);

      if(*head==NULL)
        *head=temp;
      else{                    //insert at beggining
           *head->prev=temp;
           temp->next=*head;
           *head=temp;
       }
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *head=NULL;

    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);

     int x = 17;

    cout << "Count = "
         << countTriplets(head, x);
    return 0;


}





