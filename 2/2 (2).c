#include <stdio.h>

int main()
{
  int n, i, j, k, X, ans=0, x[256];
  scanf("%d", &n);
  while(n != 0)
    {
      for(i=0; i<n; i++)
	{
	  scanf("%d", &x[i]);
	}
      for(j=0; j<n-1; j++)
	{
	  X = x[0];
	  for(k=0; k<n-j-1; k++)
	    {
	      if(X > x[k+1])
		{
		  x[k] = x[k+1];
		  x[k+1] = X;
		  ans++;
		}
	      else
		{
		  X = x[k+1];
		}
	    }
	}
      printf("%d\n", ans);
      ans=0;
      scanf("%d", &n);
    }
  return 0;
}
