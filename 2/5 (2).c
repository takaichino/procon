#include <stdio.h>

int main(){
  int w, d, sumw=0, sumd=0, x, y, j, k, ans;
  int hw[10], hd[10];
  scanf("%d %d", &w, &d);
  while(w!=0)
    {
      for(x=0;x<w;x++)
	{
	  scanf("%d", &hw[x]);
	  sumw = sumw + hw[x];
	}
      for(y=0;y<d;y++)
        {
          scanf("%d", &hd[y]);
	  sumd = sumd + hd[y];
        }
      for(j=0; j<w; j++)
	{
	  for(k=0; k<d; k++)
	    {
	      if(hw[j] == hd[k])
		{
		  hw[j] = 0;
		  hd[k] = 0;
		  break;
		}
	    }
	}
      if(sumw >= sumd)
	{
	  sumw = 0;
	  for(x=0;x<w;x++)
	    {
	      sumw = sumw + hw[x];
	    }
	  ans = sumw + sumd;
	}
      else
	{
          sumd = 0;
          for(y=0;y<d;y++)
            {
              sumd = sumd + hd[y];
            }
          ans = sumw + sumd;
        }
      printf("%d\n", ans);
      sumw = 0;
      sumd = 0;
      scanf("%d %d", &w, &d);
    }
  return 0;
}
      
