	int minSwaps(vector<int>&nums){
	    int n=nums.size();
	    unordered_map <int,int> um;
	    vector <int> v(n);
	    for(int i=0;i<n;i++)
	    {
	        um[nums[i]]=i;
	        v[i]=nums[i];
	    }
	    sort(v.begin(),v.end());
	    //compare nums with sorted nums
	    int swp=0;
	    for(int i=0;i<n;i++)
	    {
	        if(v[i]!=nums[i])
	        {
	            swp++;
	            um[nums[i]]=um[v[i]];  //bcz after swap index of nums[i] changed
	             swap(nums[i],nums[um[v[i]]]);

	        }
	    }
	    return swp;
	}
