// return the smallest window in S with all the characters of P
// if no such window exists, return "-1"
string smallestWindow (string S, string P){


    int cntt[256]={0};
    for(int i=0;i<P.size();i++)
    {
        cntt[P[i]]++;
    }
    int n=P.size();   //all char. of another string P

    int start = 0, start_index = -1, min_len = INT_MAX;

    int cnt = 0;
    int curr_count[256] = { 0 };

    for(int j=0;j<S.length();j++)
    {
       curr_count[S[j]]++;

        // If any  character matched,  with count of a char. inn another string
        // then increment count
        if (curr_count[S[j]] == cntt[S[j]] )
            cnt+=cntt[S[j]];

        if(cnt==n)
        {
            while(curr_count[S[start]]>cntt[S[start]])
            {
                 curr_count[S[start]]--;
                 start++;
            }

            // Update window size
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
                // cout<<S.substr(start_index, min_len)<<endl;
            }
        }


        }
        if(cnt<n)
        return "-1";
        else
        return S.substr(start_index, min_len);
}
