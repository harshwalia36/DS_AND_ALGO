int next(int arr[], int target, int end)
{
      // Minimum size of the array should be 1
      if(end == 0) return -1;
    // If target lies beyond the max element, than the index of strictly smaller
      // value than target should be (end - 1)
      if (target > arr[end - 1]) return end-1;
   
    int start = 0;
 
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
 
        // Move to the left side if the target is smaller
        if (arr[mid] >= target)
        {
            end = mid - 1;
        }
        // Move right side
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}