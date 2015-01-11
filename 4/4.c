#include<stdio.h>

int main()
{
  int fi[1001];
  int b1 = 1, b2 = 1, now;
  int k;
  int V, d;
  int j, last = -1;
  int ans = 1;
  int i=0;
  while(scanf("%d %d", &V, &d) != EOF)
    {
      for(i=0; i<1001; i++)
	{
	  fi[i] = 0;
	}
      for(k=0; k<V; k++)
	{
	  now = (b1 + b2) % 1001;
	  fi[now] = 1;
	  b2 = b1;
	  b1 = now;
	}
      for(j=0; j<=1000; j++)
	{
	  if(fi[j]==1)
	    {
	      if(last >= 0 && j - last >= d)
		{
		  ans++;
		  last = j;
		}
	      else
		{
		  last = j;
		}
	    }
	}
      printf("%d\n", ans);
      b1 = 1;
      b2 = 1;
      last = -1;
      ans = 1;
    }
  return 0;
}
