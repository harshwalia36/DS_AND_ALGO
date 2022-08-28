static bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
    {
      return (a.second<b.second);
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector <pair<int,int>> pp;
        for(int i=0;i<n;i++)
        {
            pp.push_back(make_pair(start[i],end[i]));
        }
        
        sort(pp.begin(),pp.end(),sortbysec);
        
        int cnt=1;
        for(int i=0,j=0;i<n;i++)
        {
            if(pp[j].second<pp[i].first)
            {
                cnt++;
                j=i;
            }
            
        }
        return cnt;
    }