#include <stdio.h>

int main(){
  int x[5], k, y;
  scanf("%d %d %d %d %d", &x[0], &x[1], &x[2], &x[3], &x[4]);
  for(k=1,k>=0,k--)
    {
      y = x[2k];
      if(x[2k] < x[2k+1])
	{
	  x[2k] = x[2k+1];
	  x[2k+1] = y;
	  y = x[2k];
	}
      if(x[k] < y)
	{
	  x[2k] = x[k];
          x[k] = y;
	}
    }
  for(k=4;k>=0;k--)
    {
      
