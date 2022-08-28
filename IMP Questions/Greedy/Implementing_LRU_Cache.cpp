
#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
     vector <int> v;
     int faults=0;
     vector <int>::iterator it;
     
     for(int i=0;i<N;i++)
     {
         it=find(v.begin(),v.end(),pages[i]);
         if(it==v.end())            // If item is not present there is a Page Fault
         {
             if(v.size()==C)
             v.erase(v.begin());      //erase the first element in the capacity bag if capacity is full
             v.push_back(pages[i]);   //push the new element in the last
             faults++;                 //increase the no. of faults
         }
         else{
          v.erase(it);                //if item s already present erase it fro its position
          v.push_back(pages[i]);     // and push it in back bcz its comes at last
         }
     }
     return faults;
    }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
} 