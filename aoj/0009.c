#include <stdio.h>
#include <math.h>

int main(){
  int n;
  int k, l, mod=0, ans=0, era;
  int a[256] ={}, a_ho = 0;
  while(scanf("%d", &n)!=EOF)
    {
      for(k=2; k<=n; k++)
	{
	  era = sqrt(k);
	  if(era==1) 
	    {
	      ans++;
	      a[a_ho] = k;
	      a_ho++;
	    }
	  else
	    {
	      for(l=0; a[l]<=era; l++)
		{
		  if(k % a[l] ==0)
		    {
		      mod++;
		      break;
		    }
		}
	      if(mod==0)
		{
		  ans++;
		  if(a_ho < 256)
		    {
		      a[a_ho] = k;
		      a_ho++;
		    }
		}
	      mod = 0;
	    }
	}
      printf("%d\n", ans);
      ans = 0;
      a_ho = 0;
    }
  return 0;
}
