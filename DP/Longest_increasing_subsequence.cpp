#include<bits/stdc++.h>
#define ll long long
#define fors(i,n)  for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define LOOP(it,m) for(auto it=m.begin();it!=m.end();it++)
#define  maxe            *max_element
#define  mine            *min_element
#define init(c,a)       memset(c,a,sizeof(c))
#define mod             1000000007

using namespace std;

//------------------------------------------------
// ---------CODE HERE-----------------

ll lis(vector<ll> v)
ll lis(vector<ll> A) {
	ll n = A.size();
    vector<ll> seq;
    for(ll i = 0; i < n; i++) {
        ll ind = lower_bound(seq.begin(), seq.end(), A[i]) - seq.begin();
        if(ind == seq.size()) {
            seq.push_back(A[i]);
        } else {
            seq[ind] = A[i];
        }
    }
    return seq.size();
}

