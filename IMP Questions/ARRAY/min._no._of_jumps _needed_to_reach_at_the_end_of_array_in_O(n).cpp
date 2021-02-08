// Function to return minimum number of jumps to end of array
int minJumps(int a[], int n){

    int jump,maxR,step;
    maxR=a[0];
    step=a[0];
    jump=1;

    if (n <= 1)
        return 0;

    // Return -1 if not possible to jump
    if (a[0] == 0)
        return -1;

    for(int i=1;i<n;i++)
    {
        if(i==n-1)
        return jump;

        maxR=max(maxR,a[i]+i);

        step--;
        if(step==0)
        {
            jump++;
            if(i>=maxR)
            return -1;
            step=maxR-i;
        }
    }
    return -1;
}
