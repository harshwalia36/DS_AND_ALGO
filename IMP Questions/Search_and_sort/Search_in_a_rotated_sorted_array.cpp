

int binarySearch(vector<int> arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}
    int pivotIndex(vector <int> arr,int l,int h)
    {   // return the pivot index
        int mid=l+(h-l)/2;
        if(l==h)
            return l+1;
        else if(arr[l]>arr[h] && h-l==1)
            return h;
        else if(arr[mid]<arr[h])      //mid is contained
           return pivotIndex(arr,l,mid);
        else
           return  pivotIndex(arr,mid,h);    //mid is contained
    }
    int search(vector<int>& nums, int target) {
            int ind=-1;
          if(nums[0]<nums[nums.size()-1])
          {
              return binarySearch(nums,0,nums.size()-1,target);           //array is already increasing
          }
           else{
          ind=pivotIndex(nums,0,nums.size()-1);
          //cout<<"ind="<<ind<<endl;

        int left=binarySearch(nums,0,ind-1,target);                         //search in left partition
        int right=binarySearch(nums,ind,nums.size()-1,target);              //search in right partition

        if(left!=-1)
            return left;
        else if(right!=-1)
            return right;
        else
            return -1;
           }
    }
