// The good and widely used way to define the hash of a string s of length n is
//  hash(s)=s[0]+s[1].p+s[2].p^2+...+s[n−1]⋅p^n−1 mod m

//  https://cp-algorithms.com/string/string-hashing.html

#include<bits/stdc++.h>
#define ll long long
#define fors(i,n)  for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)

using namespace std;


long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

// Precomputing the powers of p might give a performance boost.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    string s;
    fors(i,n)
    {
        cin>>s;
        cout<<"hash value of :"<<s<<" "<<compute_hash(s)<<endl;
    }
}
