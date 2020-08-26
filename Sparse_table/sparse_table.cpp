

ll **sp_min,**sp_max,**it; ll n,P;
int *log2arr;

ll minQuery(ll l, ll r)
{
	int len=r-l+1;
	ll p=log2arr[len];
	ll k=pow(2,p);
	ll left=sp_min[p][l];
	ll right=sp_min[p][r-k+1];
	return min(left,right);
}

ll maxQuery(ll l, ll r)
{
	int len=r-l+1;
	ll p=log2arr[len];
	ll k=pow(2,p);
	ll left=sp_max[p][l];
	ll right=sp_max[p][r-k+1];
	return max(left,right);
}

ll maxIndexQuery(ll l,ll r)
{
	ll len=r-l+1;
	ll p=log2arr[len];
	ll k=pow(2,p);
	ll left=sp_max[p][l];
	ll right=sp_max[p][r-k+1];
	if(left>right)
	return it[p][l];

	return it[p][r-k+1];

}

void buildMinSparseTree(ll values[])
{
   P=log(n)/log(2);
  sp_min=new ll*[P+1];
//   it=new ll*[P+1];
  fors(i,P+1)
  {
  	sp_min[i]=new ll[n];
//   	it[i]=new ll[n];

  }
   log2arr=new int[n+1];
	loop(i,2,n+1)
	{
		log2arr[i]=log2arr[i/2]+1;
	}

	fors(i,n)
	{
		sp_min[0][i]=values[i];
// 		it[0][i]=i;
	}

	loop(p,1,P+1)
	{
		for(ll j=0;j+(1<<p)<=n;j++)
		{  ll left,right;
		   left=sp_min[p-1][j];
		   right=sp_min[p-1][j+(1<<(p-1))];
		   sp_min[p][j]=min(left,right);

		  // if(left<right)
		  // it[p][j]=it[p-1][j];           //storing index of min element
		  // else
		  // it[p][j]=it[p-1][j+(1<<(p-1))];
		}
	}
}

void buildMaxSparseTree(ll values[])
{
   P=log(n)/log(2);
  sp_max=new ll*[P+1];
  it=new ll*[P+1];
  fors(i,P+1)
  {
  	sp_max[i]=new ll[n];
  	it[i]=new ll[n];

  }
   log2arr=new int[n+1];
	loop(i,2,n+1)
	{
		log2arr[i]=log2arr[i/2]+1;
	}

	fors(i,n)
	{
		sp_max[0][i]=values[i];
		it[0][i]=i;
	}

	loop(p,1,P+1)
	{
		for(ll j=0;j+(1<<p)<=n;j++)
		{  ll left,right;
		   left=sp_max[p-1][j];
		   right=sp_max[p-1][j+(1<<(p-1))];
		   sp_max[p][j]=max(left,right);

		   if(left>right)
		   it[p][j]=it[p-1][j];           //storing index of max element
		   else
		   it[p][j]=it[p-1][j+(1<<(p-1))];
		}
	}
}

