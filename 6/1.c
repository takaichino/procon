#include <stdio.h>

int main(){
  int n, r, p, c;
  int k, i, l, m, j;
  int card[50], sto[50];
  scanf("%d %d", &n, &r);
  while(n!=0 || r!=0)
    {
      for(i=0;i<n;i++)
	{
	  card[i] = n-i;
	}
      for(k=0;k<r;k++)
	{
	  scanf("%d %d", &p, &c);
	  if(p>0)
	    {
	      for(l=0;l<p-1;l++)
		{
		  sto[l] = card[l];
		}
	    }
	  for(m=0;m<c;m++)
	    {
	      card[m] = card[p-1+m];
	    }
	  for(j=0;j<p-1;j++)
	    {
	      card[c+j] = sto[j];
	    }
	}
      printf("%d\n", card[0]);
      scanf("%d %d", &n, &r);
    }
  return 0;
}
