#include<bits/stdc++.h>

using namespace std;

int solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    set<int> required;
    while(k--)
    {
        int a;
        cin>>a;
        required.insert(a);
    }
    cin>>k;
    while(k--)
    {
        int a;
        cin>>a;
        required.erase(a);
    }
    vector<int> skills(m),cost(m);
    for(auto &i:cost)
        cin>>i;
    
    // skills[i] - denotes skills we can acquire from ith book
    map<int,int> index;    // index of all skills which you required

    int curr=0;
    for(auto x:required)
        index[x]=curr++;

    for(auto &i:skills)
    {
        cin>>k;
        while(k--)
        {
            int a;
            cin>>a;
            if(index.count(a))
                i|=(1<<index[a]);       // mark that curr skill is present in book
        }
    }

    n=1<<index.size();   // all skills required + 1

    vector<int> best(n,1e9);        //
    best[0]=0;

    // O(2^15 * m)
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            best[i|skills[j]]=min(best[i|skills[j]],best[i]+cost[j]); // gain (i|skills[j]) from jth book
        }
    }
    
    if(best.back()==1e9)
    return -1;

    return best.back();
    

}
int main()
{
    cout<<solve();
}