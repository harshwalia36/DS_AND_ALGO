#include<bits/stdc++.h>
#define ll long long
using namespace std;

// mark all 0s with -y and mark all 1s with x, now the problem is just no of subarrays having sum 0


int helper(ll x, ll y, vector<ll>&arr)
{
    ll sum = 0;
    map<ll,ll> mp;
    mp[0]++;
    ll ans = 0;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] == 0)
            sum += (-y);
        else
            sum += (x);
        if(mp.count(sum))
            ans += mp[sum];
        mp[sum]++;
    }
    return ans;
}
int main()
{
    
    ll n;
    cin>>n;
    vector<ll> arr(n);

    for(auto &i:arr)
    cin>>i;
    
  ll x,y;
  cin>>x>>y; 

  cout<<helper(x,y,arr)<<endl;
}