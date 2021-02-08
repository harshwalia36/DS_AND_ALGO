
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


ll _mergeSort(ll arr[], ll temp[],
                 ll left, ll right);
ll merge(ll arr[], ll temp[], ll left,
                   ll mid, ll right);


ll inversionCount(ll arr[],ll array_size)
{
    ll temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}


ll _mergeSort(ll arr[], ll temp[],
                 ll left, ll right)
{
    ll mid, inv_count = 0;
    if (right > left) {

        mid = (right + left) / 2;


        inv_count += _mergeSort(arr, temp,
                                left, mid);
        inv_count += _mergeSort(arr, temp,
                             mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left,
                           mid + 1, right);
    }
    return inv_count;
}

ll merge(ll arr[], ll temp[], ll left,
          ll mid, ll right)
{
    ll i, j, k;
    ll inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }


    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];


    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   ll n;
   cin>>n;
   ll arr[n];
   fors(i,n)
   {
     cin>>arr[i];
   }
   cout<<inversionCount(arr,n);
}




