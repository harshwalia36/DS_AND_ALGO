
//User function template for C++

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function

// This function returns k'th smallest element in arr[l..r] using
int kthSmallest(int arr[], int l, int r, int k) {
    // QuickSort based method.  ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT
    if(k>0 and k<=r-l+1)
    {
        int par=partition(arr,l,r);
        int len=par-l+1;    //length of pivot position from starting
        if(len==k)    //pivot is kth smallest elemnt
        return arr[par];
        else if(par>k-1)
        return kthSmallest(arr,l,par-1,k);
        else
        return kthSmallest(arr,par+1,r,k-len);
    }
    return INT_MAX;   // if k is not present in the array

}

int partition(int arr[],int l,int r)
{
    int x=arr[r] ,i=l;   //last element as pivot
    for(int j=l;j<r;j++)
    {
        if(arr[j]<=x)
        {
            swap(&arr[j],&arr[i]);
            i++;
        }
    }
    swap(&arr[r],&arr[i]);   //at last swap pivot element with ith element
    return i;
}
