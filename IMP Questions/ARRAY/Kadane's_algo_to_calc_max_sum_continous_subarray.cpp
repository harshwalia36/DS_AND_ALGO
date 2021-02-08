//Explanation:
// Simple idea of the Kadane’s algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this).
// And keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this).
//Each time we get a positive sum compare it with max_so_far and update max_so_far if it is greater than max_so_far

/* Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
            max_ending_here = 0
return max_so_far

*/

int maxSubarraySum(int arr[], int n){
    int max_ending_here=0,max_sum_so_far=0;

    for(int i=0;i<n;i++)
    {
        max_ending_here=max_ending_here+arr[i];
        if(max_ending_here<0)
        max_ending_here=0;
        if(max_sum_so_far<max_ending_here)
        max_sum_so_far=max_ending_here;
    }
    if(max_sum_so_far==0)
    return *max_element(arr,arr+n);     // if all numbers are negative
    else
    return max_sum_so_far;


}
